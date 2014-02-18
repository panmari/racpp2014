#ifndef CLAMPTONEMAPPER_H
#define CLAMPTONEMAPPER_H
#include "core/tonemapper.h"
/**
 * Tone maps a film by clamping all color channels to range [0,1].
 */
class ClampTonemapper : public Tonemapper
{
public:
    ClampTonemapper();   
};

#endif // CLAMPTONEMAPPER_H
