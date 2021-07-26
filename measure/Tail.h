#ifndef EV3_UNIT_TAIL_H_
#define EV3_UNIT_TAIL_H_

class Tail{
    public:
        Tail();
        void  load(float mload);
        float get_value();

    private:
        float tvalue;
};

#endif