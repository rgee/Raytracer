#ifndef COLOR_H
#define COLOR_H

#include <iostream>

/* --------------------------------------------------------
 * Represents a color of the form (red, green, blue, alpha)
 * --------------------------------------------------------*/
class Color
{
public:
    float r;
    float g;
    float b;
    float a;

    Color() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) { }
    Color(float r, float g, float b, float a) :r(r), g(g), b(b), a(a) { }
    Color operator+(const Color& other) const
    {
        return Color(r + other.r, g + other.g, b + other.b, a);
    }
    Color operator*(float coeff) const
    {
        return Color(r*coeff, g*coeff, b*coeff, a);
    }

    Color& operator=(const Color& rhs);

    friend std::ostream& operator<<(std::ostream& os, Color output);

};


/*
static Color To8Bit(Color a)
{
    Color result;
    result.r = a.r * 255.0f;
    result.g = a.g * 255.0f;
    result.b = a.b * 255.0f;
    return result;
}

static Color ToArithmetic(Color a)
{
    Color result;
    result.r = a.r / 255.0f;
    result.g = a.g / 255.0f;
    result.b = a.b / 255.0f;
    return result;
}
*/


#endif