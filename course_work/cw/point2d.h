#ifndef POINT2D_H
#define POINT2D_H


class Point2D
{
public:
    double x, y;
public:
    Point2D(void);
    Point2D(const double nx, double ny);
    Point2D(const double value);
    Point2D(const Point2D &p);
    ~Point2D();

    Point2D &operator= (const Point2D &p);
    Point2D operator* (const double a) const;
};

#endif // POINT2D_H
