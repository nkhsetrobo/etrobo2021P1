#ifndef EV3_UNIT_SONAR_H_
#define EV3_UNIT_SONAR_H_
#include "SonarSensor.h"
#include "SonarMeasure.h"


class Sonar {
    public:
        explicit Sonar(const ev3api::SonarSensor& sonarsensor,SonarMeasure* sonarmeasure);
        void get_dis();

    private:
        const ev3api::SonarSensor& mSonarSensor;
        SonarMeasure* mSonarMeasure;
};
#endif