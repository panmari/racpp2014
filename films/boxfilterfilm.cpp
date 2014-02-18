#include "boxfilterfilm.h"
using std::vector;

BoxFilterFilm::BoxFilterFilm(const int _width, const int _height) : width(_width), height(_height)
{
    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            image[i][j] = Spectrum();
            unnormalized[i][j] = Spectrum();
            nSamples[i][j] = 0.f;
        }
    }
}

void BoxFilterFilm::addSample(double x, double y, Spectrum s)
{
  int xi = static_cast<int>(x);
  int yi = static_cast<int>(x);
    if(xi>=0 && xi<width && yi>=0 && yi<height)
    {
        unnormalized[xi][yi] += s;
        nSamples[xi][yi]++;
        image[xi][yi] = Spectrum(unnormalized[xi][yi] * (1/nSamples[xi][yi]));
    }
}
