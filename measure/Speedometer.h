#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_

class Speedometer{
    public:
        Speedometer();
        void load(float mload,/*int Measurement_time*/);
        float get_value();


    private:


        float speed;
};

#endif