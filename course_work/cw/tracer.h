#ifndef TRACER_H
#define TRACER_H

#include "rgbcolor.h"
#include "ray.h"
#include "worlddata.h"

const double	kHugeValue	= 1.0E10;

class Tracer
{
public:
    Tracer(void);
    ~Tracer(void);

    RGBColor trace_ray(const Ray &ray, WorldData &data);
    RGBColor trace_ray(const Ray &ray, WorldData &data, int depth);
};

#endif // TRACER_H
