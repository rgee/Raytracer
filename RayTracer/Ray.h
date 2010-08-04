#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"
#include <iostream>

class Ray
{
public:
    Ray() : origin(Vector3()), direction(Vector3()) { }
    Ray(Vector3 origin, Vector3 direction) : origin(origin), direction(direction) 
    {
        direction = direction.Normalize();
    }
    virtual ~Ray() {}

    inline void SetOrigin(Vector3& newOrigin) { origin = newOrigin; }
    inline void SetDirection(Vector3& newDirection) { direction = newDirection; }

    inline const Vector3& GetOrigin() const { return origin; }
    inline const Vector3& GetDirection() const { return direction; }
    friend std::ostream& operator<<(std::ostream& os, Ray output);
private:
    Vector3 origin, direction;
};

#endif