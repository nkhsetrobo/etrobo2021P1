#ifndef EV3_UNIT_YPOINTER_H_
#define EV3_UNIT_YPOINTER_H_

#include "Main_Measure.h"

class Ypointer : public Main_Measure{
    public:
        Ypointer();
        void load(float mload);
        float get_value();
        void  init();

    private:

        float y_coordinates;
};

#endif