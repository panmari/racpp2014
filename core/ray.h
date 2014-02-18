#ifndef RAY_H
#define RAY_H
#include "vector3f.h"

/**
 * A ray represented by an origin and a direction.
 */
class Ray
{
public:    

    const Vector3f origin;
    const Vector3f direction;

    Ray(const Vector3f _origin, const Vector3f _direction) : origin(_origin), direction(_direction) {
    }

};

#endif // RAY_H
