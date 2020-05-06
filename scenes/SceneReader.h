#ifndef SCENEREADER_H
#define SCENEREADER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <vector>
#include "library/mat.h"
#include "Scene.h"

/*
 *  Posicion 00: Tipo [sphere, base, brobject...]
 *
 *  Formato para sphere:
 *  Posicion 01:    Sphere Centro X
 *  Posicion 02:    Sphere Centro Y
 *  Posicion 03:    Sphere Centro Z
 *  Posicion 04:    Sphere Radio
 *  TO-DO FASE 2: Añadir componentes del material
 *
 *
 *  Formate para la base
 *  Posicion 01:    tipo de base: plane o sphere
 *  Posicion 02:    En caso de plane Normal X
 *  Posicion 03:    En caso de plane Normal Y
 *  Posicion 04:    En caso de plane Normal Z
 *  Posicion 05:    En caso de plane D
 *
 *  Formato para brObject:
 *  Posicion 01:    Ruta Archivo .obj
 *  Posicion 02:    Centro X
 *  Posicion 03:    Centro Y
 *  Posicion 04:    Centro Z
 *  Posicion 05:    Escala
 */

class SceneReader {
public:
    explicit SceneReader();

    SceneReader(Scene *s);

    void readFile (QString fileName);

protected:
    virtual void fileLineRead (QString lineReaded);

    Scene *scene;

    void brObjectFound(QStringList list);
};

#endif // SCENEREADER_H
