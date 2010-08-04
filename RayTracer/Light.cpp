#include "Light.h"

Light& Light::operator=(const Light& rhs)
{
    if(this == &rhs)
        return *this;

    position = rhs.position;
    color = rhs.color;
    intensity = rhs.intensity;
    return *this;
}
