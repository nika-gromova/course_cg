#include "geometricobject.h"

GeometricObject::GeometricObject(void)
{
    material_ptr = nullptr;
}

GeometricObject::GeometricObject(const GeometricObject &obj)
{
    if (obj.material_ptr)
        material_ptr = obj.material_ptr;
    else
        material_ptr = nullptr;
}

GeometricObject::~GeometricObject()
{
    if (material_ptr)
    {
        delete material_ptr;
        material_ptr = nullptr;
    }
}

GeometricObject &GeometricObject::operator=(const GeometricObject &obj)
{
    if (this == &obj)
        return (*this);
    if (material_ptr)
    {
        delete material_ptr;
        material_ptr = nullptr;
    }

    if (obj.material_ptr)
        material_ptr = obj.material_ptr;

    return (*this);
}

void GeometricObject::set_material(Material *m)
{
    material_ptr = m;
}

Material *GeometricObject::get_material() const
{
    return material_ptr;
}

bool GeometricObject::hit(const Ray &ray)
{
    double dummy1;
    Ray dummy2;
    return (this->hit(ray, dummy1, dummy2));
}
