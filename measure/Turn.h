#ifndef EV3_UNIT_TURN_H_
#define EV3_UNIT_TURN_H_

class Turn{
    public:
        Turn();
        void load(float mload);
        float get_value();
        void init();

    private:

        float ttvalue;
};

#endif