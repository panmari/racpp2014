#include "mandelbrotintegrator.h"


/**
 * Compute Mandelbrot set. See <a href="http://en.wikipedia.org/wiki/Mandelbrot_set">.
 */
Spectrum MandelbrotIntegrator::integrate(Ray r)
{
    // Assumes ray x and y direction is in range [0,1] across the image.
    float x0 = r.direction.x()*3.5f-2.5f;
    float y0 = r.direction.y()*2.f-1.f;

    float x = 0.f;
    float y = 0.f;
    int iteration = 0;
    int max_iteration = 100;

    while ( x*x + y*y < 2*2  &&  iteration < max_iteration )
    {
        float xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
        iteration = iteration + 1;
    }

    return Spectrum((float)iteration/(float)max_iteration, (float)iteration/(float)max_iteration, (float)iteration/(float)max_iteration);
}

vector<vector<float> > MandelbrotIntegrator::makePixelSamples(Sampler &sampler, int n)
{
    return sampler.makeSamples(n, 2);
}
