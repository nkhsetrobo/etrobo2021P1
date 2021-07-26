#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_

class Bright{
    public:
        static const float Bvalue;
        Main_Bright();
        void  load();
        float get_value();


    private:

        float bvalue;
};

#endif 