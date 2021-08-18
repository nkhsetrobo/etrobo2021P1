/******************************************************************************
 *  app.cpp (for LEGO Mindstorms EV3)
 *  Created on: 2015/01/25
 *  Implementation of the Task main_task
 *  Author: Kazuhiro.Kawachi
 *  Copyright (c) 2015 Embedded Technology Software Design Robot Contest
 *****************************************************************************/

#include "app.h"
#include "RandomWalker.h"
#include "ColorMeasure.h"
#include "Main_Measure.h"
#include "Main_Judge.h"
#include "VirtualPointer.h"
#include "Bright_Judge.h"
#include "Distance_Judge.h"
#include "Turn_Judge.h"
#include "Bright.h"
#include "Turn.h"
#include "Odometer.h"
#include "VirtualStraight.h"
#include "Arm.h"
#include "ArmControl.h"
#include "Sonar.h"
#include "SonarMeasure.h"
#include "SonarSensor.h"
#include "Tail.h"
#include "TailControl.h"

// デストラクタ問題の回避
// https://github.com/ETrobocon/etroboEV3/wiki/problem_and_coping
void *__dso_handle=0;

//using宣言
/*using ev3api::ColorSensor;
using ev3api::TouchSensor;
using ev3api::Motor;
using ev3api::Clock;
using ev3api::SonarSensor;
*/
using namespace ev3api;

// Device objects
// オブジェクトを静的に確保する
ColorSensor gColorSensor(PORT_2);
TouchSensor gTouchSensor(PORT_1);
SonarSensor gSonarSensor(PORT_3);
Motor       gMotor_Arm(PORT_A);
Motor       gLeftWheel(PORT_C);
Motor       gRightWheel(PORT_B);
Motor       gMotor_Tail(PORT_D,true,MEDIUM_MOTOR);
Clock       gClock;

// オブジェクトの定義
Drive           *gDrive;
static ColorMeasure    *gColorMeasure;
static Sonar           *gSonar;
static SonarMeasure    *gSonarMeasure;
Walker          *gWalker;
static Starter         *gStarter;
static SimpleTimer     *gScenarioTimer;
static SimpleTimer     *gWalkerTimer;
LineTracer      *gLineTracer;
static ArmControl *gArmControl;
static TailControl *gTailControl;
VirtualCurve    *gVirtualCurve;
VirtualStraight *gVirtualStraight;
static Scenario        *gScenario;
static ScenarioTracer  *gScenarioTracer;
static RandomWalker    *gRandomWalker;
static MotorControl    *gMotorControl;
static Main_Measure    *gMain_Measure;
static Xpointer        *gXpointer;
static Ypointer        *gYpointer;
Odometer        *gOdometer;
Turn            *gTurn;
static Speedmeter      *gSpeedmeter;
Bright_Judge    *gBright_Judge;
Distance_Judge  *gDistance_Judge;
Turn_Judge      *gTurn_Judge;
static Taikei   *gTaikei;
static Arm       *gArm;
static Tail      *gTail;
static Main_Judge      *gMain_Judge;
Bright          *gBright;
static VirtualPointer  *gVirtualPointer;
// scene object
static Scene gScenes[] = {
    { TURN_LEFT,   1250 * 1000, 0 },  // 左旋回1.25秒
    { GO_STRAIGHT, 5000 * 1000, 0 },  // 直進5秒
    { TURN_LEFT,   1250 * 1000, 0 },  // 左旋回1.25秒
    { GO_STRAIGHT, 2500 * 1000, 0 }   // 直進2.5秒
};

/**
 * EV3システム生成
 */
