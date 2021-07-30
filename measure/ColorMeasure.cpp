#include "ColorMeasure.h"

ColorMeasure::ColorMeasure(const ev3api::ColorSensor& colorSensor,Bright* bright)
    :Main_Measure(),mColorSensor(colorSensor),mBright(bright)
{
}


void ColorMeasure::get_rgb()
{
    rgb_raw_t rgbr;
    mColorSensor.getRawColor(rgbr);
    double cvalue=rgbr.r*0.21+rgbr.g*0.72+rgbr.b*0.07;
    double nnum=2.0/117;/*白の値（最大値）をー１～１で正規化*/
    cvalue=(cvalue*nnum)-1;
    if(cvalue>1){
        cvalue=1;
    }else if(cvalue<-1){
        cvalue=-1;
    }
    mBright->load(cvalue);
}

