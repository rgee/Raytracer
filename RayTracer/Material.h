#ifndef MATERIAL_H
#define MATERIAL_H

#include"Color.h"

/* -------------------------------------------------------------------
 * Material objects hold data about the material of a geometric object
 * in the scene.
 * -------------------------------------------------------------------*/
class Material
{
public:
    Material(Color diffuse)
        : transparency(0),
          specular_power(1),
          specular_color(Color()),
          diffuse_color(diffuse)
    { }


	Material(Color diffuse, Color specular, float transparency, int specular_power)
		: diffuse_color(diffuse),
		  specular_color(specular),
		  specular_power(specular_power),
		  transparency(transparency)
	{ }


    Material& operator=(Material& rhs);

    float transparency;
	int specular_power;
    Color diffuse_color;
    Color specular_color;
};

#endif