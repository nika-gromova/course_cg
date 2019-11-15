#ifndef RAY_H
#define RAY_H

#include "point3d.h"
#include "vector3d.h"

class Ray
{
public:
    Point3D origin;
    Vector3D direction;
public:
    Ray(void);
    Ray(const Point3D &o, const Vector3D &d);
    Ray(const Ray &r);
    ~Ray();

    Ray &operator= (const Ray &r);
};

#endif // RAY_H
