#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_

class Angular{
    public:
        Angular();
        void load(float mload);
        void reset();
        float get_value();

    private:
    
        float avalue;
};

#endif 