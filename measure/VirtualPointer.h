#ifndef EV3_UNIT_VIRTUALPOINTER_H_
#define EV3_UNIT_VIRTUALPOINTER_H_
#include "MotorControl.h"
#include "Xpointer.h"
#include "Ypointer.h"
#include "Odometer.h"
#include "Turn.h"
#include "math.h"
#define M_PI 3.14159265//π
#define D_LEFT 9.0//タイヤの円周
#define D_RIGHT 9.0//タイヤの円周
#define TREAD 13.8//車体幅


class VirtualPointer{
    public:
        VirtualPointer(MotorControl* motorcontrol,Xpointer* xpointer,Ypointer* ypointer,
                            Odometer* odometer,Turn* turn);
        void calc();
    private:
        MotorControl* mMotorControl;
        Xpointer* mXpointer;
        Ypointer* mYpointer;
        Odometer* mOdometer;
        Turn* mTurn;
        float current_rs1;
        float current_rs2;
        float prev_rs1;
        float prev_rs2;
        float th;
        float dth;
        float x;
        float y;
        float sumlen;

};

#endif