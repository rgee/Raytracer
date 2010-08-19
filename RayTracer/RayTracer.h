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
#include <limits>

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
        lights.push_back( Light(Vector3(30, 20, -25), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );
		lights.push_back( Light(Vector3(20, 10, -100), Color(255.0f, 255.0f, 255.0f, 0), 0.6f) );
		lights.push_back( Light(Vector3(10, -30, -25), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );

		objects.push_back(new Sphere(20.0f, Vector3(),Vector3(30, 0, -50),
			Material(Color(100.0f, 34.0f, 167.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150)));

		objects.push_back(new Sphere(20.0f, Vector3(),Vector3(-15, 0, -50),
			Material(Color(100.0f, 34.0f, 167.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150)));
    }
    Color Trace(const Camera& cam, int x, int y) const;
private:
    std::vector<Light> lights;
	std::vector<Geometry*> objects;
    Color CalculateLighting (const Camera& cam, Intersection* hit, int lightType = DIFFUSE) const;
};

#endif