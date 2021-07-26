#ifndef EV3_UNIT_BRIGHT_H_
#define EV3_UNIT_BRIGHT_H_
#include "ColorSensor.h"
#include "Bright.h"

class ColorMeasure{
    public:
        explicit ColorMeasure(const ev3api::ColorSensor& colorSensor,Bright* mbright);
        void get_rgb();

    private:
        const ev3api::ColorSensor& mColorSensor;
        Bright* mbright;
};
#endif