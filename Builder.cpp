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

     emit newSceneVirtual(scene);
}


void Builder::newDataScene(QString data, QString obj, QString colormap,
                      float xmin, float xmax, float ymin, float ymax,
                      float zmin, float zmax)
{
    SceneFactory *sfd = new SceneFactoryData();

    scene = sfd->makeScene(data, obj, colormap, xmin, ymin, zmin, xmax, zmax);

    emit newSceneData(scene);
}

