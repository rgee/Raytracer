#include "Color.h"

std::ostream& operator<<(std::ostream& os, Color output) 
{
    os << "(R: " << output.r << " G: " << output.g << " B: " << output.b << ")";
    return os;
}