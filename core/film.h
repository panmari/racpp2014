#ifndef FILM_H
#define FILM_H
#include "spectrum.h"

/**
 * A film stores a 2D grid of {@link rt.Spectrum} representing an image.
 * Rendered samples can be added one by one to a film. Samples are
 * filtered using some filter (depending on the implementation of this
 * interface) when added.
 */
class Film
{
public:
    /**
     * Add a sample to the film at a specified floating point position. The position
     * coordinates are assumed to be in image space.
     *
     * @param x x-coordinate in image space
     * @param y y-coordinate in image space
     * @param s sample to be added
     */
    virtual void addSample(double x, double y, Spectrum s) = 0;

    /**
     * Returns the image stored in the film.
     *
     * @return the image
     */
    virtual std::vector<std::vector<Spectrum> > getImage() = 0;

    /**
     * Returns width (in pixels) of film.
     *
     * @return width in pixels
     */
    virtual int getWidth() const = 0;

    /**
     * Returns height (in pixels) of film.
     *
     * @return height in pixels
     */
    virtual int getHeight() const = 0;
};

#endif // FILM_H
