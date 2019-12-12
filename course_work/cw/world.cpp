#include "world.h"
#include <iostream>
#include <thread>
#define THREADS_COUNT 4
World::World(int w, int h, int s = 1): canvas_height(h), canvas_width(w), pixel_size(s)
{
    data.background_color = BLACK;
    draw_widget = nullptr;
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

void one_ray(int x, int y, const Ray &ray, Tracer *tracer, MyPaintWidget *draw_widget,
             const WorldData &data)
{
    RGBColor pixel_color = tracer->trace_ray(ray, data);
    if (draw_widget)
    {
        draw_widget->color_pixel(x, y, pixel_color);
    }
}

void World::render(int zoom)
{
    RGBColor pixel_color;
    Ray ray;
    ray.origin = Point3D(0, 0, zoom);
    double x_coef = (canvas_width - 1.0) * 0.5;
    double y_coef = (canvas_height - 1.0) * 0.5;
    double r, c;
    std::vector <std::thread> working_threads;
    for (int x = 0; x <= canvas_width; x ++)
    {
        for (int y = 0; y <= canvas_height; y += THREADS_COUNT)
        {
            for (auto i = 0; i < THREADS_COUNT; i++)
            {
                r = pixel_size * (x - x_coef);
                c = pixel_size * (y + i - y_coef);
                ray.direction = Vector3D((r * vf.width) / canvas_width, (c * vf.height) / canvas_height, vf.d);
                ray.direction.normalize();

                std::thread th(one_ray, x, y + i, std::ref(ray), tracer, std::ref(draw_widget), data);
                working_threads.push_back(th);
            }
            for (auto i = 0; i < THREADS_COUNT; i++)
                working_threads[i].join();
            //pixel_color = tracer->trace_ray(ray, data);

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

