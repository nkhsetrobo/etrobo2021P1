#ifndef EV3_MEASURE_MAINMEASURE_H_
#define EV3_MEASURE_MAINMEASURE_H_

class Main_Measure{
    public:
        Main_Measure();
        virtual float  get_value();
        virtual void load(float mload);


};
#endif 
