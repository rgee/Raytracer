#include "RayTracer.h"


Color sumColors(Color& l, Color& r) { return l + r;}

Color RayTracer::Trace(const Camera& cam, int x, int y) const
{ 
    /* Create a VERY primitive scene. Will be refactored out into its own
     * scene object soon */
    //Sphere sphere = Sphere(20.0f, Vector3(),Vector3(30, 0, -50), Material(Color(100.0f, 34.0f, 167.0f, 0.0f), Color(255.0f, 255.0f, 255.0f, 0.0f), 1.0f, 150));

    
    float u = (cam.GetWidth() * x) / cam.GetWidth();
    float v = (cam.GetHeight() * y) / cam.GetHeight();
    Vector3 dir = Vector3(x, y, 0) - cam.GetPosition();
    Ray viewRay = cam.GetViewRay(x, y);

	float nearestT = std::numeric_limits<float>::max();
	Intersection* hit = new Intersection();
	Intersection* intermediate;

	for(std::vector<Geometry*>::const_iterator it = objects.begin(); it != objects.end(); it++)
	{
		intermediate = (*it)->Intersect(viewRay);
		if( intermediate->GetParameter() < nearestT && (intermediate->GetParameter() != -1.0f) )
		{
			hit = intermediate;
			nearestT = intermediate->GetParameter();
		}
	}
	if(hit->GetParameter() != -1.0f) {
		Material material = hit->GetObject()->GetMaterial();
		Color result;
		if(shader == DIFFUSE) {
			for(std::vector<Light>::const_iterator it = lights.begin(); it != lights.end(); ++it)
			{
				Vector3 l = hit->GetPosition() - (*it).GetPosition();
				result = result +  material.diffuse_color * (*it).GetIntensity() * std::max(0.0f, l.Normalize().Dot(hit->GetNormal().Normalize()));
			}
		} else if(shader == BLINN_PHONG) {
			Vector3 v = hit->GetPosition() + cam.GetPosition().Normalize();
			for(std::vector<Light>::const_iterator it = lights.begin(); it != lights.end(); ++it)
			{
				Intersection* shadowHit = new Intersection();
				Intersection* intermediate;
				Color ambientLight = 0.02f * Color(255.0f, 255.0f, 255.0f, 0.0f);


				// Send intersect a ray from the hit position to the current light source.
				for(std::vector<Geometry*>::const_iterator its = objects.begin(); its != objects.end(); its++)
				{
					Ray shadowRay = Ray(  hit->GetPosition() + (0.01f * (*it).GetPosition()) , (hit->GetPosition() + (*it).GetPosition()).Normalize() );

					intermediate = (*its)->Intersect(shadowRay);

					if(intermediate->GetParameter() != -1.0f)
					{
						shadowHit = intermediate;
						break;
					}
				}

				// If it successfully hits an object, the the hit point is in shadow, so we
				// ignore the current light's BRDF contribution and just take ambient light.
				if(shadowHit->GetParameter() != -1.0f)
				{
					result = result + ambientLight;
				} 
				else
				{
					Vector3 l = hit->GetPosition() - (*it).GetPosition();
					Vector3 h = (v + l).Normalize();


					Color diffuse_component = ambientLight + material.diffuse_color * (*it).GetIntensity() * std::max(0.0f, l.Normalize().Dot(hit->GetNormal().Normalize()));
					Color specular_component = material.specular_color * (*it).GetIntensity() * pow(std::max(0.0f, h.Dot(hit->GetNormal().Normalize())), material.specular_power);
					result = result + diffuse_component + specular_component;
				}
			}
			result.Clamp(0.0f, 255.0f);
		}

		return result;


    } else {
        return Color();
    }
}