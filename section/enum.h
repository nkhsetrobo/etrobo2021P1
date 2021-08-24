#ifndef EV3_APP_ENUM_H_
#define EV3_APP_ENUM_H_ 
    
    enum WALKER_NO  //上から順に番号を振ってくれる
        {
            WALKER,
            LINETRACER,
            CURVE,
            STRAIGHT,
            ARM,
            TAIL
        };

        enum JUDGE_NO
        {
            BRIGHT,
            DISTANCE,
            TURN,
            ARMJUDGE,
            TAILJUDGE
        };
#endif