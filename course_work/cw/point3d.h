#ifndef POINT3D_H
#define POINT3D_H

#include <math.h>

#include "vector3d.h"

class Point3D
{
public:
    double x, y, z;
public:
    Point3D(void);
    Point3D(const double value);
    Point3D(const double nx, const double ny, const double nz);
    Point3D(const Point3D &p);
    ~Point3D();

    Point3D &operator= (const Point3D &p);

    Point3D operator- (void) const;
    Point3D operator* (const double a) const;

    double squared_distance(const Point3D &p) const;
    double distance(const Point3D &p) const;


    Vector3D operator- (const Point3D &p) const;
    Point3D operator- (const Vector3D &v) const;
    Point3D operator+ (const Vector3D &v) const;

};

#endif // POINT3D_H
