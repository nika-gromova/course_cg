#ifndef LIGHT_H
#define LIGHT_H

#include "rgbcolor.h"
#include "point3d.h"
#include "vector3d.h"

class Light
{
public:
    Light();
    Light(double &is, RGBColor &c, Point3D &pos);
    Light(Light &nl);

    Light operator= (Light &nl);

    Vector3D get_light_ray(Point3D &P);
    RGBColor get_light(void);

    void set_intenity(double &is);
    void set_color(RGBColor &c);
    void set_position(Point3D &pos);


private:
    double intensity;
    RGBColor color;
    Point3D position;
};

#endif // LIGHT_H
