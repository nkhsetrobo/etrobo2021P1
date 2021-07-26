#ifndef EV3_UNIT_YPOINTER_H_
#define EV3_UNIT_YPOINTER_H_

class Ypointer{
    public:
        Ypointer();
        void load(float mload);
        float get_value();
        void  init();

    private:

        float y_coordinates;
};

#endif