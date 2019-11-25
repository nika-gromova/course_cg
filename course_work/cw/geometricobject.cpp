#include "geometricobject.h"

GeometricObject::GeometricObject(void)
{
    material_ptr = NULL;
}

GeometricObject::GeometricObject(const GeometricObject &obj)
{
    if (obj.material_ptr)
        material_ptr = obj.material_ptr;
    else
        material_ptr = NULL;
}

GeometricObject::~GeometricObject()
{
    if (material_ptr)
    {
        delete material_ptr;
        material_ptr = NULL;
    }
}

GeometricObject &GeometricObject::operator=(const GeometricObject &obj)
{
    if (this == &obj)
        return (*this);
    if (material_ptr)
    {
        delete material_ptr;
        material_ptr = NULL;
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
