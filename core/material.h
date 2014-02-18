#ifndef MATERIAL_H
#define MATERIAL_H
class HitRecord;

/**
 * Materials implement functionality for shading surfaces using their BRDFs.
 */
class Material
{
public:
    Material();

     /**
     * Stores information about a shading sample.
     */
    class ShadingSample {
    public:
        /**
         * The BRDF value.
         */
        Spectrum brdf;

        /**
         * The sampled direction.
         */
        Vector3f w;

        /**
         * Tells the integrator whether this is a specular sample. In this case,
         * a cosine factor in the specular BRDF should be omitted in the returned
         * BRDF value, and the integrator should act accordingly.
         */
        bool isSpecular;

        /**
         * The probability density of the sample
         */
        float p;
    };

    /**
     * Evaluate BRDF for pair of incoming and outgoing directions. This method
     * is typically called by an integrator when the integrator sampled the incident
     * direction on a light source.
     *
     * @param hitRecord Information about hit point
     * @param wOut Outgoing direction, normalized and pointing away from the surface
     * @param wIn Incoming direction, normalized and pointing away from the surface
     * @return BRDF value
     */
    virtual Spectrum evaluateBRDF(HitRecord hitRecord, Vector3f wOut, Vector3f wIn);

    /**
     * Return whether material has perfect specular reflection.
     */
    virtual bool hasSpecularReflection();

    /**
     * Evaluate specular reflection. This method is typically called by a recursive
     * ray tracer to follow the path of specular reflection.
     */
    virtual ShadingSample evaluateSpecularReflection(HitRecord hitRecord);

    /**
     * Return whether the material has perfect specular refraction.
     */
    virtual bool hasSpecularRefraction();

    /**
     * Evaluate specular refraction. This method is typically called by a recursive
     * ray tracer to follow the path of specular refraction.
     */
    virtual ShadingSample evaluateSpecularRefraction(HitRecord hitRecord);

    /**
     * Calculate a shading sample, given a uniform random sample as input. This
     * method is typically called in a path tracer to sample and evaluate the
     * next path segment. The methods decides which component of the material to
     * sample (diffuse, specular reflection or refraction, etc.), computes an
     * incident direction, and returns the BRDF value, the direction, and the
     * probability density (stored in a {@link ShadingSample}).
     */
    virtual ShadingSample getShadingSample(HitRecord hitRecord, float sample[]);

};

#endif // MATERIAL_H
