#ifndef CAMERA_H
#define CAMERA_H
#include "ray.h"
#include <vector>

/**
 * Given the specification of a ray in image space, a camera constructs
 * a corresponding ray in world space.
 */
class Camera
{
public:
    Camera();

    /**
     * Given a ray in image space, make a ray in world space according
     * to the camera specifications.
     *
     * @param i pixel column index
     * @param j pixel row index
     * @param k sample to be used to make the ray
     * @param samples array of n-dimensional samples. Use the first two dimensions
     * 		to sample the image plane. The samples are assumed to be in the range [0,1].
     * @return the ray in world coordinates
     */
    virtual Ray makeWorldSpaceRay(int i, int j, int k, std::vector<std::vector<float> > samples) const = 0;
};

#endif // CAMERA_H
