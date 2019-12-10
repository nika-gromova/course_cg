#ifndef MYPAINTWIDGET_H
#define MYPAINTWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include "rgbcolor.h"

class MyPaintWidget : public QWidget
{
    Q_OBJECT

private:
    QImage my_image;
public:
    explicit MyPaintWidget(QWidget *parent = nullptr);
    void color_pixel(int x, int y, RGBColor &color);
    void set_Qimage(int width, int height);
    void draw_line(int x1, int y1, int x2, int y2);

signals:

public slots:
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // MYPAINTWIDGET_H
