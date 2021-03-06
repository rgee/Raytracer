#include "Camera.h"

Ray Camera::GetViewRay(float x, float y) const
{
    float viewPlaneX = ( ((2.0f * float(x) - 0.5f) - float(width)) /float(width) ) * tan(fovx);
    float viewPlaneY = ( ((2.0f * float(y) - 0.5f) - float(height)) /float(height) ) * tan(fovy);

	return Ray(position, Vector3(viewPlaneX, viewPlaneY, -1.0f).Normalize());
}