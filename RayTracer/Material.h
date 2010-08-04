#ifndef MATERIAL_H
#define MATERIAL_H

#include"Color.h"

struct Material
{
    Material(Color diffuse)
        : glossiness(0),
          transparency(0),
          refraction(0),
          reflection(0),
          specular(0),
          specular_color(Color())
    { }
    float glossiness;
    float transparency;
    float refraction;
    float reflection;
    float specular;
    Color diffuse_color;
    Color specular_color;
};

#endif