#include "SceneReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <include/ObjectFactory.h>

SceneReader::SceneReader(Scene *s)
{
    scene = s;
}

void SceneReader::readFile(QString fileName) {

    std::cout << fileName.toStdString() << std::endl;

    QFile file(fileName);

    if(!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error opening the file scene" << std::endl;
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()) {
        QString line = in.readLine();
        fileLineRead(line);
    }

    file.close();
}

// TO-DO: Fase 1: Cal afegir més tipus d'objectes
void SceneReader::fileLineRead (QString lineReaded) {
    QStringList fields = lineReaded.split(",");
    if (QString::compare("Sphere", fields[0], Qt::CaseInsensitive) == 0)
        sphereFound(fields);
    else if (QString::compare("Base", fields[0], Qt::CaseInsensitive) == 0)
        baseFound(fields);
    else if (QString::compare("Triangle", fields[0], Qt::CaseInsensitive) == 0)
        triangleFound(fields);
    else if (QString::compare("Cylinder", fields[0], Qt::CaseInsensitive) == 0)
        cylinderFound(fields);
    else if (QString::compare("Circle", fields[0], Qt::CaseInsensitive) == 0)
        circleFound(fields);
    else if (QString::compare("Brobject", fields[0], Qt::CaseInsensitive) == 0)
        brObjectFound(fields);
    else
        std::cerr << "Element unknown" << std::endl;
}

// Exemple d'esfera
// sphere, 0.5, 0.5, 0.0, 0.25
void SceneReader::sphereFound(QStringList fields) {
    if (fields.size() != 5 ) {
        std::cerr << "Wrong sphere format" << std::endl;
        return;
    }
    Object *o;

    o = ObjectFactory::getInstance()->createObject(fields[1].toDouble(), fields[2].toDouble(), fields[3].toDouble(),
                                                   0, 0, 0, 0, 0, 0, fields[4].toDouble(),
                                                   1.0f, ObjectFactory::OBJECT_TYPES::SPHERE);
    scene->objects.push_back(o);
}


// Exemple de base:
// Base,  plane,  0.0,  1.0,  0.0,  -0.5, ://resources/map.png
void SceneReader::baseFound(QStringList fields) {
    if (fields.size() != 10) {
        std::cerr << "Wrong base format" << std::endl;
        return;
    }
    Object *o;
    if (QString::compare("plane", fields[1], Qt::CaseInsensitive) == 0) {
        // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z
        o = ObjectFactory::getInstance()->createObject(fields[2].toDouble(), fields[3].toDouble(), fields[4].toDouble(),
                                                       fields[5].toDouble(), fields[6].toDouble(), fields[7].toDouble(),
                                                       0, 0, 0, fields[8].toDouble(),
                                                       1.0f, ObjectFactory::OBJECT_TYPES::PLANE);
        // TO-DO Fase 4: llegir textura i afegir-la a l'objecte. Veure la classe Texture
    } else if (QString::compare("fittedplane", fields[1], Qt::CaseInsensitive) == 0) {
        // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z
        o = ObjectFactory::getInstance()->createObject(fields[2].toDouble(), fields[3].toDouble(), fields[4].toDouble(),
                                                       0, 0, 0, 0, 0, 0, fields[8].toDouble(),
                                                       1.0f, ObjectFactory::OBJECT_TYPES::FITTED_PLANE);
    }
    scene->objects.push_back(o);
    // TO-DO: Fase 3: Si cal instanciar una esfera com objecte base i no un pla, cal afegir aqui un switch
}

void SceneReader::triangleFound(QStringList fields) {
    if (fields.size() != 11) {
        std::cerr << "Wrong triangle format" << fields.size() << std::endl;
        return;
    }

    Object *o;
    // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z
    o = ObjectFactory::getInstance()->createObject(fields[1].toDouble(), fields[2].toDouble(), fields[3].toDouble(),
            fields[4].toDouble(), fields[5].toDouble(), fields[6].toDouble(),
            fields[7].toDouble(),fields[8].toDouble(), fields[9].toDouble(),
            fields[10].toDouble(), 1.0f,ObjectFactory::OBJECT_TYPES::TRIANGLE);
    scene->objects.push_back(o);
        // TO-DO Fase 4: llegir textura i afegir-la a l'objecte. Veure la classe Texture

    // TO-DO: Fase 3: Si cal instanciar una esfera com objecte base i no un pla, cal afegir aqui un switch
}

void SceneReader::brObjectFound(QStringList fields) {

    //  Fase 1: Per incloure BrObjecte
    //  Es suposa que serà una linia del fitxer de l'estil
    //  brobject nomDelFitxer posició del seu centre, i la seva escala

    if (fields.size() != 3) {
        std::cerr << "Wrong brObject format" << std::endl;
        return;
    }
    Object *o;

    o = ObjectFactory::getInstance()->createObject(fields[1], fields[2].toDouble(),
            ObjectFactory::OBJECT_TYPES::BROBJECT);

    scene->objects.push_back(o);
}

void SceneReader::cylinderFound(QStringList fields) {
    if (fields.size() != 6) {
        std::cerr << "Wrong cylinder format" << fields.size()<< std::endl;
        return;
    }

    Object *o;
    // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z
    o = ObjectFactory::getInstance()->createObject(fields[1].toDouble(), fields[2].toDouble(), fields[3].toDouble(),
                                                   0, 0, 0, 0, 0, 0, fields[4].toDouble(),
                                                   1.0f, ObjectFactory::OBJECT_TYPES::CYLINDER);
    scene->objects.push_back(o);
    // TO-DO Fase 4: llegir textura i afegir-la a l'objecte. Veure la classe Texture

    // TO-DO: Fase 3: Si cal instanciar una esfera com objecte base i no un pla, cal afegir aqui un switch
}
void SceneReader::circleFound(QStringList fields) {
    if (fields.size() != 5 ) {
        std::cerr << "Wrong circle format" << std::endl;
        return;
    }
    Object *o;
    o = ObjectFactory::getInstance()->createObject(fields[1].toDouble(), fields[2].toDouble(), fields[3].toDouble(),
                                                   0, 0, 0, 0, 0, 0, fields[4].toDouble(),
                                                   1.0f, ObjectFactory::OBJECT_TYPES::CIRCLE);
    scene->objects.push_back(o);
}
