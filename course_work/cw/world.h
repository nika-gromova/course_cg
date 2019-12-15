#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "geometricobject.h"
#include "rgbcolor.h"
#include "viewfeild.h"
#include "tracer.h"
#include "mypaintwidget.h"
#include "worlddata.h"

struct thread_params
{
    int start;
    int end;
};


class World
{
public:
    MyPaintWidget *draw_widget;

    World(int w, int h, int s);
    ~World();

    void add_object(GeometricObject *obj);
    void render(int zoom);
    void set_my_paint_widget(MyPaintWidget *dw);

    void remove_object(const int &index);
    void add_light(Light *item);
    void remove_light(const int &index);
    void render_coloumns(World *w, thread_params p, int z);
    Tracer *tracer;

    int get_obj_size();

private:
    ViewFeild vf;
    int canvas_height;
    int canvas_width;
    int pixel_size;
    double x_coef;
    double y_coef;
    WorldData data;
};

#endif // WORLD_H
