#include "pyramid.h"

Pyramid::Pyramid(void) : GeometricObject(), center(0.0), top(0.0, -1.0, 0.0), p0(-1.0, 0.0, -1.0), p1(1.0, 0.0, 1.0)
{
    this->assign_sides();
}

Pyramid::Pyramid(const Point3D &cen, const double &length, const double &width, const double &height): GeometricObject()
{
    center = cen;
    top = Point3D(cen.x, cen.y - height, cen.z);
    p0 = Point3D(cen.x - width / 2.0, cen.y, cen.z - length / 2.0);
    p1 = Point3D(cen.x + width / 2.0, cen.y, cen.z + length / 2.0);
    this->assign_sides();
}

Pyramid::Pyramid(const Point3D &cen, const Point3D &down0, const Point3D &down1, const Point3D &t): GeometricObject()
{
    center = cen;
    p0 = down0;
    p1 = down1;
    top = t;
    this->assign_sides();
}

Pyramid::Pyramid(const Pyramid &p): GeometricObject()
{
    center = p.center;
    top = p.top;
    p0 = p.p0;
    p1 = p.p1;
    side1 = p.side1;
    side2 = p.side2;
    side3 = p.side3;
    side4 = p.side4;
}

Pyramid::~Pyramid() {}

void Pyramid::set_center(const Point3D &c)
{
    center = c;
}

void Pyramid::set_center(const double &x, const double &y, const double &z)
{
    center = Point3D(x, y, z);
}

void Pyramid::set_sizes(const double &length, const double &width, const double &height)
{
    top = Point3D(center.x, center.y - height, center.z);
    p0 = Point3D(center.x - width / 2.0, center.y, center.z - length / 2.0);
    p1 = Point3D(center.x + width / 2.0, center.y, center.z + length / 2.0);
    this->assign_sides();
}

void Pyramid::assign_sides()
{
    side1 = Triangle(top, p0, Point3D(p0.x, p0.y, p1.z));
    side2 = Triangle(top, Point3D(p0.x, p0.y, p1.z), p1);
    side3 = Triangle(top, p1, Point3D(p1.x, p1.y, p0.z));
    side4 = Triangle(top, Point3D(p1.x, p1.y, p0.z), p0);
}

