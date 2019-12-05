#include "box.h"

Box::Box(void): GeometricObject(), center(0.0), p0(-1, 0, -1), p1(1, -1, 1) {}

Box::Box(const Point3D &c, const double &len, const double &w, const double &h): GeometricObject(), center(c)
{
    p0 = Point3D(c.x - len / 2.0, c.y - h / 2.0, c.z - w / 2.0);
    p1 = Point3D(c.x + len / 2.0, c.y + h / 2.0, c.z + w / 2.0);
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
    p0 = Point3D(center.x - len / 2.0, center.y - h / 2.0, center.z - w / 2.0);
    p1 = Point3D(center.x + len / 2.0, center.y + h / 2.0, center.z + w / 2.0);
}

void swap(double &m1, double &m2)
{
    double tmp = m1;
    m1 = m2;
    m2 = tmp;
}

bool Box::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double ox = ray.origin.x, oy = ray.origin.y, oz = ray.origin.z;
    double dx = ray.direction.x, dy = ray.direction.y, dz = ray.direction.z;

    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;
    double a = 1.0 / dx;
    tx_min = (p0.x - ox) * a;
    tx_max = (p1.x - ox) * a;
    if (a < 0)
        swap(tx_max, tx_min);

    double b = 1.0 / dy;
    ty_min = (p0.y - oy) * b;
    ty_max = (p1.y - oy) * b;
    if (b < 0)
        swap(ty_max, ty_min);

    double c= 1.0 / dz;
    tz_min = (p0.z - oz) * c;
    tz_max = (p1.z - oz) * c;
    if (c < 0)
        swap(tz_max, tz_min);

    double t0, t1;
    int face_in, face_out;

    if (tx_min > ty_min)
    {
        t0 = tx_min;
        face_in = (a >= 0.0) ? 0 : 1;
    }
    else
    {
        t0 = ty_min;
        face_in = (b >= 0.0) ? 2 : 3;
    }
    if (tz_min > t0)
    {
        t0 = tz_min;
        face_in = (c >= 0.0) ? 4 : 5;
    }

    if (tx_max < ty_max)
    {
        t1 = tx_max;
        face_out = (a >= 0.0) ? 1 : 0;
    }
    else
    {
        t1 = ty_max;
        face_out = (b >= 0.0) ? 3 : 2;
    }
    if (tz_max < t1)
    {
        t1 = tz_max;
        face_out = (c >= 0.0) ? 5 : 4;
    }


    if (t0 < t1 && t1 > KEps)
    {
        if (t0 > KEps)
        {
            tmin = t0;
            normal.direction = (this->calculate_normal(face_in));
        }
        else
        {
            tmin = t1;
            normal.direction = (this->calculate_normal(face_out));
        }
        normal.origin = ray.origin + (ray.direction * tmin);
        return true;
    }
    return false;
}

Vector3D Box::calculate_normal(const int &num)
{
    switch (num)
    {
    case (0):
        return Vector3D(-1, 0, 0);
    case (1):
        return Vector3D(1, 0, 0);
    case (2):
        return  Vector3D(0, -1, 0);
    case (3):
        return Vector3D(0, 1, 0);
    case (4):
        return Vector3D(0, 0, -1);
    case (5):
        return Vector3D(0, 0, 1);
    }
    return Vector3D(0, 0, 0);
}
