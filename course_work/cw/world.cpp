#include "world.h"
#include <iostream>


World::World(int w, int h, int s = 1): canvas_height(h), canvas_width(w), pixel_size(s)
{
    data.background_color = BLACK;
    draw_widget = NULL;
    tracer = new Tracer();
}

World::~World()
{
    delete tracer;
}

void World::add_object(GeometricObject *obj)
{
    data.objects.push_back(obj);
}

void World::render(int zoom)
{
    RGBColor pixel_color;
    Ray ray;
    ray.origin = Point3D(0, 0, zoom);
    double x_coef = (canvas_width - 1.0) * 0.5;
    double y_coef = (canvas_height - 1.0) * 0.5;
    double r, c;
    for (int x = 0; x <= canvas_width; x++)
    {
        for (int y = 0; y <= canvas_height; y++)
        {
            r = pixel_size * (x - x_coef);
            c = pixel_size * (y - y_coef);
            ray.direction = Vector3D((r * vf.width) / canvas_width, (c * vf.height) / canvas_height, vf.d);
            ray.direction.normalize();
            pixel_color = tracer->trace_ray(ray, data);
            if (draw_widget)
            {
                draw_widget->color_pixel(x, y, pixel_color);
            }
        }
    }
    draw_widget->repaint();
}

void World::set_my_paint_widget(MyPaintWidget *dw)
{
    draw_widget = dw;
}

void World::remove_object(const int &index)
{
    data.objects.erase(data.objects.begin() + index);
}

void World::add_light(Light *item)
{
    data.lights.push_back(item);
}

void World::remove_light(const int &index)
{
    data.lights.erase(data.lights.begin() + index);
}

