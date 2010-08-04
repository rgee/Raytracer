#include "RayTracer.h"


Color RayTracer::Trace(const Camera& cam, int x, int y) const
{ 
    /* Create a VERY primitive scene. Will be refactored out into its own
     * scene object soon */
    Sphere sphere = Sphere(400.0f, Vector3(),Vector3(200, 200, -500), Material(Color(15, 20, 200, 0)));
    Light light = Light(Vector3(0, 150, -200), Color(200.0f, 200.0f, 200.0f, 0), 0.6f);
    
    float u = (cam.GetWidth() * x) / cam.GetWidth();
    float v = (cam.GetHeight() * y) / cam.GetHeight();
    Vector3 dir = Vector3(x, y, 0) - cam.GetPosition();
    Ray viewRay = cam.GetViewRay(x, y);

    Intersection* hit = sphere.Intersect(viewRay);

    if(hit->GetParameter() != -1.0f) {

        /* Simple Lambert shading */
        Vector3 l =  hit->GetPosition() - light.GetPosition();
        return Color(16.0f, 34.0f, 167.0f, 0.0f) * light.GetIntensity() * std::max(0.0f, l.Normalize().Dot(hit->GetNormal().Normalize()));
    } else {
        return Color();
    }
}