#include "worlddata.h"
#include <stdio.h>
WorldData::WorldData() {}

WorldData::~WorldData()
{
    for (const auto item : objects)
        delete item;
    for (const auto item : lights)
        delete item;
}
