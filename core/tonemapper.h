#ifndef TONEMAPPER_H
#define TONEMAPPER_H
#include "film.h"
#include "pngwriter.h"

/**
 * Compresses a raw rendered {@link Film} to an image that can be displayed on typical 8-bit displays.
 */
class Tonemapper
{
public:
    virtual pngwriter* process(Film &film) = 0;
};

#endif // TONEMAPPER_H
