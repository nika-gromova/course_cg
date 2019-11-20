#ifndef SPHERE_H
#define SPHERE_H

#include "geometricobject.h"

class Sphere: public GeometricObject
{
public:
    Sphere(void);
    Sphere(const Point3D &c, double r);
    Sphere(const Sphere& sp);

    ~Sphere(void);

    Sphere &operator= (const Sphere& sp);
    Sphere *clone(void) const;

    void set_center(const Point3D& c);
    void set_center(double x, double y, double z);
    void set_radius(double r);
    double get_data();
    bool hit(const Ray &ray, double &tmin);
    Vector3D calculate_normal(const Point3D &p);

private:
    Point3D center;
    double radius;
    static const double kEpsilon;
};

#endif // SPHERE_H
