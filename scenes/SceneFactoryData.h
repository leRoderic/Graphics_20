#ifndef SCENEFACTORYSTATIC_H
#define SCENEFACTORYSTATIC_H

#include "SceneFactory.h"
#include "colormaps/ColorMapStatic.h"
#include "DataReader.h"

class SceneFactoryData : public SceneFactory
{
public:
    SceneFactoryData();
    virtual Scene *createScene(QString filename);
    virtual Scene *makeScene(QString filename, QString gObj, QString cmFile, float xmin, float y, float zmin,
                                  float xmax, float zmax);
    virtual ColorMap *createColorMap(ColorMapStatic::ColorMapType t);
};

#endif // SCENEFACTORYSTATIC_H
