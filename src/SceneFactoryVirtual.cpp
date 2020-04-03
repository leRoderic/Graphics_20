//
// Created by anna on 18/01/2020.
//

#include <include/Mate.h>
#include <include/Metall.h>
#include <include/Transparent.h>
#include "SceneFactoryVirtual.h"


SceneFactoryVirtual::SceneFactoryVirtual()
{

}

Scene *SceneFactoryVirtual::createScene(QString filename) {

    Scene *s = new Scene();
    SceneReader *sc = new SceneReader(s);
    sc->readFile(filename);

    s->objects[0]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->ground = s->objects[0];
    //s->objects[1]->setMaterial(new Mate(vec3(0.2f), vec3(0.5f), vec3(1.0f), 10, 0.0f));
    //s->objects[3]->setMaterial(new Transparent(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 1.0f, 1.5f));
    s->objects[1]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[2]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[3]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[4]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[5]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[6]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[7]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[8]->setMaterial(new Metall(vec3(0.2f), vec3(0.7, 0.6, 0.5), vec3(0.7f), 10, 0.0f));
    s->objects[9]->setMaterial(new Mate(vec3(0.2f), vec3(0.5f), vec3(1.0f), 10, 1.0f));


    s->ambientGlobal = vec3(0.1f);
    s->lights.push_back(new Light(vec3(-30, 0, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));
    s->lights.push_back(new Light(vec3(30, 0, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));
    s->lights.push_back(new Light(vec3(0, -30, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));
    s->lights.push_back(new Light(vec3(0, 30, 5), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));
    //s->lights.push_back(new Light(vec3(2, 8, -10), vec3(0.3f), vec3(0.7f), vec3(1.0f), vec3(0.5, 0.0, 0.01)));

    return s;
}


Camera *SceneFactoryVirtual::createCamera() {
    // creacio de la camera
    // Camera changed: !the same as the template

    vec3 lookfrom(0, 0, 40);
    vec3 lookat(0, 0, 0);
    float dist_to_focus = length(lookfrom - lookat);
    float aperture = 30;
    int pixelsX = 600;
    int pixelsY = 400;

    return (new Camera(lookfrom, lookat, vec3(0, 1, 0), 20, pixelsX, pixelsY, aperture, dist_to_focus));

}


Scene *SceneFactoryVirtual::createScene() {
    Scene *s = new Scene();
    //  TO-DO Fase 0: Test amb una esfera.
    //  TO-DO Fase 1: Aquest codi es pot modificar per a provar la visualització de diferents primitives bàsiques
    this->OneSphere(s);
    return s;
}

void SceneFactoryVirtual::OneSphere(Scene *s) {
    Sphere *sphere = new Sphere(vec3(0, 0, -1), 0.5, 1.0);
    sphere->setMaterial(new Lambertian(vec3(0.5, 0.2, 0.7)));

//    Animation *anim = new Animation();
//    anim->transf = new Translate(vec3(0.2));
//    sphere->addAnimation(anim);

    s->objects.push_back(sphere);

}