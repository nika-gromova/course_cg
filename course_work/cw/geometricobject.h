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

    virtual bool hit(const Ray &ray, double &tmin, Ray &normal) = 0;
    bool hit(const Ray &ray);
};

#endif // GEOMETRICOBJECT_H
