#include "point2d.h"

Point2D::Point2D(void): x(0.0), y(0.0) {}

Point2D::Point2D(const double nx, double ny): x(nx), y(ny) {}

Point2D::Point2D(const double value): x(value), y(value) {}

Point2D::Point2D(const Point2D &p): x(p.x), y(p.y) {}

Point2D::~Point2D() {}

Point2D &Point2D::operator=(const Point2D &p)
{
    if (this == &p)
        return (*this);
    x = p.x;
    y = p.y;
    return (*this);
}

Point2D Point2D::operator*(const double a) const
{
    return (Point2D(x * a, y * a));
}
