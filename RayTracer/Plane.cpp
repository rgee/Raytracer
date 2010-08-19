#include "Plane.h"

Intersection* Plane::Intersect(const Ray& ray) const {
	float t = -(normal.Dot(ray.GetOrigin()) - normal.Dot(point)) / normal.Dot(ray.GetDirection());

	if(t >=  0.00001) {
		Vector3 hitPos = ray.GetOrigin() + (ray.GetDirection() * t);
		return new Intersection(hitPos, normal, (Geometry*)this, 0, 0, t);
	}

    return new Intersection(Vector3(), Vector3(), (Geometry*)this, 0, 0, -1);
}