#ifndef EV3_UNIT_ARM_H_
#define EV3_UNIT_ARM_H_

class Arm{
    public:
        Arm();
        void load(float mload);
        float get_value();
        void *.reset();

    private:

        float avalue;
};

#endif