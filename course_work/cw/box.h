#ifndef BOX_H
#define BOX_H

#include "geometricobject.h"
// задается длиной, шириной, высотой и точкой в центре

class Box : public GeometricObject
{
public:
    Box(void);
    Box(const Point3D &c, const double &len, const double &w, const double &h);
    Box(const Point3D &c, const Point3D &ps, const Point3D &pe);
    Box(const Box &b);

    ~Box(void);

    void set_center(const Point3D &c);
    void set_center(const double &x, const double &y, const double &z);
    void set_sizes(const double &len, const double &w, const double &h);

    bool hit(const Ray &ray, double &tmin, Ray &normal);

private:
    Point3D center;
    // p0 - ближайший левый нижний угол, p1 - дальний правый верхний угол
    Point3D p0, p1;
};

#endif // BOX_H
