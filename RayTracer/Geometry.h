#ifndef GEOMETRY_H
#define GEOMETRY_H


#include "Material.h"
#include "Intersection.h"
#include "Ray.h"

/* --------------------------------
 * Interface for geometry obejects.
 * --------------------------------*/
class Geometry
{
public:
    Geometry(Vector3& scale, Vector3& translation, Material& material)
        : scale(scale),
          translation(translation),
          material(material)
    {}

    /* Intersect a ray with this object */
    virtual Intersection* Intersect(Ray& ray) { return (Intersection*)NULL; } 
protected:
    Vector3 scale;
    Vector3 translation;
    Material material;
};

#endif