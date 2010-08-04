#ifndef CAMERA_H
#define CAMERA_H

#include "Vector3D.h"
#include "Ray.h"
#include <math.h>

class Camera
{
public:
    Camera(float focalLength, Vector3 position, Vector3 up, Vector3 lookAt, int width, int height, float fov)
        : focalLength(focalLength),
          position(position),
          up(up),
          lookAt(lookAt),
          width(width),
          height(height),
          fov(fov)
    {
            float PI = 3.14159265358979323846;
            fovx = PI / 4.0f;
            fovy = (float(height) / float(width)) * fovx;
    }

    const Vector3& GetPosition() const { return position; }
    const Vector3& GetUp() const { return up; }
    const Vector3& GetLook() const { return lookAt; }
    const float GetFocalLength() const { return focalLength; }
    const int GetHeight() const { return height; }
    const int GetWidth() const { return width; }
    Ray GetViewRay(int x, int y) const;
private:
    float focalLength;
    float fov;
    float fovy, fovx;
    Vector3 position;
    Vector3 up;
    Vector3 lookAt;
    int width;
    int height;
};

#endif