static void user_system_create() {
    // [TODO] タッチセンサの初期化に2msのdelayがあるため、ここで待つ
    tslp_tsk(2U * 1000U);

    // オブジェクトの作成
    gStarter         = new Starter(gTouchSensor);
    gScenarioTimer   = new SimpleTimer(gClock);
    gWalkerTimer     = new SimpleTimer(gClock);
    gMotorControl    = new MotorControl(gLeftWheel,gRightWheel,gMotor_Arm,gMotor_Tail);
    gTaikei          = new Taikei();
    gDrive           = new Drive(gMotorControl,gTaikei);
    gMain_Measure    = new Main_Measure();
    gBright          = new Bright();
    gSonarMeasure    = new SonarMeasure();
    gArm             = new Arm();
    gTail            = new Tail();
    gXpointer        = new Xpointer();
    gYpointer        = new Ypointer();
    gOdometer        = new Odometer();
    gTurn            = new Turn();
    gSpeedmeter      = new Speedmeter();
    gWalker          = new Walker(gDrive,gBright,gXpointer,gYpointer,gTurn,gArm,gTail);
    gMain_Judge      = new Main_Judge();
    gBright_Judge    = new Bright_Judge();
    gDistance_Judge  = new Distance_Judge();
    gTurn_Judge      = new Turn_Judge();
    gLineTracer      = new LineTracer(gDrive,gBright,gXpointer,gYpointer,gTurn,gArm,gTail);
    gArmControl      = new ArmControl(gMotor_Arm,gDrive,gBright,gXpointer,gYpointer,gTurn,gArm,gTail);
    gTailControl     = new TailControl(gMotor_Tail,gDrive,gBright,gXpointer,gYpointer,gTurn,gArm,gTail);
    gVirtualStraight = new VirtualStraight(gDrive,gBright,gXpointer,gYpointer,gTurn,gArm,gTail);
    gVirtualCurve    = new VirtualCurve(gDrive,gBright,gXpointer,gYpointer,gTurn,gArm,gTail);
    gScenario        = new Scenario(0);
    gScenarioTracer  = new ScenarioTracer(gDrive,
                                          gWalker,
                                          gScenario,
                                          gScenarioTimer);
    gRandomWalker    = new RandomWalker(gLineTracer,
                                        gVirtualCurve,
                                        gVirtualStraight,
                                        gScenarioTracer,
                                        gStarter,
                                        gWalkerTimer);
    gColorMeasure    = new ColorMeasure(gColorSensor,gBright);
    gSonar           = new Sonar(gSonarSensor,gSonarMeasure);
    gVirtualPointer  = new VirtualPointer(gMotorControl,gXpointer,gYpointer,gOdometer,gTurn,gArm,gTail,gSpeedmeter);

    // シナリオを構築する
    for (uint32_t i = 0; i < (sizeof(gScenes)/sizeof(gScenes[0])); i++) {
        gScenario->add(&gScenes[i]);
    }
    // 初期化完了通知
    ev3_led_set_color(LED_ORANGE);
}

/**
 * EV3システム破棄
 */
static void user_system_destroy() {
    gLeftWheel.reset();
    gRightWheel.reset();
    gMotor_Arm.reset();
    gMotor_Tail.reset();
    
    delete gRandomWalker;
    delete gScenarioTracer;
    delete gScenario;
    delete gLineTracer;
    delete gVirtualCurve;
    delete gWalker;
    delete gWalkerTimer;
    delete gScenarioTimer;
    delete gStarter;    
    
}

/**
 * メインタスク
 */
void main_task(intptr_t unused) {
    user_system_create();  // センサやモータの初期化処理

    // 周期ハンドラ開始
    sta_cyc(CYC_TRACER);
    sta_cyc(CYC_POLLING);

    slp_tsk();  // バックボタンが押されるまで待つ

    // 周期ハンドラ停止
    stp_cyc(CYC_TRACER);
    stp_cyc(CYC_POLLING);

    user_system_destroy();  // 終了処理

    ext_tsk();
}

/**
 * ライントレースタスク
 */
void tracer_task(intptr_t exinf) {
    if (ev3_button_is_pressed(BACK_BUTTON)) {
        wup_tsk(MAIN_TASK);  // バックボタン押下
    } else {
        gWalker->setCommand(50,0);
        /*gLineTracer->init();
        gLineTracer->run();*/
        gRandomWalker->run();
        double status[]={0,-50};
        gArmControl->init(status);
        gArmControl->run();
        /*double status2[]={0,100000};
        gTailControl->init(status2);
        gTailControl->run();*/    
    }

    ext_tsk();
}

void polling_task(intptr_t exinf) {
   gColorMeasure->get_rgb();
   gVirtualPointer->calc();
   gSonar->get_dis();
    ext_tsk();
}