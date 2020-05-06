//
// Created by anna on 18/01/2020.
//

#include "SceneFactoryVirtual.h"


SceneFactoryVirtual::SceneFactoryVirtual()
{

}

Scene *SceneFactoryVirtual::createScene(QString filename) {

    Scene *s = new Scene();
    SceneReader *sc = new SceneReader(s);
    sc->readFile(filename);

    s->lightAmbientGlobal = vec3(0.1f);
    s->lights.push_back(new Light(vec4(-30, 0, 5,0), vec4(0.0f),vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));

    return s;
}



Scene *SceneFactoryVirtual::createScene() {
    Scene *s = new Scene();
    this->OneSphere(s);
    return s;
}

void SceneFactoryVirtual::OneSphere(Scene *s) {


}
