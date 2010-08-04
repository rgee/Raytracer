#include "Sphere.h"

Intersection* Sphere::Intersect(const Ray& ray) const
{
    /* Quadratic equation */
    Vector3 dst = ray.GetOrigin() - translation;
    float B = dst.Dot(ray.GetDirection());
    float C = dst.Dot(dst) - (radius * radius);
    float D = B*B - C;

    /* Discriminant < 0, so we know the object does not intersect */
    if(D < 0) {
        return new Intersection(Vector3(), Vector3(), material, 0, 0, -1);
    }

    /* Right now we only care about where the ray /enters/ the sphere
     * float t2 = (-B + sqrt(D)) would give us its exit point. Will
     * compute later for refraction / transmission
     */
    float t = (-B - sqrt(D));

    /* Avoid intersecting with the near plane */
    if(t <= 0.00001) {
        return new Intersection(Vector3(), Vector3(), material, 0, 0, -1);
    }

    /* Intersection point */
    Vector3 point = (ray.GetOrigin() + ray.GetDirection() * t);

    /* Normal at the intersection point */
    Vector3 normal = (point - translation);

    return new Intersection(point, normal.Normalize(), material, 0, 0, t);
}