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

    template <typename T>
    Vector3f(T const& o) {
      for (int i = 0; i < 3; i++) {
        data()[i] = o[i];
      }
    }
    float x() const { data ()[0]; }
    float y() const { data ()[1]; }
    float z() const { data ()[1]; }
    float operator[](int i) const { data ()[i]; }
    Vector3f& operator+=(Vector3f const& other);
    Vector3f operator+(Vector3f const& other);

    Vector3f cross(Vector3f const& other) const;
    void cross(Vector3f const& other, Vector3f& result) const;
    float dot(Vector3f const& other) {
      return x() * other.x() + y() * other.y() + z() * other.z();
    }
    float length() const {
      return std::sqrt(x() * x() + y() * y() + z() * z());
    }
    void normalize() {
      *this *= 1/length();
    }
};

#endif // VECTOR3F_H
