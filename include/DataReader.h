#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>
#include "glm/glm.hpp"
#include "Scene.h"
#include "ObjectFactory.h"


class DataReader {
public:
    explicit DataReader();

    DataReader(Scene *s);

    void readFile (QString fileName);

protected:
    virtual void fileLineRead (QString lineReaded);

    Scene *scene;

    void baseFound(QStringList list);

    void limitsFound(QStringList list);

    void propFound(QStringList list);

    void dataFound(QStringList list);

private:
    int numProp, tmp;
    float xMin, xMax, zMin, zMax;
    float spMin, spMax; // Sphere value range
    float tMin, tMax; // Sphere value range
    float cyMin, cyMax; // Cylinder value range
    float brMin, brMax; // BoundaryObject value range
    QString objFile;
    vector<ObjectFactory::OBJECT_TYPES> props;
};

#endif // DataReader_H
