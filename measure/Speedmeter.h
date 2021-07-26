#ifndef EV3_UNIT_SPEEDOMETER_H_
#define EV3_UNIT_SPEEDOMETER_H_

class Speedmeter{
    public:
        Speedmeter();
        void load(float mload,/*int Measurement_time*/);
        float get_value();


    private:


        float speed;
};

#endif