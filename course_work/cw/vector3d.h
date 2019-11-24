#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <math.h>
#include <maths.h>

class Point3D;

class Vector3D
{
public:
    double x, y, z;
public:
    Vector3D(void);
    Vector3D(double value);
    Vector3D(double nx, double ny, double nz);
    Vector3D(const Vector3D &v);
    Vector3D(const Point3D &p);
    ~Vector3D();

    Vector3D &operator= (const Vector3D &v);
    Vector3D &operator= (const Point3D &p);

    Vector3D operator- (void) const;
    double length(void) const;
    double squared_length(void) const;
    Vector3D operator* (double a) const;
    Vector3D operator/ (double a) const;

    Vector3D operator+ (const Vector3D &v) const;
    Vector3D &operator+= (const Vector3D &v);
    Vector3D operator- (const Vector3D &v) const;
    Vector3D &operator-= (const Vector3D &v);

    // скалярное произведение
    double operator* (const Vector3D &v) const;
    // векторное произведение
    Vector3D operator^ (const Vector3D &v) const;

    Vector3D &normalize(void);
    Vector3D get_normal(void) const;

    bool is_null(void) const;

};

#endif // VECTOR3D_H
