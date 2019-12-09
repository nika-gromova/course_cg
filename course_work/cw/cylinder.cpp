#include "cylinder.h"
#include "maths.h"

const double kHugeValue	= 1.0E10;

Cylinder::Cylinder(void) : GeometricObject(), center(Point3D(0.0, 0.5, 0.0)), height(1.0), radius(1.0)
{
    this->assign_bases();
}

Cylinder::Cylinder(const Point3D &cen, const double &h, const double &r) : GeometricObject(), center(cen), height(h), radius(r)
{
    this->assign_bases();
}

Cylinder::Cylinder(const Cylinder &c) : GeometricObject(), center(c.center), height(c.height), radius(c.radius)
{
    this->assign_bases();
}

Cylinder::~Cylinder() {}

Cylinder &Cylinder::operator=(const Cylinder &c)
{
    if (this == &c)
        return (*this);
    GeometricObject::operator =(c);

    center = c.center;
    height = c.height;
    radius = c.radius;
    this->assign_bases();

    return (*this);
}

void Cylinder::set_center(const Point3D &cen)
{
    center = cen;
}

void Cylinder::set_radius(const double &r)
{
    radius = r;
}

void Cylinder::set_height(const double &h)
{
    height = h;
}

bool Cylinder::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double ox = ray.origin.x - center.x;
    double oz = ray.origin.z - center.z;
    double a = ray.direction.x * ray.direction.x + ray.direction.z * ray.direction.z;
    double b = 2 * (ox * ray.direction.x + oz * ray.direction.z);
    double c = ox * ox + oz * oz - radius * radius;

    Ray local_normal;
    double min_t = kHugeValue;
    Point3D p;
    bool hit = false;

    double t1 = 0.0, t2 = 0.0;
    double params[3] = {a, b, c};
    int res = solve_quadric(t1, t2, params);

    if (res)
    {
        // t1 - smaller; t2 - larger roots

       if (t1 > KEps)
       {
           p = ray.origin + (ray.direction * t1);
           if (p.y <= center.y && p.y >= (center.y - height))
           {
               min_t = t1;
               local_normal.direction = (Vector3D(p.x - center.x, 0, p.z - center.z)).normalize();
               local_normal.origin = p;
               hit = true;
           }
       }
       if (!hit && t2 > KEps)
       {
           p = ray.origin + (ray.direction * t2);
           if (p.y <= center.y && p.y >= (center.y - height))
           {
               min_t = t2;
               local_normal.direction = (Vector3D(p.x - center.x, 0, p.z - center.z)).normalize();
               local_normal.origin = p;
               hit = true;
           }
       }
    }
    double cur_t;
    Ray cur_normal;
    for (auto i = 0; i < 2; i++)
    {
        if (bases[i].hit(ray, cur_t, cur_normal) && cur_t < min_t)
        {
            min_t = cur_t;
            local_normal = cur_normal;
            hit = true;
        }
    }

    if (hit)
    {
        tmin = min_t;
        normal = local_normal;
    }
    return hit;

}
void Cylinder::assign_bases()
{
    bases.push_back(Disk(center, radius, Vector3D(0.0, 1.0, 0.0)));
    bases.push_back(Disk(Point3D(center.x, center.y - height, center.z), radius, Vector3D(0.0, -1.0, 0.0)));
}
