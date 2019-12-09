#include "rectangle.h"

Rectangle::Rectangle() : GeometricObject(), p0(Point3D(-1, 0, -1)), da(1), db(1), local_normal(Vector3D(0, 1, 0))
{
    this->assign_vect(1, 1);
}

Rectangle::Rectangle(const Point3D &point, const double &length, const double &width, const Vector3D &normal) : GeometricObject(),
    p0(point), da(length * length), db(width * width), local_normal(normal)
{
    local_normal.normalize();
    this->assign_vect(length, width);
}

Rectangle::Rectangle(const Rectangle &r) : GeometricObject(),  p0(r.p0), a(r.a), b(r.b), da(r.da), db(r.db), local_normal(r.local_normal) {}

Rectangle::~Rectangle() {}

Rectangle &Rectangle::operator=(const Rectangle &r)
{
    if (this == &r)
        return (*this);
    GeometricObject::operator =(r);

    p0 = r.p0;
    a = r.a;
    b = r.b;
    da = r.da;
    db = r.db;
    local_normal = r.local_normal;

    return (*this);
}

void Rectangle::set_point(const Point3D &p)
{
    p0 = p;
}

void Rectangle::set_sizes(const double &length, const double &width)
{
    this->assign_vect(length, width);
    da = length * length;
    db = width * width;
}

void Rectangle::set_normal(const Vector3D &normal)
{
    local_normal = normal;
    local_normal.normalize();
}

bool Rectangle::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double t = (p0 - ray.origin) * local_normal / (local_normal * ray.direction);
    if ( t <= KEps)
        return false;
    Point3D p = ray.origin + (ray.direction * t);
    Vector3D d = (p - p0);

    double check_a = (d * a);
    if (check_a < 0 || check_a > da)
        return false;

    double check_b = (d * b);
    if (check_b <0 || check_b > db)
        return false;

    tmin = t;
    normal.origin = p;
    normal.direction = local_normal;
    return true;
}

void Rectangle::assign_vect(const double &len, const double &w)
{
    a = (Point3D(p0.x + w, p0.y, p0.z) - p0);
    b = (Point3D(p0.x, p0.y, p0.z + len) - p0);
}
