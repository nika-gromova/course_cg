#include "tracer.h"
#include "geometricobject.h"
#include <iostream>
#include <math.h>

Tracer::Tracer(void) {}

Tracer::~Tracer() {}

Vector3D compute_reflected(const Vector3D &light_dir, const Vector3D &normal)
{
    Vector3D result;
    result = (normal * (2 * (light_dir * normal))) - light_dir;
    return result;
}

Vector3D compute_refracted(const Vector3D &light_dir, const Vector3D &normal, const double eta)
{
    Vector3D result;
    double cos_theta1 = - (light_dir * normal) / (light_dir.length());
    if (cos_theta1 < 0)
        return compute_refracted(light_dir, -normal, 1.0 / eta);

    double tmp = 1 - eta * eta * (1 - cos_theta1 * cos_theta1);
    if (tmp < 0)
    {
        result = Vector3D(0.0);
    }
    else
    {
        double betta = eta * cos_theta1 - sqrt(tmp);
        //if (betta > 0)
            //betta = -betta;
        result = ((light_dir * eta) + (normal * betta));
    }
    return result;
}

RGBColor Tracer::trace_ray(const Ray &ray, WorldData &data, int depth)
{
    double tmin = kHugeValue;
    int num_obj = data.objects.size();

    RGBColor local_color(0.0);
    RGBColor total_intensity(AMBIENT);
    RGBColor reflected_color(0.0);
    RGBColor refracted_color(0.0);

    Ray reflected;
    Ray refracted;

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
            hit = true;
            tmin = t;
            index_min = i;
        }
    }
    if (!hit)
    {
        return (data.background_color);
    }

    cur_obj = data.objects[index_min];
    intersect_point = ray.origin + (ray.direction * tmin);
    normal = cur_obj->calculate_normal(intersect_point);
    material_ptr = (cur_obj->get_material());

    total_intensity += compute_intensity(data, intersect_point, normal, -(ray.direction), material_ptr);
    local_color = (material_ptr->color * total_intensity);

    if (depth <= 0 || material_ptr->reflect_coef <= 0)
        return local_color;

    reflected.origin = intersect_point;
    reflected.direction = compute_reflected(-ray.direction, normal);
    reflected_color = this->trace_ray(reflected, data, depth - 1);
    reflected_color = (local_color + (reflected_color * material_ptr->reflect_coef));

    if (material_ptr->eta > 1 || material_ptr->refract_coef <= 0)
        return reflected_color;

    refracted.origin = intersect_point;
    refracted.direction = compute_refracted(ray.direction, normal, material_ptr->eta);
    if (!refracted.direction.is_null())
        refracted_color = this->trace_ray(refracted, data, depth - 1);

    return (reflected_color + (refracted_color * material_ptr->refract_coef));

}

RGBColor Tracer::compute_intensity(WorldData &data, const Point3D &intersect_point, const Vector3D &normal, const Vector3D &to_the_camera, const Material *material)
{
    std::vector<Light *> &lights = data.lights;

    RGBColor diffuse_intensity(0.0);
    RGBColor reflect_intensity(0.0);

    RGBColor current_intensity;

    Ray light_ray;

    Vector3D reflected;

    double cos_theta = 0.0;
    double cos_alpha = 0.0;

    double distance;
    double diffuse = material->diffuse_coef;
    double reflect = material->reflect_coef;

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
            diffuse_intensity += ((current_intensity * cos_theta) / (distance));

        // specular
        if (material->specular != -1)
        {
            reflected = compute_reflected(light_ray.direction, normal);
            cos_alpha = (reflected * to_the_camera);
            if (cos_alpha > 0.0)
                reflect_intensity += (current_intensity * pow(cos_alpha / (reflected.length() * to_the_camera.length()), material->specular));
        }
    }
    return ((diffuse_intensity * diffuse) + (reflect_intensity * reflect));
}
