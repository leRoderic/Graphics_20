#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>
#include "library/mat.h"
#include "Scene.h"


class DataReader {
public:
    explicit DataReader();

    DataReader(Scene *s);

    void readFile (QString fileName);

    void setParameters (vec4 pMin, vec4 pMax, QString objFile, QString cmfile);

protected:
    virtual void fileLineRead (QString lineReaded);

    Scene *scene;

    void propFound(QStringList list);

    void dataFound(QStringList list);

private:
    int numProp, tmp;
    vec4 pMin, pMax;
    float xMin, xMax, zMin, zMax;
    float dMin, dMax; // data range
    QString objFile, cmFile;
};

#endif // DataReader_H
