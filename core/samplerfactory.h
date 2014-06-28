#ifndef SAMPLERFACTORY_H
#define SAMPLERFACTORY_H
#include "sampler.h"

/**
 * Makes a {@link Sampler}.
 */
class SamplerFactory
{
public:
    SamplerFactory();

    virtual Sampler* make() = 0;
};

#endif // SAMPLERFACTORY_H
