#ifndef DATAREADER_H
#define DATAREADER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>
#include "glm/glm.hpp"
#include "Scene.h"
#include "ObjectFactory.h"

/*
 *  Posicion 00: Tipo [sphere, base, brobject...]
 *
 *  Formato para sphere:
 *  Posicion 01:    Sphere Centro X
 *  Posicion 02:    Sphere Centro Y
 *  Posicion 03:    Sphere Centro Z
 *  Posicion 04:    Sphere Radio
 *
 *
 *  Formato para la base
 *  Posicion 01:    tipo de base: plane o sphere
 *  Posicion 02:    En caso de plane Normal X
 *  Posicion 03:    En caso de plane Normal Y
 *  Posicion 04:    En caso de plane Normal Z
 *  Posicion 05:    En caso de plane D
 *
 *  Formato para brObject:
 *  Posicion 01:    Archivo.obj
 *  Posicion 02:    Centro X
 *  Posicion 03:    Centro Y
 *  Posicion 04:    Centro Z
 *  Posicion 05:    Escala
 */

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
    int numProp;
    vector<ObjectFactory::OBJECT_TYPES> props;
};

#endif // DataReader_H
