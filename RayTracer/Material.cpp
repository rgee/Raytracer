#include "Material.h"

Material& Material::operator=(Material& rhs)
{
    if(this != &rhs)
    {
        float glossiness = rhs.glossiness;
        float transparency = rhs.transparency;
        float refraction = rhs.refraction;
        float reflection = rhs.reflection;
        float specular = rhs.specular;
        Color diffuse_color = rhs.diffuse_color;
        Color specular_color = rhs.specular_color;
    }
    return *this;
}