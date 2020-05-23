//
// Created by anna on 18/01/2020.
//

#include "SceneFactoryVirtual.h"


SceneFactoryVirtual::SceneFactoryVirtual()
{

}
Scene *SceneFactoryVirtual::makeScene(QString filename, QString gObj, QString cmFile, float xmin, float y, float zmin,
                                     float xmax, float zmax) {
    return nullptr;
}



Scene *SceneFactoryVirtual::createScene(QString nomFitxer) {
    Scene *s = new Scene();

    s->lightAmbientGlobal = vec3(0.3f);

    Light *light = new Light(vec4(10, 20, 20,0), vec4(0.0f),vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Puntual);
    //light->setTipusLight(Puntual);
    s->addLight(light);

    //Light *dir_light = new Light(vec4(10, 20, 20,0), vec4(1.0f),vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Direccional);
    //dir_light->setTipusLight(Direccional);
    //s->addLight(dir_light);

    Light* spotlight = new Light(vec4(10, 20, 20, 0), vec4(1.0f), vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Spot, 0.25);
    s->addLight(spotlight);

    Object * obj = new Object(100000, nomFitxer);
    obj->setMaterial(new Material());
    s->addObject(obj);

    return s;
}
