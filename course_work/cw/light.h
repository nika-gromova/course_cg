#ifndef LIGHT_H
#define LIGHT_H

#include "rgbcolor.h"
#include "point3d.h"

class Light
{
public:
    Light();
private:
    double intensity;
    RGBColor color;
    Point3D position;
};

#endif // LIGHT_H
