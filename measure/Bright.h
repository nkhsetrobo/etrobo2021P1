#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_

class Bright{
    public:
        Bright();
        void  load(float mload);
        float get_value();


    private:

        float bvalue;
};

#endif 