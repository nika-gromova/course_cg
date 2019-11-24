#include "rgbcolor.h"

#include "maths.h"

RGBColor::RGBColor(void): r(0.0), g(0.0), b(0.0) {}

RGBColor::RGBColor(double value)
{
    value = check_value(value);
    r = value;
    g = value;
    b = value;
}

RGBColor::RGBColor(double nr, double ng, double nb)
{
    nr = check_value(nr);
    ng = check_value(ng);
    nb = check_value(nb);
    r = nr;
    g = ng;
    b = nb;
}

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
    r = check_value(r);
    g *= a;
    g = check_value(g);
    b *= a;
    b = check_value(b);
    return (*this);
}

RGBColor RGBColor::operator/(const double a) const
{
    if (is_zero(a))
        return (RGBColor(1.0));
    return RGBColor(r / a, g / a, b / a);
}

RGBColor &RGBColor::operator/(const double a)
{
    if (is_zero(a))
    {
        r = 1;
        g = 1;
        b = 1;
    }
    else
    {
        r /= a;
        r = check_value(r);
        g /= a;
        g = check_value(g);
        b /= a;
        b = check_value(b);
    }
    return (*this);
}

bool RGBColor::operator==(const RGBColor &color) const
{
    return (is_zero(r - color.r) && is_zero(g - color.g) && is_zero(b - color.b));
}

double RGBColor::avg_color() const
{
    return (one_third * (r + g + b));
}
