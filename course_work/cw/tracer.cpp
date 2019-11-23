#include "tracer.h"
#include "geometricobject.h"
#include <iostream>
#include <math.h>

Tracer::Tracer(void) {}

Tracer::~Tracer() {}

Vector3D compute_reflected(const Ray &light_ray, const Vector3D &normal)
{
    Vector3D result;
    Vector3D norm_light = (light_ray.direction.get_normal());
    result = (normal * (2 * (norm_light * normal))) - norm_light;
    return result;
}


RGBColor Tracer::trace_ray(const Ray &ray, WorldData &data, int depth)
{
    double tmin = kHugeValue;
    int num_obj = data.objects.size();

    GeometricObject *cur_obj;
    Material *material_ptr;

    double t = 0.0;
    int index_min = 0;
    Point3D intersect_point;
    Vector3D normal;
    bool hit = false;

    for (int i = 0; i < num_obj; i++)
    {
        cur_obj = data.objects[i];
        if (cur_obj->hit(ray, t))
        {
            std::cout << "here1\n";
            if (t < tmin)
            {
                std::cout << "here2\n";
                hit = true;
                tmin = t;
                index_min = i;
            }
        }
    }
    if (hit)
    {
        cur_obj = data.objects[index_min];
        intersect_point = ray.origin + (ray.direction * tmin);
        normal = cur_obj->calculate_normal(intersect_point);
        material_ptr = (cur_obj->get_material());
        RGBColor intensity = compute_intensity(data, intersect_point, normal, -(ray.direction), material_ptr, depth);
        return (material_ptr->color * intensity);
    }
    else
        return (data.background_color);
}

RGBColor Tracer::compute_intensity(WorldData &data, const Point3D &intersect_point, const Vector3D &normal, const Vector3D &to_the_camera, const Material *material, int depth)
{
    std::vector<Light *> &lights = data.lights;
    RGBColor total_intensity(AMBIENT);
    RGBColor current_intensity;

    Ray light_ray;

    Vector3D reflected;
    Ray reflected_ray;
    double cos_theta = 0.0;
    double cos_alpha = 0.0;

    double distance;

    double dummy;
    bool shadow = false;

    for (auto const &light : lights)
    {
        light_ray.direction = light->get_light_ray(intersect_point);
        light_ray.origin = intersect_point;
        distance = light_ray.direction.length();
        current_intensity = light->get_light();

        for (auto const &obj : data.objects)
            shadow = shadow || (obj->hit(light_ray, dummy));
        if (shadow)
            continue;

        // diffuse
        cos_theta = (light_ray.direction * normal);
        if (cos_theta > 0.0)
            total_intensity += ((current_intensity * cos_theta * material->diffuse_coef) / (distance));

        // specular
        if (material->specular != -1)
        {
            reflected = compute_reflected(light_ray, normal);
            cos_alpha = (reflected * to_the_camera);
            if (cos_alpha > 0.0)
                total_intensity += (current_intensity * material->diffuse_coef * pow(cos_alpha / (reflected.length() * to_the_camera.length()), material->specular));
        }

        if (material->refraction_coef > 0 || depth > 0)
        {
            reflected_ray.origin = intersect_point;
            reflected_ray.direction = reflected;
            RGBColor additional = this->trace_ray(reflected_ray, data, depth - 1);
            std::cout << "reflected:\n" << additional.r << ", " << additional.g << ", " << additional.b << std::endl;
            total_intensity += additional;
        }
    }
    return total_intensity;
}
