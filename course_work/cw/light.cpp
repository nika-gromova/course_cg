#include "light.h"
#include "constants.h"

Light::Light()
{
    intensity = 0.1;
    color = WHITE;
    position = Point3D(0, -10, 0);
}

Light::Light(const double &is, const RGBColor &c, const Point3D &pos)
{
    intensity = is;
    color = c;
    position = pos;
}

Light::Light(Light &nl)
{
    intensity = nl.intensity;
    color = nl.color;
    position = nl.position;
}

Light Light::operator=(Light &nl)
{
    intensity = nl.intensity;
    color = nl.color;
    position = nl.position;
    return (*this);
}

Vector3D Light::get_light_ray(const Point3D &P) const
{
    return (position - P);
}

RGBColor Light::get_light() const
{
    return (color * intensity);
}

void Light::set_intenity(double &is)
{
    intensity = is;
}

void Light::set_color(RGBColor &c)
{
    color = c;
}

void Light::set_position(Point3D &pos)
{
    position = pos;
}
