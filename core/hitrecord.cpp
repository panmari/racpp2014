#include "hitrecord.h"

HitRecord::HitRecord(float t, Vector3f position, Vector3f normal, Vector3f w, Intersectable &intersectable, Material &material, float u, float v)
{
    this->t = t;
    this->position = position;
    this->normal = normal;
    this->w = w;
    this->intersectable = &intersectable;
    this->material = &material;
    this->u = u;
    this->v = v;

    // Make tangent frame: t1, t2, normal is a right handed frame
    t1 = Vector3f(1,0,0);
    t1.cross(t1, normal);
    if(t1.length()==0)
    {
        t1 = Vector3f(0,1,0);
        t1.cross(t1, normal);
    }
    t1.normalize();
    t2 = Vector3f();
    t2.cross(normal, t1);
}
