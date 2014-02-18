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
    const int width, height;

private:
    Spectrum[][] image;
    Spectrum[][] unnormalized;
    float nSamples[][];

    int getWidth()
    {
        return width;
    }

    int getHeight()
    {
        return height;
    }

    Spectrum[][] getImage()
    {
        return image;
    }
};

#endif // BOXFILTERFILM_H
