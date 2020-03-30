#include "SceneFactoryData.h"

SceneFactoryData::SceneFactoryData()
{

}

Camera *SceneFactoryData::createCamera() {
    // creacio de la camera
    //vec3 lookfrom(3,2,2);
    vec3 lookfrom(1, 1, 0.5);
    vec3 lookat(0,0,0);

    float dist_to_focus = 2;

    float aperture = 0.2;
    int pixelsX = 600;
    int pixelsY = 400;

    return (new Camera(lookfrom, lookat, vec3(0, 1, 0), 90, pixelsX, pixelsY, aperture, dist_to_focus));
}

Scene *SceneFactoryData::createScene(QString filename) {
    Scene *s = new Scene();
    DataReader *sc = new DataReader(s);
    // TODO: Fase 1: construccio de l'escena dins de dataReader
    sc->readFile(filename);

    s->lights.push_back(new Light(vec3(2, 8, 10), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));
    return s;
}

ColorMap *SceneFactoryData::createColorMap(ColorMapStatic::ColorMapType t) {
    ColorMap *cm = new ColorMapStatic(t);
    return cm;
}
