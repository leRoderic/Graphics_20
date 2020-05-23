#include "SceneFactoryData.h"
#include "Light.h"

#include <objects/plane.h>

SceneFactoryData::SceneFactoryData()
{

}

Scene *SceneFactoryData::createScene(QString filename) {
    return nullptr;
}

Scene *SceneFactoryData::makeScene(QString filename, QString gObj, QString cmFile, float xmin, float y, float zmin,
                                     float xmax, float zmax) {
    Scene *s = new Scene();
    DataReader *sc = new DataReader(s);
    sc->setParameters(vec4(xmin, y, zmin, 1), vec4(xmax, y, zmax, 1), gObj, cmFile);

    Plane *p = new Plane(vec4(xmin, y, zmin, 1), vec4(xmax, y, zmin, 1), vec4(xmin, y, zmax, 1), vec4(xmax, y, zmax, 1));
    p->setTexture(new QOpenGLTexture(QImage("://resources/textures/2k_venus_surface.jpg")));
    s->addObject(p);

    sc->readFile(filename);

    s->lights.push_back(new Light(vec4(2, 15, 10,0), vec4(0,0,0,0), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(3.0,2.0,1.0), Puntual));
    s->lightAmbientGlobal = vec3(0.3f);

    return s;
}

ColorMap *SceneFactoryData::createColorMap(ColorMapStatic::ColorMapType t) {
    ColorMap *cm = new ColorMapStatic(t);
    return cm;
}
