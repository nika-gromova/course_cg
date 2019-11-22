#ifndef WORLDDATA_H
#define WORLDDATA_H

#include <vector>
#include "geometricobject.h"
#include "rgbcolor.h"
#include "light.h"

class WorldData
{
public:
    WorldData(std::vector<GeometricObject *> ob, RGBColor color);
    std::vector<GeometricObject *> objects;
    RGBColor background_color;
    std::vector<Light *> lights;

    // ambient light
};

#endif // WORLDDATA_H
