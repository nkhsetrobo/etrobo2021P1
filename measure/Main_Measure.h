#ifndef EV3_UNIT_MAINMEASURE_H_
#define EV3_UNIT_MAINMEASURE_H_

class Main_Measure{
    public:
        Main_Measure();
        virtual float  get_value();
        void load(float mload);


    private:

};

#endif 
