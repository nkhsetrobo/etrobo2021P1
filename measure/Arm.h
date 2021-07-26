#ifndef EV3_UNIT_ARM_H_
#define EV3_UNIT_ARM_H_

class Arm{
    public:
        Arm();
        void load(float mload);
        float get_value();
        void init();

    private:

        float Arm_angle;
};

#endif