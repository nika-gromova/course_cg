#include "cone.h"

Cone::Cone(void) : GeometricObject(), center(Point3D(0.0, 0.5, 0.0)), radius(1.0), height(1.0), base(Disk(center, radius, Vector3D(0, 1, 0))) {}

Cone::Cone(const Point3D &cen, const double &r, const double &h) : GeometricObject(), center(cen), radius(r), height(h)
{
    base = Disk(center, r, Vector3D(0, 1, 0));
}

Cone::Cone(const Cone &c) : GeometricObject(), center(c.center), radius(c.radius), height(c.height), base(c.base) {}

Cone::~Cone() {}

Cone &Cone::operator=(const Cone &c)
{
    if (this == &c)
        return (*this);
    GeometricObject::operator =(c);

    center = c.center;
    radius = c.radius;
    height = c.height;
    base = c.base;

    return (*this);
}

void Cone::set_center(const Point3D &cen)
{
    center = cen;
}

void Cone::set_base_radius(const double &r)
{
    radius = r;
}

void Cone::set_height(const double &h)
{
    height = h;
}

bool Cone::hit(const Ray &ray, double &tmin, Ray &normal)
{
    return false;
}

