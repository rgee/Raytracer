#include "Ray.h"

std::ostream& operator<<(std::ostream& os, Ray output)
{
    os << "Origin: " << output.origin << "Direction: " << output.direction << std::endl;
    return os;
}