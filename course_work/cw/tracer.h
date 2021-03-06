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

    RGBColor trace_ray(const Ray &ray, const WorldData &data, int depth = 3);
    RGBColor compute_intensity(const WorldData &data, const Point3D &intersect_point, const Vector3D &normal, const Vector3D &to_the_camera, const Material *material);
};

#endif // TRACER_H
