#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geometricobject.h"

class Rectangle : public GeometricObject
{
public:
    Rectangle();
    Rectangle(const Point3D &point, const double &length, const double &width, const Vector3D &normal);
    Rectangle(const Rectangle &r);

    ~Rectangle(void);

    Rectangle &operator= (const Rectangle &r);

    void set_point(const Point3D &p);
    void set_sizes(const double &length, const double &width);
    void set_normal(const Vector3D &normal);

    bool hit(const Ray &ray, double &tmin, Ray &normal);
private:
    Point3D p0;
    Vector3D a, b;
    double da, db;
    Vector3D local_normal;
    void assign_vect(const double &len, const double &w);
};

#endif // RECTANGLE_H
