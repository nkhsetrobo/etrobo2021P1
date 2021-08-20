#include "ColorMeasure.h"

ColorMeasure::ColorMeasure(const ev3api::ColorSensor& colorSensor,Bright* bright,Colorh* colorh,Colors* colors)
    :mColorSensor(colorSensor),mBright(bright),mColorh(colorh),mColors(colors)
{
}


void ColorMeasure::get_rgb()
{
    rgb_raw_t rgbr;
    mColorSensor.getRawColor(rgbr);
    double cvalue=rgbr.r*0.21+rgbr.g*0.72+rgbr.b*0.07;
    double nnum=2.0/117;/*白の値（最大値）を -1～1で正規化*/
    cvalue=(cvalue*nnum)-1;
    if(cvalue>1){
        cvalue=1;
    }else if(cvalue<-1){
        cvalue=-1;
    }
    mBright->load(cvalue);
    hsv_t hsv;
    getHSV(rgbr,hsv);
}

void ColorMeasure::getHSV(rgb_raw_t rgb, hsv_t& hsv){
    float r = rgb.r;
    float g = rgb.g;
    float b = rgb.b;
               
    float h=0, s=0, v=0;
    
    if (r >= g && g >= b) { 
        
        if(r!=0)
            s = (r - b) / r;
        else 
            s=0;
        v = r;
        if(r==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (g - b) / (r- b);
    }
    if (r >= b && b >= g)
    {
        v = r;
        if(r!=0)
          s = (r - g) / r;
        else 
            s=0;
        if(r==g)
            h=0;
        else if(s!=0)
            h = 60.0 * (g - b) / (r - g) + 360.0;
    }
    if (g >= r && r >= b)
    {
        v = g;
        if(g!=0)
            s = (g - b) / g;
        else 
            s=0;
        if(g==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (b - r) / (g - b) + 120.0;
    }
    if (g >= b && b >= r)
    {
        v = g;
        if(g!=0)
            s = (g - r) / g;
        else 
            s=0;
        if(r==g)
            h=0;
        else if(s!=0)
            h = 60.0 * (b - r) / (g - r) + 120.0;
    }
    if (b >= r && r >= g)
    {
        v = b;
        if(b!=0)
            s = (b - g) / b;
        else
            s=0;
        if(g==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (r - g) / (b - g) + 240.0;
    }
    if (b >= g && g >= r)
    {
        v = b;
        if(b!=0) 
            s = (b - r) / b;
        else
            s=0;
        
        if(r==b)
            h=0;
        else if(s!=0)
            h = 60.0 * (r - g) / (b - r) + 240.0;
    }
    hsv.h = h;
    hsv.s = s;
    hsv.v = v;
    mColorh->load(hsv.h);
    mColors->load(hsv.s);
}

