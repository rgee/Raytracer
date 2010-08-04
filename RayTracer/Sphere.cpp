#include "Sphere.h"

Intersection* Sphere::Intersect(const Ray& ray) const
{
    Vector3 dst = ray.GetOrigin() - translation;
    float B = dst.Dot(ray.GetDirection());
    float C = dst.Dot(dst) - (radius * radius);
    float D = B*B - C;

    if(D < 0) {
        return new Intersection(Vector3(), Vector3(), material, 0, 0, -1);
    }

    float t = (-B - sqrt(D));

    if(t <= 0.00001) {
        return new Intersection(Vector3(), Vector3(), material, 0, 0, -1);
    }

    Vector3 point = (ray.GetOrigin() + ray.GetDirection() * t);
    Vector3 normal = (point - translation);

    return new Intersection(point, normal.Normalize(), material, 0, 0, t);
}