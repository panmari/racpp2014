#include "vector3f.h"

Vector3f& Vector3f::operator+=(Vector3f const& other) {
  data()[0] += other.x();
  data()[1] += other.y();
  data()[2] += other.z();
}

Vector3f Vector3f::operator+(Vector3f const& other) {
  Vector3f n(*this);
  n += other;
  return n;
}

Vector3f Vector3f::cross(Vector3f const& other) const {
  Vector3f v;
  cross(other, v);
  return v;
}
void Vector3f::cross(Vector3f const& other, Vector3f& result) const {
  result.data() [0] = y() * other.z() - other.y() * z();
  result.data() [1] = - x() * other.z() + other.x() * z();
  result.data() [2] = - y() * other.x() + other.x() * y();
}
