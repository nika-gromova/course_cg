#include "rgbcolor.h"

RGBColor::RGBColor(void): r(0.0), g(0.0), b(0.0) {}

RGBColor::RGBColor(double value): r(value), g(value), b(value) {}

RGBColor::RGBColor(double nr, double ng, double nb): r(nr), g(ng), b(nb) {}

RGBColor::RGBColor(const RGBColor &color): r(color.r), g(color.g), b(color.b) {}

RGBColor::~RGBColor() {}

RGBColor &RGBColor::operator=(const RGBColor &color)
{
    if (this == &color)
        return (*this);
    r = color.r;
    g = color.g;
    b = color.b;
    return (*this);
}

RGBColor RGBColor::operator+(const RGBColor &color) const
{
    return RGBColor(r + color.r, g + color.g, b + color.b);
}

RGBColor &RGBColor::operator+=(const RGBColor &color)
{
    r += color.r;
    g += color.g;
    b += color.b;
    return (*this);
}

RGBColor RGBColor::operator*(const RGBColor &color) const
{
    return RGBColor(r * color.r, g * color.g, b * color.b);
}

RGBColor &RGBColor::operator*=(const RGBColor &color)
{
    r *= color.r;
    g *= color.g;
    b *= color.b;
    return (*this);
}

RGBColor RGBColor::operator*(const double a) const
{
    return RGBColor(r * a, g * a, b * a);
}

RGBColor &RGBColor::operator*=(const double a)
{
    r *= a;
    g *= a;
    b *= a;
    return (*this);
}

bool RGBColor::operator==(const RGBColor &color) const
{
    return (r == color.r && g == color.g && b == color.b);
}

double RGBColor::avg_color() const
{
    return (one_third * (r + g + b));
}
