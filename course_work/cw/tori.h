#ifndef TORI_H
#define TORI_H

#include "geometricobject.h"

class Tori : public GeometricObject
{
public:
    Tori(void);
    Tori(const Point3D &cen, const double &outer_r, const double &inner_r);
    Tori(const Tori &t);

    ~Tori(void);

    Tori &operator= (const Tori &t);

    void set_center(const Point3D &cen);
    void set_outer_r(const double &outer_r);
    void set_inner_r(const double &inner_r);

    bool hit(const Ray &ray, double &tmin, Ray &normal);
    Vector3D calculate_normal(const Point3D &p);

private:
    Point3D center;
    double a; // outer radius
    double b; // inner radius
};

#endif // TORI_H
