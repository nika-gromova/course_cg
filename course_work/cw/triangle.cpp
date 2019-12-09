#include "triangle.h"

Triangle::Triangle(): GeometricObject(), v0(0, 0, 0), v1(0, 0, 0), v2(1, 0, 0), local_normal(0, 1, 0) {}

Triangle::Triangle(const Point3D &a, const Point3D &b, const Point3D &c) : GeometricObject()
{
    v0 = a;
    v1 = b;
    v2 = c;
    local_normal = ((v2 - v0) ^ (v1 - v0));
    local_normal.normalize();
}

Triangle::Triangle(const Triangle &t) : GeometricObject()
{
    v0 = t.v0;
    v1 = t.v1;
    v2 = t.v2;
    local_normal = t.local_normal;
}

Triangle::~Triangle() {}

Triangle &Triangle::operator=(const Triangle &t)
{
    if (this == &t)
        return (*this);
    GeometricObject::operator =(t);

    v0 = t.v0;
    v1 = t.v1;
    v2 = t.v2;
    local_normal = t.local_normal;

    return (*this);
}

bool Triangle::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double a = v0.x -v1.x, b = v0.x - v2.x, c = ray.direction.x, d = v0.x - ray.origin.x;
    double e = v0.y - v1.y, f =v0.y - v2.y, g = ray.direction.y, h = v0.y - ray.origin.y;
    double i = v0.z - v1.z, j = v0.z - v2.z, k = ray.direction.z, v = v0.z - ray.origin.z;

    double m = f * k - g * j, n = h * k - g * v, p = f * v - h * j;
    double q = g * i - e * k, s = e * j - f * i;

    double inv_d = 1.0 / (a * m + b * q + c * s);
    double e1 = d * m - b * n - c * p;
    double beta = e1 * inv_d;
    if (beta < 0.0)
        return false;

    double r = e * v - h * i;
    double e2 = a * n + d * q + c * r;
    double gamma = e2 * inv_d;
    if (gamma < 0.0)
        return false;
    if (gamma + beta > 1.0)
        return false;

    double e3 = a * p - b * r + d * s;
    double t = e3 * inv_d;
    if (t < KEps)
        return false;

    tmin = t;
    normal.direction = local_normal;
    normal.origin = ray.origin + (ray.direction * t);
    return true;
}

