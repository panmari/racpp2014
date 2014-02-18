#ifndef LIGHTSOURCE_H
#define LIGHTSOURCE_H
#include "vector3f.h"
#include "spectrum.h"

/**
 * Light sources provide illumination for rendered scenes.
 */
class Lightsource
{
public:
    Lightsource();

        /**
         * Stores all information related to a light sample.
         */
        class LightSample
        {
        public:
            /**
             * The position on the light source that was sampled.
             */
            Vector3f position;

            /**
             * The normal on the light source that was sampled.
             */
            Vector3f normal;

            /**
             * The emission on the light source that was sampled.
             */
            Spectrum emission;

            /**
             * The probability density of the sample.
             */
            float p;

            LightSample(Vector3f _position, Vector3f _normal, Spectrum _emission, float _p) :
                position(_position), normal(_normal), emission(_emission), p(_p)
            {
            }

        };

        /**
         * Get a {@link LightSample} from this light source.
         *
         * @param s random sample to determine the location on the light source
         * @return the light samples
         */
        Lightsource::LightSample getLightSample(float s[]);

};

#endif // LIGHTSOURCE_H
