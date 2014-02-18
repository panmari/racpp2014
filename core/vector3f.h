#ifndef VECTOR3F_H
#define VECTOR3F_H
#include <boost/numeric/ublas/vector.hpp>

class Vector3f : public boost::numeric::ublas::vector<float>
{
public:

    Vector3f(): vector(3) {
        Vector3f(0, 0, 0);
    }

    Vector3f(float x, float y, float z): vector(3) {
        data ()[0] = x;
        data ()[1] = y;
        data ()[2] = z;
    }
};

#endif // VECTOR3F_H
