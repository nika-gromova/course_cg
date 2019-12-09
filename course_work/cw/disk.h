#ifndef DISK_H
#define DISK_H

#include "geometricobject.h"

class Disk : public GeometricObject
{
public:
    Disk(void);
    Disk(const Point3D &cen, const double &r, const Vector3D &normal);
    Disk(const Disk &d);

    ~Disk(void);

    Disk &operator= (const Disk &d);

    void set_center(const Point3D &cen);
    void set_radius(const double &r);
    void set_normal(const Vector3D &normal);

    bool hit(const Ray &ray, double &tmin, Ray &normal);

private:
    Point3D center;
    double dradius;
    Vector3D local_normal;
};

#endif // DISK_H
