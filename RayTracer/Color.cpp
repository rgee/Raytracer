#include "Color.h"

std::ostream& operator<<(std::ostream& os, Color output) 
{
    os << "(R: " << output.r << " G: " << output.g << " B: " << output.b << ")";
    return os;
}

Color& Color::operator=(const Color& rhs)
{
    if(this == &rhs) {
        return *this;
    }

    r = rhs.r;
    g = rhs.g;
    b = rhs.b;
    a = rhs.a;

    return *this;
}