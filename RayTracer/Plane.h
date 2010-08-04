#ifndef PLANE_H
#define PLANE_H

#include "Geometry.h"
#include "Intersection.h"
#include <math.h>

class Plane : public Geometry
{
public:
    Plane(Vector3 point, Vector3 normal, Material material)
        : point(point),
          normal(normal),
          Geometry(material)
    {}

    virtual Intersection* Intersect(const Ray& ray) const;

    const Vector3& GetNormal() const { return normal; }

private:
    /* Any point in this plane */
    Vector3 point;

    /* Normal vector of the plane */
    Vector3 normal;
};

#endif