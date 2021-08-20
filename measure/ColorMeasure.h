#ifndef EV3_UNIT_COLORMEASURE_H_
#define EV3_UNIT_COLORMEASURE_H_
#include "ColorSensor.h"
#include "Bright.h"
#include "Colorh.h"
#include "Colors.h"

typedef struct hsv_t {
    float h;
    float s;
    float v;
} HSV_T;


class ColorMeasure {
    public:
        explicit ColorMeasure(const ev3api::ColorSensor& colorSensor,Bright* bright,Colorh* colorh,Colors* colors);
        void get_rgb();
        void getHSV(rgb_raw_t rgb, hsv_t& hsv);
    private:
        const ev3api::ColorSensor& mColorSensor;
        Bright* mBright;
        Colorh* mColorh;
        Colors* mColors;
};
#endif