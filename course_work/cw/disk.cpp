#include "disk.h"

Disk::Disk(void) : GeometricObject(), center(Point3D(0.0)), dradius(1.0), local_normal(Vector3D(0.0, 1.0, 0.0)) {}

Disk::Disk(const Point3D &cen, const double &r, const Vector3D &normal) : GeometricObject(), center(cen), dradius(r * r), local_normal(normal)
{
    local_normal.normalize();
}

Disk::Disk(const Disk &d) : GeometricObject(), center(d.center), dradius(d.dradius), local_normal(d.local_normal) {}

Disk::~Disk() {}

Disk &Disk::operator=(const Disk &d)
{
    if (this == &d)
        return (*this);
    GeometricObject::operator =(d);
    center = d.center;
    dradius = d.dradius;
    local_normal = d.local_normal;
    return (*this);
}

void Disk::set_center(const Point3D &cen)
{
    center = cen;
}

void Disk::set_radius(const double &r)
{
    dradius = r * r;
}

void Disk::set_normal(const Vector3D &normal)
{
    local_normal = normal;
    local_normal.normalize();
}

bool Disk::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double t = (center - ray.origin) * local_normal / (local_normal * ray.direction);
    if ( t <= KEps)
        return false;
    Point3D p = ray.origin + (ray.direction * t);
    Vector3D d = (p - center);

    double check = d.squared_length();
    if (check > dradius)
        return false;

    tmin = t;
    normal.origin = p;
    normal.direction = local_normal;
    return true;
}
