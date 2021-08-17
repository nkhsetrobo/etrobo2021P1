#include "Sonar.h"

Sonar::Sonar(const ev3api::SonarSensor& sonarsensor,SonarMeasure* sonarmeasure)
    :mSonarSensor(sonarsensor),
    mSonarMeasure(sonarmeasure)
{
}


void Sonar::get_dis()
{
    int dis=mSonarSensor.getDistance();
    //printf("%d\n",dis);
    mSonarMeasure->load(dis);
}