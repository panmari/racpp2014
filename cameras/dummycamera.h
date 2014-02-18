#ifndef DUMMYCAMERA_H
#define DUMMYCAMERA_H
#include "camera.h"

class DummyCamera : public Camera
{
public:
    DummyCamera(const int _width, const int _height) : width(_width), height(_height)
    {
    }
private:
    const int width, height;
};

#endif // DUMMYCAMERA_H
