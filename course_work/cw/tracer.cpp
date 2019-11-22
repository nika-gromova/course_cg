#include "tracer.h"
#include "geometricobject.h"
#include <iostream>

Tracer::Tracer(void) {}

Tracer::~Tracer() {}

RGBColor Tracer::trace_ray(const Ray &ray, WorldData &data)
{
    double tmin = kHugeValue;
    int num_obj = data.objects.size();
    GeometricObject *cur_obj;

    Material *material_ptr;

    double t;
    bool hit = false;

    for (int i = 0; i < num_obj; i++)
    {
        cur_obj = data.objects[i];
        if (cur_obj->hit(ray, t) && (t < tmin))
        {
            // std::cout << ray.origin.x << ";" << ray.origin.y << ": t - " << t << " " << "tmin - " << tmin << std::endl;
            hit = true;
            tmin = t;
            material_ptr = (cur_obj->get_material());
         }
    }
    if (hit)
        return (material_ptr->color);
    else
        return (data.background_color);
}

RGBColor Tracer::trace_ray(const Ray &ray, WorldData &data, int depth)
{

}
