#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "geometricobject.h"

class Triangle : public GeometricObject
{
public:

    Triangle();
    Triangle(const Point3D &a, const Point3D &b, const Point3D &c);

    ~Triangle(void);

    bool hit(const Ray &ray, double &tmin, Ray &normal);
private:
    Point3D v0;
    Point3D v1;
    Point3D v2;
    Vector3D local_normal;
};
#endif // TRIANGLE_H
