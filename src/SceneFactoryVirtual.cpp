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
    return s;
}

Scene *SceneFactoryVirtual::createScene() {
    Scene *s = new Scene();
    //   TODO Fase 0: Test amb una esfera.
    //  TODO Fase 1: Aquest codi es pot modificar per a provar la visualització de diferents primitives bàsiques
    this->OneSphere(s);
    return s;
}

void SceneFactoryVirtual::OneSphere(Scene *s) {
    Sphere * sphere = new Sphere(vec3(0, 0, -1), 0.5, 1.0);
    sphere->setMaterial(new Lambertian(vec3(0.5, 0.2, 0.7)));

//    Animation *anim = new Animation();
//    anim->transf = new Translate(vec3(0.2));
//    sphere->addAnimation(anim);

    s->objects.push_back(sphere);

}

Camera *SceneFactoryVirtual::createCamera() {
    // creacio de la camera
    vec3 lookfrom(0, 0, 1);
    vec3 lookat(0,0,0);
    float dist_to_focus = 1.0;
    float aperture = 0.1;
    int pixelsX = 600;
    int pixelsY = 400;
    return( new Camera(lookfrom, lookat, vec3(0,1,0), 90, pixelsX, pixelsY, aperture, dist_to_focus));
}
