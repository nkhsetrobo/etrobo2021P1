#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_

class Odometer{
    public:
        Odometer();
        void load(float mload);
        void reset();
        float get_value();


    private:
    

        float ovalue;
};

#endif 