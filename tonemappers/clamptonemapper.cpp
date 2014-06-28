#include "clamptonemapper.h"
#include <boost/filesystem.hpp>
#include <png++/png.hpp>

namespace fs = boost::filesystem;

/**
* Perform tone mapping and return a {@link java.awt.image.BufferedImage}.
*
* @param film the film to be tonemapped
* @return the output image
*/
void ClampTonemapper::process(Film &film)
{
   png::image< png::rgb_pixel > image(film.getWidth(), film.getHeight());

   for(int i=0; i<film.getWidth(); i++)
   {
       for(int j=0; j<film.getHeight(); j++)
       {
           // Clamping
           Spectrum s = film.getImage()[i][j];
           s.clamp(0,1);
           image[film.getHeight() - i][j] = png::rgb_pixel(s.x(), s.y(), s.z());
       }
   }
   image.write("test.png");
}
