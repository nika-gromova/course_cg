#ifndef CYLINDER_H
#define CYLINDER_H

#include <vector>
#include "geometricobject.h"
#include "disk.h"

class Cylinder : public GeometricObject
{
public:
    Cylinder(void);
    Cylinder(const Point3D &cen, const double &h, const double &r);
    Cylinder(const Cylinder &c);

    ~Cylinder(void);

    Cylinder &operator= (const Cylinder &c);

    void set_center(const Point3D &cen);
    void set_radius(const double &r);
    void set_height(const double &h);

    bool hit(const Ray &ray, double &tmin, Ray &normal);

private:
    Point3D center; // center of the bottom base
    double height;
    double radius;
    std::vector<Disk> bases;
    void assign_bases();
};

#endif // CYLINDER_H
