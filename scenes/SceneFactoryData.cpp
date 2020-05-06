#include "SceneFactoryData.h"
#include "Light.h"

SceneFactoryData::SceneFactoryData()
{

}

Scene *SceneFactoryData::createScene(QString filename) {
    Scene *s = new Scene();
    DataReader *sc = new DataReader(s);

    sc->readFile(filename);

    s->lights.push_back(new Light(vec4(2, 15, 10,0), vec4(0,0,0,0), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(3.0,2.0,1.0)));

    s->lightAmbientGlobal = vec3(0.3f);

    return s;
}

ColorMap *SceneFactoryData::createColorMap(ColorMapStatic::ColorMapType t) {
    ColorMap *cm = new ColorMapStatic(t);
    return cm;
}
