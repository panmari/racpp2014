#include "clamptonemapper.h"

namespace fs = boost::filesystem;

/**
* Perform tone mapping and return a {@link java.awt.image.BufferedImage}.
*
* @param film the film to be tonemapped
* @return the output image
*/
pngwriter* ClampTonemapper::process(Film &film)
{
   pngwriter* img = new pngwriter(film.getWidth(), film.getHeight(), 0, fs::unique_path().c_str() );

   for(int i=0; i<film.getWidth(); i++)
   {
       for(int j=0; j<film.getHeight(); j++)
       {
           // Clamping
           Spectrum s = film.getImage()[i][j];
           s.clamp(0,1);
           img->plot(i, film.getHeight()-1-j, s.x(), s.y(), s.z());
       }
   }
   return img;
}
