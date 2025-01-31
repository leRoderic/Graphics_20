#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <string.h>

#include "Scene.h"
#include "Camera.h"
#include "colormaps/ColorMap.h"

#include "colormaps/ColorMapStatic.h"
#include <QString>

class SceneFactory
{
public:

    typedef enum
    {
           VIRTUAL,
           DATA,
           TEMPORAL

    } SCENE_FACTORIES;

    virtual Scene    *createScene(QString nomFitxer) = 0;
    virtual vector<vec3> createColorMap(QString f) {};
    virtual Scene *makeScene(QString filename, QString gObj, QString cmFile, float xmin, float y, float zmin,
                                  float xmax, float zmax) = 0;
};

#endif // SCENEFACTORY_H
