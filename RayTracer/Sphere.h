#ifndef SPHERE_H
#define SPHERE_H

#include "Geometry.h"
#include "Intersection.h"

#include <math.h>
#include <limits>
#include <algorithm>

class Sphere : public Geometry
{
public:
    Sphere(float radius, Vector3& scale, Vector3& translate, Material& material)
        : radius(radius),
          Geometry(scale, translate, material)
    { }

    virtual Intersection* Intersect(const Ray& ray) const;

    float GetRadius() const { return radius; }
private:
    float radius;
};

#endif