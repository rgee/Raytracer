#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <iostream>
#include "Color.h"
#include "Ray.h"
#include "Sphere.h"
#include "Plane.h"
#include "Light.h"
#include "Camera.h"
#include <vector>
#include <algorithm>
#include <limits>

typedef enum ShadingModel
{
    DIFFUSE = 1,
    BLINN_PHONG
} ShadingModel;

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
		//lights.push_back( Light(Vector3(20, 10, -100), Color(255.0f, 255.0f, 255.0f, 0), 0.6f) );
		//lights.push_back( Light(Vector3(10, -30, -25), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );
		lights.push_back( Light(Vector3(-10, -30, -400), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );
		lights.push_back( Light(Vector3(30, -30, -50), Color(200.0f, 200.0f, 200.0f, 0), 0.6f) );

		objects.push_back(new Sphere(20.0f, Vector3(),Vector3(30, -5, -50),
			Material(Color(20.0f, 34.0f, 167.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150)));

		objects.push_back(new Sphere(10.0f, Vector3(),Vector3(-15, 10, -50),
			Material(Color(200.0f, 34.0f, 20.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150)));

		objects.push_back(new Sphere(10.0f, Vector3(),Vector3(0, 10, -500),
			Material(Color(100.0f, 34.0f, 167.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150)));

		objects.push_back(new Plane(Vector3(0, 20, 0), Vector3(0, 1, 0),
			Material(Color(100.0f, 34.0f, 167.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150)));

		shader = BLINN_PHONG;
	}
    Color Trace(const Camera& cam, int x, int y) const;
private:
	// Lights in the scene
    std::vector<Light> lights;

	// Geometry in the scene
	std::vector<Geometry*> objects;

	// The type of shading we're using
	ShadingModel shader;
	Intersection* IntersectScene(Ray& ray) const;
};

#endif