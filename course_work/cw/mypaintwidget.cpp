#include "mypaintwidget.h"
#include <cmath>
MyPaintWidget::MyPaintWidget(QWidget *parent) : QWidget(parent)
{
}

void MyPaintWidget::color_pixel(int x, int y, RGBColor &color)
{
    QColor cur_color(static_cast<int>(round(color.r * 255)), static_cast<int>(round(color.g * 255)), static_cast<int>(round(color.b * 255)));
    QPainter painter(&my_image);
    painter.setPen(cur_color);
    painter.drawPoint(x, y);
}

void MyPaintWidget::set_Qimage(int width, int height)
{
    my_image = QImage(width, height, QImage::Format_RGB32);
    my_image.fill(QColor(Qt::black));
}

void MyPaintWidget::draw_line(int x1, int y1, int x2, int y2)
{
    QPainter painter(&my_image);
    painter.setPen(Qt::white);
    painter.drawLine(x1, y1, x2, y2);
    painter.drawEllipse(x2 - 2, y2 - 2, 4, 4);
}

void MyPaintWidget::paintEvent(QPaintEvent *event)
{
    /*
    int x1 = 10;
    int x2 = 110;
    int y1 = 10;
    int y2 = y1 + 100;
    draw_line(x1, y1, x2, y1);
    draw_line(x1, y1, x1, y2);
    draw_line(x1, y1, x1 + x1 / 2, y1 - y1 / 2);*/
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}
