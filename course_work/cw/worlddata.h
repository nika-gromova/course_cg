#ifndef WORLDDATA_H
#define WORLDDATA_H

#include <vector>
#include "geometricobject.h"
#include "rgbcolor.h"
#include "light.h"

class WorldData
{
public:
    WorldData(void);
    ~WorldData();
    std::vector<GeometricObject *> objects;
    std::vector<Light *> lights;
    RGBColor background_color;
};

#endif // WORLDDATA_H
