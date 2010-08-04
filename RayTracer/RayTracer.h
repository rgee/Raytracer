#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include <algorithm>

class RayTracer
{
public:
    RayTracer() { }
    Color Trace(const Camera& cam, int x, int y) const;
};

#endif