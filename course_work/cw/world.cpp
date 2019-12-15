#include "world.h"
#include <thread>
#include <mutex>


#define THREADS_COUNT 4

std::mutex mtx;
std::vector<std::thread> threads(THREADS_COUNT);

World::World(int w, int h, int s = 1): canvas_height(h), canvas_width(w), pixel_size(s)
{
    data.background_color = BLACK;
    draw_widget = nullptr;
    tracer = new Tracer();
    canvas_width--;
    canvas_height--;
    x_coef = (canvas_width - 1.0) * 0.5;
    y_coef = (canvas_height - 1.0) * 0.5;
}

World::~World()
{
    delete tracer;
}

/*
void World::render(int zoom)
{
    Ray ray;
    ray.origin = Point3D(0, 0, zoom);
    RGBColor pixel_color;
    double r, c;
    for (int x = 0; x <= canvas_width; x++ )
    {
        for (int y = 0; y <= canvas_height; y++ )
        {
            r = pixel_size * (x - x_coef);
            c = pixel_size * (y - y_coef);
            ray.direction = Vector3D((r * vf.width) / canvas_width, (c * vf.height) / canvas_height, vf.d);
            ray.direction.normalize();
            pixel_color = tracer->trace_ray(ray, data);
            if (draw_widget)
                draw_widget->color_pixel(x, y, pixel_color);
        }
    }
    draw_widget->repaint();
}
*/


void World::render(int zoom)
{
    int start = 0;
    int end = 0;
    double dcw = canvas_width;
    double pstep = dcw / THREADS_COUNT;
    int step = round(pstep);
    thread_params params;

    for (auto i = 0; i < THREADS_COUNT; i++)
    {
        end = start + step;
        params.start = start;
        params.end = end;
        threads[i] = std::thread(&World::render_coloumns, this, this, params, zoom);
        start += step;
    }
    for (auto i = 0; i < THREADS_COUNT; i++)
    {
        threads[i].join();
    }

    draw_widget->repaint();
}


void World::set_my_paint_widget(MyPaintWidget *dw)
{
    draw_widget = dw;
}


void World::add_object(GeometricObject *obj)
{
    data.objects.push_back(obj);
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

void World::render_coloumns(World *w, thread_params p, int z)
{
    Ray ray;
    ray.origin = Point3D(0, 0, z);
    RGBColor pixel_color;
    double r, c;
    for (int x = p.start; x < p.end; x++ )
    {
        for (int y = 0; y <= w->canvas_height; y++ )
        {
            r = w->pixel_size * (x - w->x_coef);
            c = w->pixel_size * (y - w->y_coef);
            ray.direction = Vector3D((r * w->vf.width) / w->canvas_width, (c * w->vf.height) / w->canvas_height, w->vf.d);
            ray.direction.normalize();
            pixel_color = w->tracer->trace_ray(ray, data);
            if (w->draw_widget)
                w->draw_widget->color_pixel(x, y, pixel_color);
        }
    }
}

int World::get_obj_size()
{
    return data.objects.size();
}

