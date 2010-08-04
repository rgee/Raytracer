#ifndef SPHERE_H
#define SPHERE_H

#include "Geometry.h"
#include "Intersection.h"

#include <math.h>
#include <algorithm>

/* ---------------------
 * A sphere in the scene 
 * ---------------------*/
class Sphere : public Geometry
{
public:
    Sphere(float radius, Vector3& scale, Vector3& translate, Material& material)
        : radius(radius),
          Geometry(scale, translate, material)
    { }

    /* Intersect a ray with this sphere */
    virtual Intersection* Intersect(const Ray& ray) const;

    float GetRadius() const { return radius; }
private:

    /* The only special information we need is the radius. */
    float radius;
};

#endif