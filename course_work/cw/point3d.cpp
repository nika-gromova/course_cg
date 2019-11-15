#include "point3d.h"

Point3D::Point3D(void): x(0.0), y(0.0), z(0.0) {}

Point3D::Point3D(const double value): x(value), y(value), z(value) {}

Point3D::Point3D(const double nx, const double ny, const double nz): x(nx), y(ny), z(nz) {}

Point3D::Point3D(const Point3D &p): x(p.x), y(p.y), z(p.z) {}

Point3D::~Point3D() {}

Point3D &Point3D::operator=(const Point3D &p)
{
    if (this == &p)
        return (*this);
    x = p.x;
    y = p.y;
    z = p.z;
    return (*this);
}

Point3D Point3D::operator-() const
{
    return Point3D(-x, -y, -z);
}

Point3D Point3D::operator*(const double a) const
{
    return Point3D(x * a, y * a, z * a);
}

double Point3D::squared_distance(const Point3D &p) const
{
    double dx = p.x - x, dy = p.y - y, dz = p.z - z;
    return dx * dx + dy * dy + dz * dz;
}

double Point3D::distance(const Point3D &p) const
{
    double dx = p.x - x, dy = p.y - y, dz = p.z - z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

Vector3D Point3D::operator-(const Point3D &p) const
{
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D Point3D::operator-(const Vector3D &v) const
{
    return Point3D(x - v.x, y - v.y, z - v.z);
}

Point3D Point3D::operator+(const Vector3D &v) const
{
    return Point3D(x + v.x, y + v.y, z + v.z);
}

