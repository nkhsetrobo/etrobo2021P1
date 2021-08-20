#ifndef EV3_UNIT_XPOINTER_H_
#define EV3_UNIT_XPOINTER_H_

#include "Main_Measure.h"

class Xpointer : public Main_Measure{
    public:
        Xpointer();
        void load(float mload);
        float get_value();
        void  init();

    private:

        float x_coordinates;
};

#endif