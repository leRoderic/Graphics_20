#include "SceneReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>

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

    if (QString::compare("object", fields[0], Qt::CaseInsensitive) == 0)
        brObjectFound(fields);
    else
        std::cerr << "Element unknown" << std::endl;
}


void SceneReader::brObjectFound(QStringList fields) {

    //  Fase 1: Per incloure BrObjecte
    //  Es suposa que serà una linia del fitxer de l'estil
    //  brobject nomDelFitxer posició del seu centre, i la seva escala

    if (fields.size() != 2) {
        std::cerr << "Wrong brObject format" << std::endl;
        return;
    }
    Object *o = new Object(100000, fields[1]);

    scene->elements.push_back(o);
}

