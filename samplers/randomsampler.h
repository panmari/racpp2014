#ifndef RANDOMSAMPLER_H
#define RANDOMSAMPLER_H
#include "sampler.h"
#include "samplerfactory.h"
#include <boost/random.hpp>


class RandomSampler : public Sampler
{
public:
    virtual vector<vector<float> > makeSamples(int n, int d);
};

class RandomSamplerFactory : public SamplerFactory {
public:
  Sampler make() { return RandomSampler(); }
};

#endif // RANDOMSAMPLER_H
