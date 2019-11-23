#ifndef RGBCOLOR_H
#define RGBCOLOR_H

#define one_third 0.333333333333

class RGBColor
{
public:
    double r, g, b;
public:
    RGBColor(void);
    RGBColor(double value);
    RGBColor(double nr, double ng, double nb);
    RGBColor(const RGBColor &color);

    ~RGBColor();

    RGBColor &operator= (const RGBColor &color);

    RGBColor operator+ (const RGBColor &color) const;
    RGBColor &operator+= (const RGBColor &color);
    RGBColor operator* (const RGBColor &color) const;
    RGBColor &operator*= (const RGBColor &color);
    RGBColor operator* (const double a) const;
    RGBColor &operator*= (const double a);
    RGBColor operator/ (const double a) const;
    RGBColor &operator/ (const double a);
    bool operator== (const RGBColor &color) const;
    double avg_color(void) const;
};
#endif // RGBCOLOR_H
