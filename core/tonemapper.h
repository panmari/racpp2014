#ifndef TONEMAPPER_H
#define TONEMAPPER_H
#include <cairo.h>

/**
 * Compresses a raw rendered {@link Film} to an image that can be displayed on typical 8-bit displays.
 */
class Tonemapper
{
public:
    Tonemapper(); 

    virtual cairo_surface_t* process(Film film);

};

#endif // TONEMAPPER_H
