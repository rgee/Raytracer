#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include "Light.h"
#include "Camera.h"
#include <vector>
#include <algorithm>

enum
{
    DIFFUSE = 1,
    BLINN_PHONG
};

/* -----------------------------------------------------
 * Ray tracer object. Delegates calls to execute the ray
 * tracing algorithm
 * -----------------------------------------------------*/
class RayTracer
{
public:
    RayTracer() 
    {
        //lights.push_back( Light(Vector3(0, 150, -200), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );
        lights.push_back( Light(Vector3(0, 150, -200), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );
    }
    Color Trace(const Camera& cam, int x, int y) const;
private:
    std::vector<Light> lights;
    Color CalculateLighting (Material& material, Intersection* hit, int lightType = DIFFUSE) const;

};

#endif