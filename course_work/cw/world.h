#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "geometricobject.h"
#include "rgbcolor.h"
#include "viewfeild.h"
#include "tracer.h"
#include "mypaintwidget.h"


class World
{
public:
    RGBColor back_ground_color;
    std::vector<GeometricObject *> objects;
    // std::vector<Light> lights;
public:
    World(int w, int h, int s);

    void add_object(GeometricObject *obj);
    void render(int zoom);
    void set_my_paint_widget(MyPaintWidget *dw);

    // void remove_object(const int &index); ???
    // void add_light(const Light &item);
    // void remove_light(const int &index);

    Tracer *tracer;
private:
    ViewFeild vf;
    int canvas_height;
    int canvas_width;
    int pixel_size;

    MyPaintWidget *draw_widget;
};

#endif // WORLD_H
