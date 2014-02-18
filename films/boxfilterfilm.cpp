#include "boxfilterfilm.h"

BoxFilterFilm::BoxFilterFilm(const int _width, const int _height) : width(_width), height(_height)
{
    image = new Spectrum[width][height];
    unnormalized = new Spectrum[width][height];
    nSamples = new float[width][height];

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            image[i][j] = new Spectrum();
            unnormalized[i][j] = new Spectrum();
            nSamples[i][j] = 0.f;
        }
    }
}

void BoxFilterFilm::addSample(double x, double y, Spectrum s)
{
    if((int)x>=0 && (int)x<width && (int)y>=0 && (int)y<height)
    {
        unnormalized[(int)x][(int)y].r += s.r;
        unnormalized[(int)x][(int)y].g += s.g;
        unnormalized[(int)x][(int)y].b += s.b;
        nSamples[(int)x][(int)y]++;
        image[(int)x][(int)y].r = unnormalized[(int)x][(int)y].r/nSamples[(int)x][(int)y];
        image[(int)x][(int)y].g = unnormalized[(int)x][(int)y].g/nSamples[(int)x][(int)y];
        image[(int)x][(int)y].b = unnormalized[(int)x][(int)y].b/nSamples[(int)x][(int)y];
    }
}
