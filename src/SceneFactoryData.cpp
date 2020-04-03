#include <include/MaterialTextura.h>
#include <include/Metall.h>
#include "SceneFactoryData.h"

SceneFactoryData::SceneFactoryData()
{

}

Camera *SceneFactoryData::createCamera() {
    // creacio de la camera

    //vec3 lookfrom(0, 15, 30);//vec3 lookfrom(0, 10, 10);
    //vec3 lookat(0, 0, 0);//    vec3 lookat(1, 0, 0);
    vec3 lookfrom(0, 20, 10);
    vec3 lookat(1, 0, 0);

    float dist_to_focus = distance(lookfrom, lookat);

    float aperture = 30;//30
    int pixelsX = 600;// 600
    int pixelsY = 400;// 400

    return (new Camera(lookfrom, lookat, vec3(0, 1, 0), 70, pixelsX, pixelsY, aperture, dist_to_focus));
}

Scene *SceneFactoryData::createScene(QString filename) {
    Scene *s = new Scene();
    DataReader *sc = new DataReader(s);
    // TODO: Fase 1: construccio de l'escena dins de dataReader
    sc->readFile(filename);

    s->lights.push_back(new Light(vec3(-5, 20, 10), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(0.0,0.0,1.0)));
    s->lights.push_back(new Light(vec3(2, 8, -50), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(0.0,0.0,1.0)));
    //s->lights.push_back(new Light(vec3(2, 8, 10), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(0.0,0.0,1.0)));
    s->ambientGlobal = vec3(0.7);
    /* // LUCES EUROPA
     s->lights.push_back(new Light(vec3(-5, 20, 10), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(1.0,0.0,1.0)));
    s->lights.push_back(new Light(vec3(-5, 5, -40), vec3(0.01f), vec3(0.5f), vec3(0.4f), vec3(1.0,0.0,1.0)));
    s->lights.push_back(new Light(vec3(2, 15, 10), vec3(0.1f), vec3(0.7f), vec3(0.7f), vec3(3.0,2.0,1.0)));
    s->ambientGlobal = vec3(0.3f);*/

    //s->ground->setMaterial(new MaterialTextura());
    for(Object *o: s->objects){
        if(dynamic_cast<Sphere *>(o)) {
            //Metall(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha);
            o->setMaterial(new Metall(vec3(0.1f), vec3(0.2, 0.2, 1.0), vec3(1.0f), 500, 0));
        }
    }

    return s;
}

ColorMap *SceneFactoryData::createColorMap(ColorMapStatic::ColorMapType t) {
    ColorMap *cm = new ColorMapStatic(t);
    return cm;
}
