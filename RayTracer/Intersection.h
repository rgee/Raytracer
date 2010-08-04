#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "Material.h"
#include "Vector3D.h"

class Intersection
{
public:
    Intersection(Vector3 hitPos, Vector3 hitNorm, Material mat, float u, float v, float t)
        : hitPosition(hitPos),
          hitNormal(hitNorm),
          material(mat),
          u(u),
          v(v),
          t(t)
    { }

    ~Intersection();

    const Material& GetMaterial() const { return material; }
    const Vector3& GetPosition() const { return hitPosition; }
    const float GetParameter() const { return t; }
    const Vector3& GetNormal() const { return hitNormal; }
private:
    Vector3 hitPosition;
    Vector3 hitNormal;
    Material material;
    
    /* Texture coordinate */
    float u;
    
    /* Texture coordinate */
    float v;

    /* Ray parameter of the intersection */
    float t;
};

#endif