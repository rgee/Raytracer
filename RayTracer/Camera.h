#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"
#include "Ray.h"
#include <math.h>

/* --------------------------------------------------------------------------
 * The camera encapsulates the logic behind looking at the screen and viewing
 * rays.
 * --------------------------------------------------------------------------*/
class Camera
{
public:
    Camera(Vector3 position, int width, int height)
        : position(position),
          width(width),
          height(height)
    {
            float PI = 3.14159265358979323846;
            fovx = PI / 4.0f;
            fovy = (float(height) / float(width)) * fovx;
	

			Vector3 dist = Vector3(0,0,0) - position;
			v = Vector3(0, 1, 0);
			w = dist.Normalize();
			u = w.Cross(v).Normalize();
			Vector3 dest = position + w * dist.Length();
			vw = dist.Length() *tan((PI / 4.0f)/2.0f);
			vh = vw * (height/ width);
			c = dest + (-u) * vw + (-v) * vh;
    }

    const Vector3& GetPosition() const { return position; }
    const int GetHeight() const { return height; }
    const int GetWidth() const { return width; }

    /* Returns a ray from the camera position pointing toward the (x, y) position
     * on the image plane. */
    Ray GetViewRay(float x, float y) const;
private:
    /* Horizontal and vertical field of view. */
    float fovy, fovx;

    /* Position of the camera. */
    Vector3 position;

	/* Orthonormal basis */
	Vector3 u, v, w;
	Vector3 c;

    /* Width of the screen to output to. */
    int width;

    /* Height of the screen to output to. */
    int height;

	float vh;
	float vw;
	float focalLength;
	
};

#endif