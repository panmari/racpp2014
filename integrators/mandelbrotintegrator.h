#ifndef MANDELBROTINTEGRATOR_H
#define MANDELBROTINTEGRATOR_H
#include "integrator.h"
#include "scene.h"

class MandelbrotIntegrator : public Integrator
{
public:
    virtual Spectrum integrate(Ray r);
    virtual vector<vector<float> > makePixelSamples(Sampler &sampler, int n);
};

class MandelbrotIntegratorFactory : public IntegratorFactory {
public:
  Integrator* make(Scene &scene) {
      return new MandelbrotIntegrator();
  }

  void prepareScene(Scene scene) { }
};

#endif // MANDELBROTINTEGRATOR_H
