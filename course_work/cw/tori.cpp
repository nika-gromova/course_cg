#include "tori.h"

Tori::Tori(void) : GeometricObject(), center(Point3D(0.0)), a(2.0), b(1.0) {}

Tori::Tori(const Point3D &cen, const double &outer_r, const double &inner_r) : GeometricObject()
{
    center = cen;
    a = outer_r;
    b = inner_r;
}

Tori::Tori(const Tori &t) : GeometricObject(), center(t.center), a(t.a), b(t.b) {}

Tori::~Tori() {}

Tori &Tori::operator=(const Tori &t)
{
    if (this == &t)
        return (*this);
    center = t.center;
    a = t.a;
    b = t.b;
    return (*this);
}

void Tori::set_center(const Point3D &cen)
{
    center = cen;
}

void Tori::set_outer_r(const double &outer_r)
{
    a = outer_r;
}

void Tori::set_inner_r(const double &inner_r)
{
    b = inner_r;
}

bool Tori::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double ox = ray.origin.x - center.x;
    double oy = ray.origin.y - center.y;
    double oz = ray.origin.z - center.z;
    double dx = ray.direction.x, dy = ray.direction.y, dz = ray.direction.z;

    double dox = ox * ox, doy = oy * oy, doz = oz * oz;
    double ddx = dx * dx, ddy = dy * dy, ddz = dz * dz;
    double dorig = dox + doy + doz - (a * a + b * b) * (a * a + b * b);
    double dsum = ox * dx + oy * dy + oz * dz;
    double ddir = ddx + ddy + ddz;

    double c4 = ddir * ddir;
    double c3 = 4 * ddir * dsum;
    double c2 = 2 * ddir * ddir + 4 * dsum * dsum + 4 * a * a * dy * dy;
    double c1 = 4 * dorig * dsum + 8 * a * a * oy * dy;
    double c0 = 4 * dorig * dorig - 4 * a * a * (b * b - oy * oy);
    return false;
}

