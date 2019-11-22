#include "material.h"

Material::Material(void)
{
    color = BLACK;
    diffuse_coef = 0.2; // чем меньше, тем больше "маттовость"
    glossy_coef = 0.5;
    specular = 1;
    refraction_coef = 0.3;
}

Material::Material(const RGBColor &c, double d, double g, int s, double r)
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
    glossy_coef = g;
    specular = s;
    refraction_coef = r;
}

Material::Material(const Material &m)
{
    color = m.color;
    diffuse_coef = m.diffuse_coef;
    glossy_coef = m.glossy_coef;
    specular = m.specular;
    refraction_coef = m.refraction_coef;
}

Material &Material::operator=(const Material &m)
{
    if (this == &m)
        return (*this);
    color = m.color;
    diffuse_coef = m.diffuse_coef;
    glossy_coef = m.glossy_coef;
    specular = m.specular;
    refraction_coef = m.refraction_coef;
    return (*this);
}
