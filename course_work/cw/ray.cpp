#include "ray.h"

Ray::Ray(void): origin(0.0), direction(0.0, 0.0, 1.0) {}

Ray::Ray(const Point3D &o, const Vector3D &d): origin(o), direction(d) {}

Ray::Ray(const Ray &r): origin(r.origin), direction(r.direction) {}

Ray::~Ray() {}

Ray &Ray::operator=(const Ray &r)
{
    if (this == &r)
        return (*this);
    origin = r.origin;
    direction = r.direction;
    return (*this);
}
