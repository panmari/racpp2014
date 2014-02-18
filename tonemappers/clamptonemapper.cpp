#include "clamptonemapper.h"

ClampTonemapper::ClampTonemapper()
{
}

/**
* Perform tone mapping and return a {@link java.awt.image.BufferedImage}.
*
* @param film the film to be tonemapped
* @return the output image
*/
cairo_surface_t* ClampTonemapper::process(Film film)
{
    cairo_surface_t* img = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, film.getWidth(), film.getHeight());

   for(int i=0; i<film.getWidth(); i++)
   {
       for(int j=0; j<film.getHeight(); j++)
       {
           // Clamping
           Spectrum s = film.getImage()[i][j];
           s.clamp(0,1);
           img.setRGB(i, film.getHeight()-1-j, ((int)(255.f*s.r) << 16) | ((int)(255.f*s.g) << 8) | ((int)(255.f*s.b)));
       }
   }
   return img;
}
