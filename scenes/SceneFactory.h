#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include <string.h>

#include "Scene.h"
#include "Camera.h"
#include "colormaps/ColorMap.h"
#include "ReadFile.h"
#include "ObjectFactory.h"
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
    virtual ColorMap *createColorMap(ColorMapStatic::ColorMapType t) {return nullptr;};
    virtual Camera   *createCamera() = 0;

};

#endif // SCENEFACTORY_H
