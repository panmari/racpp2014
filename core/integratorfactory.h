#ifndef INTEGRATORFACTORY_H
#define INTEGRATORFACTORY_H
#include "integrator.h"
class Scene;

/**
 * Makes an {@link Integrator}.
 */
class IntegratorFactory
{
public:
    IntegratorFactory();
    virtual Integrator* make(Scene &scene) = 0;
    virtual void prepareScene(Scene &scene) = 0;
};

#endif // INTEGRATORFACTORY_H
