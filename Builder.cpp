#include "Builder.h"

Builder::Builder(GLWidget *glWid)
{
    glWidget = glWid;
    scene = glWidget->getScene();

}

void Builder::newObjFromFile()
{
    QString fileName = QFileDialog::getOpenFileName();
    if (!fileName.isNull()) {
            Object * obj = new Object(100000, fileName);
            scene->addObject(obj);
            scene->camera->actualitzaCamera(scene->capsaMinima);
            emit newObj(obj);
    }
}

void Builder::newVirtualScene() {
    // TO DO Fase 1: creació de la nova escena Virtual a partir d'un fitxer VIRTUAL

     emit newScene(scene);
}


void Builder::newDataScene(QString data, QString obj, QString colormap,
                      float xmin, float xmax, float ymin, float ymax,
                      float zmin, float zmax)
{
    // TO DO Fase 1: Crear la nova escena a partir de les dades
    // de la finestra de visualization mapping corresponent

    emit newScene(scene);
}

