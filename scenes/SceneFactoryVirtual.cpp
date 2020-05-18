//
// Created by anna on 18/01/2020.
//

#include "SceneFactoryVirtual.h"


SceneFactoryVirtual::SceneFactoryVirtual()
{

}
/*
Scene *SceneFactoryVirtual::createScene(QString filename) {

    Scene *s = new Scene();
    SceneReader *sc = new SceneReader(s);
    sc->readFile(filename);

    s->lightAmbientGlobal = vec3(0.1f);
    s->lights.push_back(new Light(vec4(-30, 0, 5,0), vec4(0.0f),vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));

    return s;
}*/



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

Camera *SceneFactoryVirtual::createCamera() {
    return nullptr;

}
