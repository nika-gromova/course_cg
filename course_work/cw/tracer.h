#ifndef TRACER_H
#define TRACER_H

#include "rgbcolor.h"
#include "ray.h"
#include "worlddata.h"

const double kHugeValue	= 1.0E10;

class Tracer
{
public:
    Tracer(void);
    ~Tracer(void);

    RGBColor trace_ray(const Ray &ray, WorldData &data, int depth = 3);
    RGBColor compute_intensity(WorldData &data, const Point3D &intersect_point, const Vector3D &normal, const Vector3D &to_the_camera, const Material *material, int depth);
};

#endif // TRACER_H
