#include "RayTracer.h"


Color sumColors(Color& l, Color& r) { return l + r;}

Color RayTracer::Trace(const Camera& cam, int x, int y) const
{ 
    /* Create a VERY primitive scene. Will be refactored out into its own
     * scene object soon */
    Sphere sphere = Sphere(400.0f, Vector3(),Vector3(100, 200, -500), Material(Color(15, 20, 200, 0)));

    
    float u = (cam.GetWidth() * x) / cam.GetWidth();
    float v = (cam.GetHeight() * y) / cam.GetHeight();
    Vector3 dir = Vector3(x, y, 0) - cam.GetPosition();
    Ray viewRay = cam.GetViewRay(x, y);

    Intersection* hit = sphere.Intersect(viewRay);

    if(hit->GetParameter() != -1.0f) {
        return CalculateLighting(Material(Color(16.0f, 34.0f, 167.0f, 0.0f)), hit, DIFFUSE);
    } else {
        return Color();
    }
}

Color RayTracer::CalculateLighting(Material& material, Intersection* hit, int lightType) const {
    if(lightType == DIFFUSE) {
        Color result;

        for(std::vector<Light>::const_iterator it = lights.begin(); it != lights.end(); ++it)
        {
            Vector3 l = hit->GetPosition() - (*it).GetPosition();
            result = result + material.diffuse_color * (*it).GetIntensity() * std::max(0.0f, l.Normalize().Dot(hit->GetNormal().Normalize()));
        }
        return result;
    }
}