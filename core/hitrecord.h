
#ifndef HITRECORD_H
#define HITRECORD_H
#include "vector3f.h"
#include "intersectable.h"
#include "material.h"

/**
 * Stores information about a ray-surface intersection. This information
 * is typically used for shading.
 */
class HitRecord
{
public:
    HitRecord();

    /**
     * Hit position.
     */
    Vector3f position;

    /**
     * Normal at hit point.
     */
    Vector3f normal;

    /**
     * Tangent vectors at hit point.
     */
    Vector3f t1, t2;

    /**
     * Texture coordinates at hit point.
     */
    float u, v;

    /**
     * Direction towards origin of ray that hit surface. By convention it points away from
     * the surface, that is, in the direction opposite to the incident ray.
     */
    Vector3f w;

    /**
     * t parameter of the ray at the hit point.
     */
    float t;

    /**
     * The {@link Intersectable} that was hit.
     */
    Intersectable intersectable;

    /**
     * The material at the hit point.
     */
    Material material;

    HitRecord(float t, Vector3f position, Vector3f normal, Vector3f w, Intersectable intersectable, Material material, float u, float v);

    Vector3f getPositionVector()
    {
        return position;
    }
};

#endif // HITRECORD_H
