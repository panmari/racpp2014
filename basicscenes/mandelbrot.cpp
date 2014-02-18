#include "mandelbrot.h"
#include "dummycamera.h"
#include "boxfilterfilm.h"
#include "clamptonemapper.h"
#include "mandelbrotintegrator.h"
#include "randomsampler.h"
using std::make_shared;

Mandelbrot::Mandelbrot()
{
    // Output file name
    outputFilename = "../output/basicscenes/Mandelbrot";

    // Width and height of output image in pixels
    width = 1024;
    height = 1024;

    // Number of samples per pixel
    SPP = 16;

    // Specify the camera, film, and tonemapper to use
    camera = new DummyCamera(width, height);
    film = new BoxFilterFilm(width, height);
    tonemapper = new ClampTonemapper();

    // Specify the integrator and sampler to use
    integratorFactory = new MandelbrotIntegratorFactory();
    samplerFactory = new RandomSamplerFactory();
}
