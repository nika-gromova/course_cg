#ifndef MATERIAL_H
#define MATERIAL_H

#include "rgbcolor.h"
#include "constants.h"
class Material
{
public:
    double diffuse_coef; // коэффициент диффузного отражения
    double reflect_coef; // коэффициент зеркального отражения
    int specular; // степень косинуса для блестящих поверхностей
    double refract_coef; // коэффициент пропускания
    double eta;
    RGBColor color;

public:
    Material(void);
    Material(const RGBColor &c, double d, double g, int s, double r, double e);
    Material(double d, double g, int s, double r, double e);
    Material(const Material& m);
    Material &operator= (const Material &m);
};

#endif // MATERIAL_H
