#ifndef PYRAMID_H
#define PYRAMID_H
#include <vector>
#include "geometricobject.h"
#include "triangle.h"
#include "rectangle.h"

#define SIDESNUM 4

class Pyramid : public GeometricObject
{
public:
    Pyramid(void);
    Pyramid(const Point3D &cen, const double &length, const double &height);
    Pyramid(const Point3D &cen, const Point3D &down, const Point3D &t, const double &length);
    Pyramid(const Pyramid &p);

    ~Pyramid(void);

    Pyramid &operator= (const Pyramid &p);

    void set_center(const Point3D &c);
    void set_center(const double &x, const double &y, const double &z);
    void set_sizes(const double &length, const double &width, const double &height);

    bool hit(const Ray &ray, double &tmin, Ray &normal);

private:
    Point3D center;
    Point3D top;
    Point3D p0;
    double side;


    std::vector<Triangle> planes;
    Rectangle bottom;
    void assign_planes(void);
    // 4 triangles + 1 rectangle
};

#endif // PYRAMID_H
