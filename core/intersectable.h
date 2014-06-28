#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H
#include "ray.h"
class HitRecord;

/**
 * An intersectable supports ray-surface intersection.
 */
class Intersectable
{
public:
    /**
     * Implement ray-surface intersection in this method.
     *
     * @param r the ray used for intersection testing
     * @return a hit record, should return null if there is no intersection
     */
    virtual HitRecord intersect(Ray r) = 0;
};

#endif // INTERSECTABLE_H
