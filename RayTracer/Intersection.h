#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Geometry.h"
#include "Vector3D.h"

/* ----------------------------------------------------------------
 * Represents an intersection point. Holds various bits of data
 * necessary for evaluating an intersection of a ray with an object.
 *
 * An intersection with ray parameter -1 indicates a non-hit.
 * ----------------------------------------------------------------
 */
class Intersection
{
public:

    Intersection(Vector3 hitPos, Vector3 hitNorm, Geometry* geo, float u, float v, float t)
        : hitPosition(hitPos),
          hitNormal(hitNorm),
		  object(geo),
          u(u),
          v(v),
          t(t)
    { }

	Intersection()
		: hitPosition(Vector3() ),
		  hitNormal(Vector3() ),
		  t(-1.0f)
	{ }

    ~Intersection();
	const Geometry* GetObject() const { return object; }
    const Vector3& GetPosition() const { return hitPosition; }
    const float GetParameter() const { return t; }
    const Vector3& GetNormal() const { return hitNormal; }
private:
    Vector3 hitPosition;
    Vector3 hitNormal;

	/* The object intersected. Use pointer here because a
	   world object could hold resources like file handles, 
	   mesh data, etc. We don't want copies of that. */
    Geometry* object;
    
    /* Texture coordinate */
    float u;
    
    /* Texture coordinate */
    float v;

    /* Ray parameter of the intersection */
    float t;
};

#endif