#ifndef EV3_SPEEDCONTROL_H_
#define EV3_SPEEDCONTROL_H_

class SpeedControl{
    public:
        void getFWD();

    private:
        float nspeed;
        float aiming;
        float fspeed;
};
#endif