#include "dummycamera.h"
using std::vector;

/**
 * Make a ray whose x- and y- coordinates in the direction vector are in the range [0,1] over the image plane.
 */
Ray DummyCamera::makeWorldSpaceRay(int i, int j, int k, vector<vector<float>> samples) const {
    float x = ((float)i+samples[k][0]) / (float)width;
    float y = ((float)j+samples[k][1]) / (float)height;
    return Ray(Vector3f(0.f,0.f,0.f), Vector3f(x, y, 1.f));
}
