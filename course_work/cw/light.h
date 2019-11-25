#ifndef LIGHT_H
#define LIGHT_H

#include "rgbcolor.h"
#include "point3d.h"
#include "vector3d.h"

#define AMBIENT 0.4
class Light
{
public:
    Light();
    Light(const double &is, const RGBColor &c, const Point3D &pos);
    Light(Light &nl);

    Light operator= (Light &nl);

    Vector3D get_light_ray(const Point3D &P) const;
    RGBColor get_light(void) const;
    Point3D get_position(void) const;

    void set_intenity(double &is);
    void set_color(RGBColor &c);
    void set_position(Point3D &pos);


private:
    double intensity;
    RGBColor color;
    Point3D position;
};

#endif // LIGHT_H
