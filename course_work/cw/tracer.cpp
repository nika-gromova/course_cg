#include "tracer.h"
#include "geometricobject.h"
#include <iostream>

Tracer::Tracer(void) {}

Tracer::~Tracer() {}

RGBColor compute_intensity(std::vector<Light *> &lights, const Point3D &intersect_point, const Vector3D &normal, const Vector3D &to_the_camera, const Material *material)
{
    RGBColor total_intensity(AMBIENT);
    double cos_theta = 0.0;
    Vector3D light_ray;
    for (auto const &light : lights)
    {
        light_ray = light->get_light_ray(intersect_point);
        cos_theta = (light_ray * normal);
        if (cos_theta > 0.0)
            total_intensity += ((light->get_light() * cos_theta * material->diffuse_coef) * (1 / (light_ray.length() + normal.length())));
    }
    return total_intensity;
}




RGBColor Tracer::trace_ray(const Ray &ray, WorldData &data)
{
    double tmin = kHugeValue;
    int num_obj = data.objects.size();

    GeometricObject *cur_obj;
    Material *material_ptr;

    double t;
    int index_min = 0;
    Point3D intersect_point;
    Vector3D normal;
    bool hit = false;

    for (int i = 0; i < num_obj; i++)
    {
        cur_obj = data.objects[i];
        if (cur_obj->hit(ray, t) && (t < tmin))
        {
            hit = true;
            tmin = t;
            index_min = i;
         }
    }
    if (hit)
    {
        cur_obj = data.objects[index_min];
        intersect_point = ray.origin + (ray.direction * tmin);
        normal = cur_obj->calculate_normal(intersect_point);
        material_ptr = (cur_obj->get_material());
        return (material_ptr->color * compute_intensity(data.lights, intersect_point, normal, -(ray.direction), material_ptr));
    }
    else
        return (data.background_color);
}

RGBColor Tracer::trace_ray(const Ray &ray, WorldData &data, int depth)
{

}

