#include "Builder.h"

#include <objects/plane.h>

Builder::Builder(GLWidget *glWid)
{
    glWidget = glWid;
    scene = glWidget->getScene();

}

void Builder::loadSphere(){
    QString fileName (":/resources/models/bigSphere.obj");
    Object * obj = new Object(100000, fileName);
    obj->setMaterial(new Material());
    scene->addObject(obj);
    scene->camera->actualitzaCamera(scene->capsaMinima);
    emit newObj(obj);
}

void Builder::newObjFromFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isNull()) {
            Object * obj = new Object(100000, fileName);
            obj->setMaterial(new Material());
            scene->addObject(obj);
            scene->camera->actualitzaCamera(scene->capsaMinima);
            emit newObj(obj);
    }
}

void Builder::newVirtualScene() {
    // TO DO Fase 1: creació de la nova escena Virtual a partir d'un fitxer VIRTUAL

    SceneFactory *s = new SceneFactoryVirtual();
    scene = s->createScene("://resources/models/sphere0.obj");

     emit newScene(scene);
}


void Builder::newDataScene(QString data, QString obj, QString colormap,
                      float xmin, float xmax, float ymin, float ymax,
                      float zmin, float zmax)
{
    // TO DO Fase 1: Crear la nova escena a partir de les dades
    // de la finestra de visualization mapping corresponent
    vec4 v1, v2, v3, v4;
    v1 = vec4(xmin, ymin, zmin, 1);
    v2 = vec4(xmax, ymin, zmin, 1);
    v3 = vec4(xmin, ymin, zmax, 1);
    v4 = vec4(xmax, ymin, zmax, 1);
    Plane *p = new Plane(v1, v2, v3, v4);
    //scene = new Scene();
    p->setTexture(new QOpenGLTexture(QImage("://resources/textures/2k_venus_surface.jpg")));
    scene->addObject(p);
    Light *light = new Light(vec4(10, 20, 20,0), vec4(0.0f),vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Puntual);
    //light->setTipusLight(Puntual);
    scene->addLight(light);
    //DataReader *dr = new DataReader(scene);
    //dr->xMax = xmax;
    emit newScene(scene);
}

