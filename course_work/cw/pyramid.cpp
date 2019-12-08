#include "pyramid.h"
const double kHugeValue	= 1.0E10;

Pyramid::Pyramid(void) : GeometricObject(), center(0.0), top(0.0, -1.0, 0.0), p0(-1.0, 0.0, -1.0), side(1)
{
    this->assign_planes();
}

Pyramid::Pyramid(const Point3D &cen, const double &length, const double &height): GeometricObject()
{
    center = cen;
    side = length;
    double tmp = side / 2.0;
    top = Point3D(cen.x, cen.y - height, cen.z);
    p0 = Point3D(cen.x - tmp, cen.y, cen.z - tmp);
    this->assign_planes();
}

Pyramid::Pyramid(const Point3D &cen, const Point3D &down, const Point3D &t, const double &length): GeometricObject()
{
    center = cen;
    side = length;
    p0 = down;
    top = t;
    this->assign_planes();
}

Pyramid::Pyramid(const Pyramid &p): GeometricObject()
{
    center = p.center;
    top = p.top;
    p0 = p.p0;
    side = p.side;
    for (auto i = 0; i < SIDESNUM; i++)
        planes[i] = (p.planes)[i];
}

Pyramid::~Pyramid() {}

Pyramid &Pyramid::operator=(const Pyramid &p)
{
    if (this == &p)
        return (*this);
    GeometricObject::operator =(p);

    center = p.center;
    top = p.top;
    p0 = p.p0;
    side = p.side;
    for (auto i = 0; i < SIDESNUM; i++)
        planes[i] = (p.planes)[i];

    return (*this);
}

void Pyramid::set_center(const Point3D &c)
{
    center = c;
}

void Pyramid::set_center(const double &x, const double &y, const double &z)
{
    center = Point3D(x, y, z);
}

bool Pyramid::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double min_t = kHugeValue;
    double cur_t;
    Ray cur_normal;
    bool hit = false;

    for (auto i = 0; i < SIDESNUM; i++)
    {
        if (planes[i].hit(ray, cur_t, cur_normal) && cur_t < min_t)
        {
            min_t = cur_t;
            normal = cur_normal;
            hit = true;
        }
    }
    if (bottom.hit(ray, cur_t, cur_normal) && cur_t < min_t)
    {
        min_t = cur_t;
        normal = cur_normal;
        hit = true;
    }

    if (hit)
        tmin = min_t;
    return hit;
}

void Pyramid::assign_planes()
{
    double pz = p0.z + side;
    double px = p0.x + side;
    planes.push_back(Triangle(top, p0, Point3D(p0.x, p0.y, pz)));
    planes.push_back(Triangle(top, Point3D(p0.x, p0.y, pz), Point3D(px, p0.y, pz)));
    planes.push_back(Triangle(top,  Point3D(px, p0.y, pz), Point3D(px, p0.y, p0.z)));
    planes.push_back(Triangle(top, Point3D(px, p0.y, p0.z), p0));
    bottom = Rectangle(p0, side, side, Vector3D(0, 1, 0));
}


