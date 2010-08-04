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

    Geometry(Material& material)
        : scale(Vector3()),
          translation(Vector3()),
          material(material)
    {}

    /* Intersect a ray with this object */
    virtual Intersection* Intersect(const Ray& ray) const { return (Intersection*)NULL; } 
protected:
    /* Scaling on the x, y and z axes. */
    Vector3 scale;

    /* How much to translate this  object from the origin.
     * i.e. Position */
    Vector3 translation;

    /* This objects material. */
    Material material;
};

#endif