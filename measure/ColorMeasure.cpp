#include "ColorMeasure.h"

ColorMeasure::ColorMeasure(const ev3api::ColorSensor& colorSensor,Bright* bright)
    :Main_Measure(),mColorSensor(colorSensor),mBright(bright)
{
}


void ColorMeasure::get_rgb()
{
    rgb_raw_t rgbr;
    mColorSensor.getRawColor(rgbr);
    float cvalue=rgbr.r*0.21+rgbr.g*0.72+rgbr.b*0.07;
    float nnum=2/117;/*白の値（最大値）をー１～１で正規化*/
    cvalue=cvalue*nnum-1;
    mBright->load(cvalue);
}

