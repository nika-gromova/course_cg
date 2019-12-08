#ifndef PYRAMID_H
#define PYRAMID_H

#include "geometricobject.h"
#include "triangle.h"

class Pyramid : public GeometricObject
{
public:
    Pyramid(void);
    Pyramid(const Point3D &cen, const double &length, const double &width, const double &height);
    Pyramid(const Point3D &cen, const Point3D &down0, const Point3D &down1, const Point3D &t);
    Pyramid(const Pyramid &p);

    ~Pyramid(void);

    void set_center(const Point3D &c);
    void set_center(const double &x, const double &y, const double &z);
    void set_sizes(const double &length, const double &width, const double &height);

    // bool hit(const Ray &ray, double &tmin, Ray &normal);

private:
    Point3D center;
    Point3D top;
    Point3D p0;
    Point3D p1;


    Triangle side1;
    Triangle side2;
    Triangle side3;
    Triangle side4;
    void assign_sides(void);
    // 4 triangles + 1 rectangle
};

#endif // PYRAMID_H
