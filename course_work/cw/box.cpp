#include "box.h"

Box::Box(void): GeometricObject(), center(0.0), p0(-1, 0, -1), p1(1, -1, 1) {}

Box::Box(const Point3D &c, const double &len, const double &w, const double &h): GeometricObject(), center(c)
{
    p0 = Point3D(c.x - len / 2.0, c.y + h / 2.0, c.z - w / 2.0);
    p1 = Point3D(c.x + len / 2.0, c.y - h / 2.0, c.z + w / 2.0);
}

Box::Box(const Point3D &c, const Point3D &ps, const Point3D &pe): GeometricObject(), center(c), p0(ps), p1(pe) {}

Box::Box(const Box &b): GeometricObject(), center(b.center), p0(b.p0), p1(b.p1) {}

Box::~Box() {}

void Box::set_center(const Point3D &c)
{
    center = c;
}

void Box::set_center(const double &x, const double &y, const double &z)
{
    center = Point3D(x, y, z);
}

void Box::set_sizes(const double &len, const double &w, const double &h)
{
    p0 = Point3D(center.x - len / 2.0, center.y + h / 2.0, center.z - w / 2.0);
    p1 = Point3D(center.x - len / 2.0, center.y + h / 2.0, center.z - w / 2.0);
}

bool Box::hit(const Ray &ray, double &tmin, Ray &normal)
{

    return true;
}
