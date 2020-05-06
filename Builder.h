#ifndef BUILDER_H
#define BUILDER_H

#include <QtWidgets>
#include <GLWidget.h>

class Builder : public QObject {
        Q_OBJECT

    Scene *scene;
    GLWidget *glWidget;

public:
    Builder(GLWidget *glWid);

public slots:
    void loadSphere();
    void newObjFromFile();
    void newVirtualScene();
    void newDataScene(QString data, QString obj, QString colormap, float xmin, float xmax, float ymin, float ymax, float zmin, float zmax);

signals:
    void newObj(Object *o);
    void newScene(Scene *sc);
};

#endif // BUILDER_H
