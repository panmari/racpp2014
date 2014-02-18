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
    virtual Integrator make(Scene scene);
    virtual void prepareScene(Scene scene);
};

#endif // INTEGRATORFACTORY_H
