#ifndef WORLDDATA_H
#define WORLDDATA_H

#include <vector>
#include "geometricobject.h"
#include "rgbcolor.h"
class WorldData
{
public:
    WorldData(std::vector<GeometricObject *> ob, RGBColor color);
    std::vector<GeometricObject *> objects;
    RGBColor background_color;
    // lights
};

#endif // WORLDDATA_H
