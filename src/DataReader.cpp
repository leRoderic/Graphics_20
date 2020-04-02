#include "DataReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <include/ObjectFactory.h>
#include <include/Mate.h>
#include <include/MaterialTextura.h>

float toColorMapUnderstandable(float d);

DataReader::DataReader(Scene *s) {
    scene = s;
    numProp = 0;

}

void DataReader::readFile(QString fileName) {
    QFile file(fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error opening the file" << std::endl;
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        fileLineRead(line);
    }

    file.close();
}

// TO-DO: Fase 1: Cal afegir més tipus d'objectes
void DataReader::fileLineRead(QString lineReaded) {

    QStringList fields = lineReaded.split(",");
    if (QString::compare("limits", fields[0], Qt::CaseInsensitive) == 0)
        limitsFound(fields);
    else if (QString::compare("base", fields[0], Qt::CaseInsensitive) == 0)
        baseFound(fields);
    else if (QString::compare("prop", fields[0], Qt::CaseInsensitive) == 0)
        propFound(fields);
    else if (QString::compare("data", fields[0], Qt::CaseInsensitive) == 0)
        dataFound(fields);
    else
        std::cerr << "Element unknown" << std::endl;
}

void DataReader::baseFound(QStringList fields) {
    //base plane nx ny nz d textura
    if (fields.size() != 7) {
        std::cerr << "Wrong base format" << std::endl;
        return;
    }

    Object *o;

    if (QString::compare(" plane", fields[1], Qt::CaseInsensitive) == 0) {
        // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z

        float y = -1.0f;
        y = fields[5].toDouble();

        scene->pmin = vec3 (xMin, y, zMin);
        scene->pmax = vec3 (xMax, y, zMax);

        o = ObjectFactory::getInstance()->createObject(scene->pmin.x, y, scene->pmin.z, scene->pmax.x, y, scene->pmax.z,
                                                       fields[2].toDouble(), fields[3].toDouble(), fields[4].toDouble(),
                                                       y, 0, ObjectFactory::OBJECT_TYPES::FITTED_PLANE);

        o->setMaterial(new MaterialTextura(fields[6].simplified()));
        //Fase 1 / 3.2 / b / a
        scene->ground = (FittedPlane *) o;

        // TODO Fase 4: llegir textura i afegir-la a l'objecte. Veure la classe Texture
    } else if (QString::compare(" sphere", fields[1], Qt::CaseInsensitive) == 0) {
        // TO-DO: Fase 3: Si cal instanciar una esfera com objecte base i no un pla, cal afegir aqui un else
        o = ObjectFactory::getInstance()->createObject(fields[2].toDouble(), fields[3].toDouble(),
                                                       fields[4].toDouble(), 0, 0, 0, 0, 0, 0,
                                                       fields[5].toDouble(), 0, ObjectFactory::OBJECT_TYPES::SPHERE);
        scene->ground = (Sphere *) o;
    }
}


void DataReader::limitsFound(QStringList fields) {
    // limits xmin xmax zmin zmax
    if (fields.size() != 5) {
        std::cerr << "Wrong limits format" << std::endl;
        return;
    }
    xMin = fields[1].toDouble();
    xMax = fields[2].toDouble();
    zMin = fields[3].toDouble();
    zMax = fields[4].toDouble();

    // TO-DO Fase 1: Cal guardar el limits del mapa per saber on mapejar les posicions dels objectes
}

void DataReader::propFound(QStringList fields) {
    //prop numProp vmin vmax tipusGizmo
    if (fields.size() != 5) {
        std::cerr << "Wrong propietat format" << std::endl;
        return;
    }
    numProp++;
    // TO-DO Fase 1: Cal guardar els valors per a poder escalar els objectes i el tipus de
    //  gizmo de totes les propietats (SPHERE, BR_OBJ, CILINDRE...)
    cout << fields[4].toStdString() << endl;
    if (QString::compare(" sphere", fields[4], Qt::CaseInsensitive) == 0) {
        spMin = fields[2].toDouble();
        spMax = fields[3].toDouble();
        props.push_back(ObjectFactory::OBJECT_TYPES::SPHERE);
    } else if (QString::compare(" cylinder", fields[4], Qt::CaseInsensitive) == 0) {
        cyMin = fields[2].toDouble();
        cyMax = fields[3].toDouble();
        props.push_back(ObjectFactory::OBJECT_TYPES::CYLINDER);
    } else if (QString::compare(" brobject", fields[5], Qt::CaseInsensitive) == 0) {
        brMin = fields[2].toDouble();
        brMax = fields[3].toDouble();
        objFile = fields[4];
        props.push_back(ObjectFactory::OBJECT_TYPES::BROBJECT);
    }

    // TODO Fase 2: Aquesta valors minim i maxim tambe serviran per mapejar el material des de la paleta
}


void DataReader::dataFound(QStringList fields) {
    //data x z valor1 valor2...
    /*if (fields.size() != (numProp+3)) {
        std::cerr << "Wrong data format" << std::endl;
        return;
    }*/

    Object *o;
    vec3 translation = vec3(0.0f);
    float scaledData;

    for (int i = 0; i < numProp; i++) {
        // TODO Fase 1: Cal colocar els objectes al seu lloc del mon virtual, escalats segons el valor i
        //  amb el seu color corresponent segons el seu ColorMap

        translation.x = (fields[1].toDouble() - xMin) / (xMax - xMin) * (scene->pmax.x - scene->pmin.x) + scene->pmin.x;
        translation.z = scene->pmax.z - (fields[2].toDouble() - zMin) / (zMax - zMin) * (scene->pmax.z - scene->pmin.z);

        if (props.back() == ObjectFactory::OBJECT_TYPES::SPHERE) {

            scaledData = (fields[3].toDouble() - spMin) / (spMax - spMin);

            o = ObjectFactory::getInstance()->createObject(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
                                                           0.0f, 1, toColorMapUnderstandable(scaledData), props.back());
            o->aplicaTG(new Scale(scaledData));
            o->aplicaTG(new Translate(translation));

        } else if (props.back() == ObjectFactory::OBJECT_TYPES::CYLINDER) {
            scaledData = (fields[3].toDouble() - cyMin) / (cyMax - cyMin);
            o = ObjectFactory::getInstance()->createObject(0.0f, 0.0f, 0.0f, 0, 0, 0, 0, 0, 0, 1, toColorMapUnderstandable(scaledData),
                                                           props.back());
            o->aplicaTG(new Scale(scaledData));
            o->aplicaTG(new Translate(translation));
        } else if (props.back() == ObjectFactory::OBJECT_TYPES::BROBJECT) {
            scaledData = (fields[3].toDouble() - brMin) / (brMax - brMin);
            o = ObjectFactory::getInstance()->createObject(objFile, toColorMapUnderstandable(scaledData), props.back());
        }

        scene->objects.push_back(o);
    }
}

float toColorMapUnderstandable(float d){

    float scaled = (d - 0) / (1 - 0);

    if(scaled > 1)
        return 255;
    else if(scaled < 0)
        return 0;

    return scaled*255;
}
