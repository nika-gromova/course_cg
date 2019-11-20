#ifndef GEOMETRICOBJECT_H
#define GEOMETRICOBJECT_H

#include "material.h"
#include "point3d.h"
#include "vector3d.h"
#include "ray.h"

class GeometricObject
{
private:
    Material *material_ptr;
public:
    GeometricObject(void);
    GeometricObject(const GeometricObject& obj);
    virtual ~GeometricObject(void);

    GeometricObject &operator= (const GeometricObject& obj);
    virtual GeometricObject* clone(void) const = 0;

    void set_material(Material *m);
    Material* get_material(void) const;
    virtual double get_data() = 0;

    virtual Vector3D calculate_normal(const Point3D &p) = 0;
    virtual bool hit(const Ray &ray, double &tmin) = 0;
};

#endif // GEOMETRICOBJECT_H
