#include <iostream>
#include <cmath>
#include <math.h>

#ifndef trigoExtras
#define trigoExtras

double eleTan(double angleViewDeg, double distance, double HeightResult)
{
    double radians = angleViewDeg * M_PI / 180;
    HeightResult = distance * tan(radians);

    return HeightResult;
}

double depTan(double angleDepDeg, double height, double baseResult)
{
    double halfAngleDegree = 90 - angleDepDeg;
    double radians = halfAngleDegree * M_PI / 180;
    baseResult = height / radians;
    baseResult = height * tan(radians);

    return baseResult;
}



#endif // trigoExtras
