#ifndef DUMMYCAMERA_H
#define DUMMYCAMERA_H
#include "camera.h"

class DummyCamera : public Camera {
public:
    DummyCamera(const int _width, const int _height) : width(_width), height(_height) { }

    Ray makeWorldSpaceRay(int i, int j, int k, std::vector<std::vector<float> > samples) const;
private:
    const int width, height;
};

#endif // DUMMYCAMERA_H
