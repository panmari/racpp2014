#ifndef BOXFILTERFILM_H
#define BOXFILTERFILM_H
#include "film.h"
/**
 * Uses a box filter when accumulating samples on a film. A box filter means
 * that samples contribute only to the pixel that they lie in. Sample values
 * are simply averaged.
 */
class BoxFilterFilm : public Film
{
public:
    BoxFilterFilm(const int width, const int height);

    int getWidth() const
    {
        return width;
    }

    int getHeight() const
    {
        return height;
    }

    std::vector<std::vector<Spectrum> > getImage()
    {
        return image;
    }

private:
    const int width, height;
    std::vector<std::vector<Spectrum> > image;
    std::vector<std::vector<Spectrum> > unnormalized;
    float **nSamples;
    void addSample(double x, double y, Spectrum s);
};

#endif // BOXFILTERFILM_H
