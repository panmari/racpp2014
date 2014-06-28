#ifndef SCENE_H
#define SCENE_H
#include "core_utils.h"

/**
 * Defines scene properties that need to be made accessible to the renderer.
 */
class Scene {
public:

    IntegratorFactory*  getIntegratorFactory() {
        return integratorFactory;
    }

    SamplerFactory*  getSamplerFactory() {
        return samplerFactory;
    }

    std::string getOutputFilename()
    {
        return outputFilename;
    }

    Camera*  getCamera() {
        return camera;
    }

    Film*  getFilm() {
        return film;
    }

    Intersectable*  getIntersectable() {
        return root;
    }

    LightList*  getLightList() {
        return lightList;
    }

    int getSPP() {
        return SPP;
    }

    Tonemapper*  getTonemapper()
    {
        return tonemapper;
    }

    virtual void prepare() = 0;
    virtual ~Scene() {};

protected:
    string outputFilename;
    /// Samples per pixel
    int SPP;
    int width;
    int height;
    Camera* camera;
    Film* film;
    IntegratorFactory* integratorFactory;
    SamplerFactory* samplerFactory;
    Tonemapper* tonemapper;
    Intersectable* root;
    LightList* lightList;
};

#endif // SCENE_H
