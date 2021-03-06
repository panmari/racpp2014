#ifndef CLAMPTONEMAPPER_H
#define CLAMPTONEMAPPER_H
#include <boost/filesystem.hpp>
#include "tonemapper.h"
/**
 * Tone maps a film by clamping all color channels to range [0,1].
 */
class ClampTonemapper : public Tonemapper
{
public:
    void process(Film &film);
    void write_png_file(char* file_name);
};

#endif // CLAMPTONEMAPPER_H
