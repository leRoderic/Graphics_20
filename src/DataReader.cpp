
#include "DataReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <include/ObjectFactory.h>

DataReader::DataReader(Scene *s)
{
    scene = s;
    numProp = 0;

}

void DataReader::readFile(QString fileName) {
    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error opening the file" << std::endl;
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        fileLineRead(line);
    }

    file.close();
}

// TODO: Fase 1: Cal afegir més tipus d'objectes
void DataReader::fileLineRead (QString lineReaded) {

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

    if (QString::compare("plane", fields[1], Qt::CaseInsensitive) == 0) {
        // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z
        Object *o;

        vec3 p1 = this->scene->pmax;
        vec3 p2 = this->scene->pmin;

        o = ObjectFactory::getInstance()->createObject(0, 0, 0, 0, 0, 0, 0, 0, 0,
                                                       0, 0, ObjectFactory::OBJECT_TYPES::FITTED_PLANE);

        //o = ObjectFactory::getInstance()->createObject(fields[1].toDouble(), fields[2].toDouble(), fields[3].toDouble(), fields[4].toDouble(),
        //        1.0f,ObjectFactory::OBJECT_TYPES::PLANE);
        scene->objects.push_back(o);
        // TODO Fase 4: llegir textura i afegir-la a l'objecte. Veure la classe Texture
    }
    // TODO: Fase 3: Si cal instanciar una esfera com objecte base i no un pla, cal afegir aqui un else
}


void DataReader::limitsFound(QStringList fields) {
    // limits xmin xmax zmin zmax
    if (fields.size() != 5) {
        std::cerr << "Wrong limits format" << std::endl;
        return;
    }
    xmin = fields[1].toDouble();
    xmax = fields[2].toDouble();
    zmin = fields[3].toDouble();
    zmax = fields[4].toDouble();
    // TO-DO Fase 1: Cal guardar el limits del mapa per saber on mapejar les posicions dels objectes
}

void DataReader::propFound(QStringList fields) {
    //prop numProp vmin vmax tipusGizmo
    if (fields.size() != 5) {
        std::cerr << "Wrong propietat format" << std::endl;
        return;
    }
    numProp++;
    // TODO Fase 1: Cal guardar els valors per a poder escalar els objectes i el tipus de
    //  gizmo de totes les propietats (SPHERE, BR_OBJ, CILINDRE...)
    cout<<fields[4].toStdString()<<endl;
    if (QString::compare("sphere", fields[4], Qt::CaseInsensitive) == 0) {
        props.push_back(ObjectFactory::OBJECT_TYPES::SPHERE);
    }else if (QString::compare("cylinder", fields[4], Qt::CaseInsensitive) == 0) {
        props.push_back(ObjectFactory::OBJECT_TYPES::CYLINDER);
    }else if (QString::compare("brobject", fields[4], Qt::CaseInsensitive) == 0) {
        props.push_back(ObjectFactory::OBJECT_TYPES::BROBJECT);
    }else if (QString::compare("triangle", fields[4], Qt::CaseInsensitive) == 0) {
        props.push_back(ObjectFactory::OBJECT_TYPES::TRIANGLE);
    }

    // TODO Fase 2: Aquesta valors minim i maxim tambe serviran per mapejar el material des de la paleta
}


void DataReader::dataFound(QStringList fields) {
    //data x z valor1 valor2...
    if (fields.size() != (numProp+3)) {
        std::cerr << "Wrong data format" << std::endl;
        return;
    }
    for (int i=0; i<numProp; i++) {
        // TODO Fase 1: Cal colocar els objectes al seu lloc del mon virtual, escalats segons el valor i
        //  amb el seu color corresponent segons el seu ColorMap
        Object *o;
        o = ObjectFactory::getInstance()->createObject(fields[1].toDouble(), 0.0, fields[2].toDouble(),
                                                       0, 0, 0, 0, 0, 0, fields[3 + i].toDouble(),
                                                       1.0f, props[i]);
        scene->objects.push_back(o);
    }
}
