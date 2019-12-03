#include "sphere.h"
#include "maths.h"

const double Sphere::kEpsilon = 0.001;

Sphere::Sphere(void): GeometricObject(), center(0.0), radius(0.0) {}

Sphere::Sphere(const Point3D &c, double r): GeometricObject(), center(c), radius(r) {}

Sphere::Sphere(const Sphere &sp): GeometricObject(sp), center(sp.center), radius(sp.radius) {}

Sphere::~Sphere() {}

Sphere &Sphere::operator=(const Sphere &sp)
{
    if (this == &sp)
        return (*this);
    GeometricObject::operator =(sp);

    center = sp.center;
    radius = sp.radius;

    return (*this);
}

Sphere *Sphere::clone() const
{
    return (new Sphere(*this));
}

void Sphere::set_center(const Point3D &c)
{
    center = c;
}

void Sphere::set_center(double x, double y, double z)
{
    center.x = x;
    center.y = y;
    center.z = z;
}

void Sphere::set_radius(double r)
{
    radius = r;
}


bool Sphere::hit(const Ray &ray, double &tmin, Ray &normal)
{
    Vector3D OC = ray.origin - center;
    double a = ray.direction.squared_length();
    double b = 2 * (OC * ray.direction);
    double c = OC.squared_length() - radius * radius;
    double t1 = 0, t2 = 0;
    double params[3] = {a, b, c};
    int res = solve_quadric(t1, t2, params);
    if (!res)
        return false;
    else
    {
        // t1 - smaller; t2 - larger roots

        if (t1 > kEpsilon)
        {
            tmin = t1;
            normal.origin = ray.origin + (ray.direction * tmin);
            normal.direction = this->calculate_normal(normal.origin);
            return true;
        }
        if (t2 > kEpsilon)
        {
            tmin = t2;
            normal.origin = ray.origin + (ray.direction * tmin);
            normal.direction = this->calculate_normal(normal.origin);
            return true;
        }
    }
    return false;
}

Vector3D Sphere::calculate_normal(const Point3D &p)
{
    Vector3D PC = p - center;
    return (PC.get_normal());
}
