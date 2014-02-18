#include "spectrum.h"

void Spectrum::clamp(float min, float max) {
  assert( min <= max );
  for (int i = 0; i < 3; i++) {
    float f = operator[](i);
    data() [i] = f < min ? min : f;
    data() [i] = f > max ? max : f;
  }
}
