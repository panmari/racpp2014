#include "randomsampler.h"

static boost::random::mt19937_64 rng;
static boost::random::uniform_real_distribution<> uniform(0,1);

/**
 * Makes @param n uniform random samples in @param d
 * dimensions. The samples are in the range [0,1] in
 * all dimensions.
 */
vector<vector<float> > RandomSampler::makeSamples(int n, int d)
{
    vector<vector<float> > samples = vector<vector<float> >(n);

    for(int i=0; i<n; i++)
    {
        samples[i] = vector<float> (d);
        for(int j=0; j<d; j++)
        {
            samples[i][j] = uniform(rng);
        }
    }
    return samples;
}
