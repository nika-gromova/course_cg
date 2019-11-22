#include "light.h"
#include "constants.h"

Light::Light()
{
    intensity = 0.1;
    color = WHITE;
    position = Point3D(0, -10, 0);
}

Light::Light(double &is, RGBColor &c, Point3D &pos)
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

Vector3D Light::get_light_ray(Point3D &P)
{
    return (P - position);
}

RGBColor Light::get_light()
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
