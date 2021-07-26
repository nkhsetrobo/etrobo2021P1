#include "ColorMeasure.h"

ColorMeasure::ColorMeasure(const ev3api::ColorSensor& colorSensor,Bright* bright)
    :  mColorSensor(colorSensor),mbright(bright)
{
}


void ColorMeasure::get_rgb()
{
    rgb_raw_t rgbr;
    mColorSensor.getRawColor(rgbr);
    float cvalue=rgbr.r*0.21+rgbr.g*0.72+rgbr.b*0.07;
    mbright->load(cvalue);
}

