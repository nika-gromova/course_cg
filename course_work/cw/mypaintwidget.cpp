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
    my_image.fill(QColor(Qt::white));
}

void MyPaintWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(0, 0, my_image);
}
