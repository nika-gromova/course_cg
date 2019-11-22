#include "worlddata.h"

WorldData::WorldData() {}

WorldData::~WorldData()
{
    for (const auto item : objects)
        delete item;
    for (const auto item : lights)
        delete item;
}
