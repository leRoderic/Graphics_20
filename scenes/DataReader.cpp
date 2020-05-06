#include "DataReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>


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
    if (QString::compare("prop", fields[0], Qt::CaseInsensitive) == 0)
        propFound(fields);
    else if (QString::compare("data", fields[0], Qt::CaseInsensitive) == 0)
        dataFound(fields);
    else
        std::cerr << "Element unknown" << std::endl;
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

}


void DataReader::dataFound(QStringList fields) {
    //data x z valor1 valor2...
    /*if (fields.size() != (numProp+3)) {
        std::cerr << "Wrong data format" << std::endl;
        return;
    }*/


}

float toColorMapUnderstandable(float d){

    float scaled = (d - 0) / (1 - 0);

    if(scaled > 1)
        return 255;
    else if(scaled < 0)
        return 0;

    return scaled*255;
}
