#include "dummycamera.h"

/**
 * Make a ray whose x- and y- coordinates in the direction vector are in the range [0,1] over the image plane.
 */
Ray DummyCamera::makeWorldSpaceRay(int i, int j, int k, vector<vector<float>> samples) {
    float x = ((float)i+samples[k][0]) / (float)width;
    float y = ((float)j+samples[k][1]) / (float)height;
    return new Ray(Vector3f(0.f,0.f,0.f), Vector3f(x, y, 1.f));
}
