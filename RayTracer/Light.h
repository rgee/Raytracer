#ifndef LIGHT_H
#define LIGHT_H

#include "Vector3D.h"
#include "Color.h"

/* -----------------------------------------------
 * A light object, not very special at the moment.
 * -----------------------------------------------*/
class Light
{
public:
    Light() : position(Vector3()), color(Color()), intensity(0) { }
    Light(Vector3 pos, Color color, float intens) : position(pos), color(color), intensity(intens) { }
    ~Light() { };

    float GetIntensity() const { return intensity; }
    const Vector3& GetPosition() const { return position; }
private:
    Vector3 position;
    Color color;
    float intensity;
};

#endif