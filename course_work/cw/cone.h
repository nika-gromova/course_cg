#ifndef CONE_H
#define CONE_H

#include "geometricobject.h"
#include "disk.h"

class Cone : public GeometricObject
{
public:
    Cone(void);
    Cone(const Point3D &cen, const double &r, const double &h);
    Cone(const Cone &c);

    ~Cone(void);

    Cone &operator= (const Cone &c);

    void set_center(const Point3D &cen);
    void set_base_radius(const double &r);
    void set_height(const double &h);

    bool hit(const Ray &ray, double &tmin, Ray &normal);

private:
    Point3D center; // center of a base
    double radius;
    double height;
    double dradius;
    double dheight;
    double k;
    Disk base;
};

#endif // CONE_H
