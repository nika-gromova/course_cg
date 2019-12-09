#include "cone.h"
const double kHugeValue	= 1.0E10;

Cone::Cone(void) : GeometricObject(), center(Point3D(0.0, 0.5, 0.0)), radius(1.0), height(1.0), k(1.0),
    hr(1.0), base(Disk(center, radius, Vector3D(0, 1, 0))) {}

Cone::Cone(const Point3D &cen, const double &r, const double &h) : GeometricObject(), center(cen), radius(r), height(h)
{
    k = radius * radius / height * height;
    hr = height / radius;
    base = Disk(center, r, Vector3D(0, 1, 0));
}

Cone::Cone(const Cone &c) : GeometricObject(), center(c.center), radius(c.radius), height(c.height),
    k(c.k), hr(c.hr), base(c.base) {}

Cone::~Cone() {}

Cone &Cone::operator=(const Cone &c)
{
    if (this == &c)
        return (*this);
    GeometricObject::operator =(c);

    center = c.center;
    radius = c.radius;
    height = c.height;
    k = c.k;
    hr = height / radius;
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
    k = radius * radius / height * height;
    hr = height / radius;
}

void Cone::set_height(const double &h)
{
    height = h;
    k = radius * radius / height * height;
    hr = height / radius;
}

bool Cone::hit(const Ray &ray, double &tmin, Ray &normal)
{
    double ox = ray.origin.x - center.x;
    double oz = ray.origin.z - center.z;
    double oy = ray.origin.y - center.y + height;
    double dx = ray.direction.x, dy = ray.direction.y, dz = ray.direction.z;
    double a = dx * dx - k * dy * dy + dz * dz;
    double b = 2 * (ox * dx - k * oy * dy + oz * dz);
    double c = ox * ox - k * oy * oy + oz * oz;

    tmin = kHugeValue;
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
               tmin = t1;
               normal.direction = this->calculate_normal(p);
               normal.origin = p;
               hit = true;
           }
       }
       if (!hit && t2 > KEps)
       {
           p = ray.origin + (ray.direction * t2);
           if (p.y <= center.y && p.y >= (center.y - height))
           {
               tmin = t2;
               normal.direction = this->calculate_normal(p);
               normal.origin = p;
               hit = true;
           }
       }
    }
    double cur_t;
    Ray cur_normal;
    if (base.hit(ray, cur_t, cur_normal) && cur_t < tmin)
    {
        tmin = cur_t;
        normal = cur_normal;
        hit = true;
    }

    return hit;
}

Vector3D Cone::calculate_normal(const Point3D &p)
{
    Vector3D normal = Vector3D(2 * (hr * p.x - center.x), (-2) * (p.y + height - center.y),
                               2 * (hr * p.z - center.z));
    return normal.get_normal();
}

