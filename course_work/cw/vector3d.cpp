#include "vector3d.h"
#include "point3d.h"
Vector3D::Vector3D(void): x(0.0), y(0.0), z(0.0) {}

Vector3D::Vector3D(double value): x(value), y(value), z(value) {}

Vector3D::Vector3D(double nx, double ny, double nz): x(nx), y(ny), z(nz) {}

Vector3D::Vector3D(const Vector3D &v): x(v.x), y(v.y), z(v.z) {}

Vector3D::Vector3D(const Point3D &p): x(p.x), y(p.y), z(p.z) {}

Vector3D::~Vector3D() {}

Vector3D &Vector3D::operator=(const Vector3D &v)
{
    if (this == &v)
        return (*this);
    x = v.x;
    y = v.y;
    z = v.z;
    return (*this);
}

Vector3D &Vector3D::operator=(const Point3D &p)
{
    x = p.x;
    y = p.y;
    z = p.z;
    return (*this);
}

Vector3D Vector3D::operator-() const
{
    return Vector3D(-x, -y, -z);
}

double Vector3D::length() const
{
    return sqrt(x * x + y * y + z * z);
}

double Vector3D::squared_length() const
{
    return (x * x + y * y + z * z);
}

Vector3D Vector3D::operator*(double a) const
{
    return Vector3D(x * a, y * a, z * a);
}

Vector3D Vector3D::operator/(double a) const
{
    return (*this) * (1.0 / a);
}

Vector3D Vector3D::operator+(const Vector3D &v) const
{
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D &Vector3D::operator+=(const Vector3D &v)
{
    x += v.x;
    y += v.y;
    z += v.z;
    return (*this);

}

Vector3D Vector3D::operator-(const Vector3D &v) const
{
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

Vector3D &Vector3D::operator-=(const Vector3D &v)
{
    x -= v.x;
    y -= v.y;
    z -= v.z;
    return (*this);
}

double Vector3D::operator*(const Vector3D &v) const
{
    return x * v.x + y * v.y + z * v.z;
}

Vector3D Vector3D::operator^(const Vector3D &v) const
{
    return Vector3D(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}

Vector3D &Vector3D::normalize()
{
    double inv_len = 1.0 / (this->length());
    x *= inv_len;
    y *= inv_len;
    z *= inv_len;
    return (*this);
}

Vector3D Vector3D::get_normal() const
{
    double inv_len = 1.0 / (this->length());
    return Vector3D(x * inv_len, y * inv_len, z * inv_len);
}
