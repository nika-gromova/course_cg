#include "tori.h"
#include "maths.h"

const double kHugeValue	= 1.0E10;

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
    double dorig = dox + doy + doz - a * a - b * b;
    double coordssum = ox * dx + oy * dy + oz * dz;
    double ddir = ddx + ddy + ddz;

    double coeffs[5];
    double roots[4];

    coeffs[4] = ddir * ddir;
    coeffs[3] = 4 * ddir * coordssum;
    coeffs[2] = 2 * ddir * dorig + 4 * coordssum * coordssum + 4 * a * a * dy * dy;
    coeffs[1] = 4 * dorig * coordssum + 8 * a * a * oy * dy;
    coeffs[0] = dorig * dorig - 4 * a * a * (b * b - oy * oy);

    int res = SolveQuartic(coeffs, roots);

    bool hit = false;
    double min_t = kHugeValue;

    if (!res)
        return false;

    for (auto i = 0; i < res; i++)
    {
        if (roots[i] > KEps && roots[i] < min_t)
        {
            hit = true;
            min_t = roots[i];
        }
    }

    if (!hit)
        return false;

    tmin = min_t;
    normal.origin = ray.origin + (ray.direction * tmin);
    normal.direction = this->calculate_normal(normal.origin);

    return true;
}

Vector3D Tori::calculate_normal(const Point3D &p)
{
    double ox = p.x - center.x, oy = p.y - center.y, oz =p.z - center.z;
    double sum_squared = ox * ox + oy * oy + oz * oz - a * a - b * b;
    double da = 2 * a * a;
    Vector3D normal;
    normal.x = 4 * ox * (sum_squared);
    normal.y = 4 * oy * (sum_squared + da);
    normal.z = 4 * oz * (sum_squared);

    normal.normalize();
    return normal;
}

