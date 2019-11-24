#include "material.h"

Material::Material(void)
{
    color = BLACK;
    diffuse_coef = 0.01; // чем меньше, тем больше "маттовость"
    reflect_coef = 0.20; //
    specular = 125; // чем меньше, тем больше блик
    refract_coef = 0.79;
    //eta = 1.0;
    eta = 1.0 / 1.42957113;
}

Material::Material(const RGBColor &c, double d, double g, int s, double r, double e)
{
    double tmp = d + g + r;
    if (tmp > 1.0)
    {
        d /= tmp;
        g /= tmp;
        r /= tmp;
    }
    color = c;
    diffuse_coef = d;
    reflect_coef = g;
    specular = s;
    refract_coef = r;
    eta = e;
}

Material::Material(double d, double g, int s, double r, double e)
{
    double tmp = d + g + r;
    if (tmp > 1.0)
    {
        d /= tmp;
        g /= tmp;
        r /= tmp;
    }
    color = BLACK;
    diffuse_coef = d;
    reflect_coef = g;
    specular = s;
    refract_coef = r;
    eta = e;
}

Material::Material(const Material &m)
{
    color = m.color;
    diffuse_coef = m.diffuse_coef;
    reflect_coef = m.reflect_coef;
    specular = m.specular;
    refract_coef = m.refract_coef;
    eta = m.eta;
}

Material &Material::operator=(const Material &m)
{
    if (this == &m)
        return (*this);
    color = m.color;
    diffuse_coef = m.diffuse_coef;
    reflect_coef = m.reflect_coef;
    specular = m.specular;
    refract_coef = m.refract_coef;
    eta = m.eta;
    return (*this);
}
