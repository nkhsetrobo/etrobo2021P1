#ifndef EV3_UNIT_XPOINTER_H_
#define EV3_UNIT_XPOINTER_H_

class Xpointer{
    public:
        Xpointer();
        void load(float mload);
        float get_value();
        void .reset();

    private:

        float xvalue;
}

#endif