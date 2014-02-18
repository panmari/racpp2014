#ifndef SPECTRUM_H
#define SPECTRUM_H

#include "vector3f.h"

/**
 * Stores a spectrum of color values. In this implementation, we work with RGB colors.
 */
class Spectrum : public Vector3f
{
public:
  Spectrum() {}
  Spectrum(Vector3f const& v) {
    int i = 0;
    for (float d : v.data()) {
      data()[i] = d;
      i++;
    }
  }
  Spectrum(float x, float y, float z) : Vector3f(x,y,z) { }

  void clamp(float min, float max);

};

#endif // SPECTRUM_H
