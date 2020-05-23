#include "DataReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <TG/Translate.h>


float toColorMapUnderstandable(float d);

DataReader::DataReader(Scene *s) {
    scene = s;
    numProp = 0;

}

void DataReader::setParameters(vec4 pMin, vec4 pMax, QString objFile, vector<vec3> cm) {
    this->pMin = pMin;
    this->pMax = pMax;
    this->objFile = objFile;
    this->colormap = cm;
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

void DataReader::propFound(QStringList fields) {
    //prop numProp vmin vmax tipusGizmo
    if (fields.size() != 4) {
        std::cerr << "Wrong property format" << std::endl;
        return;
    }
    numProp++;
    dMin = fields[2].toDouble();
    dMax = fields[3].toDouble();

    // TO-DO Fase 2: Aquesta valors minim i maxim tambe serviran per mapejar el material des de la paleta
}

vec3 DataReader::getColorFromPalette (float data) {

    return this->colormap[(int)(data*this->colormap.size())];
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

        /*translation.x = (fields[1].toDouble() - xMin) / (xMax - xMin) * (pMax.x - pMin.x) + pMin.x;
        translation.z = -(pMax.z - (fields[2].toDouble() - zMin) / (zMax - zMin) * (pMax.z - pMin.z));*/

        scaledData = (fields[3].toDouble() - dMin) / (dMax - dMin); // Scaling data according to range

        o = new Object(100000, objFile);

        o->setMaterial(new Material(vec3(0.2f), getColorFromPalette(scaledData), vec3(1.0f), 1.0, 20.0f));
        // Una pequeña ñapa no puede faltar en todo código.
        o->aplicaTGG(new TranslateTG(vec3(fields[1].toDouble()+this->pMin.x, this->pMin.x, -fields[2].toDouble())));

        /* ANIMACIONES DE LA FASE 2 */
        /* En lugar de crear una nueva Scene factory sobreescribimos SceneFactoryData para simplificar */
        /* Aplicar animación a un objeto segun los datos leidos del fichero -> los datos de las animaciones se leen del fichero */
        //qDebug() << fields.size();
        if(fields.size() >= 7){
            Animation* orbit = new Animation();
            orbit->transf = new TranslateTG(vec3(fields[4].toDouble(), fields[5].toDouble(), fields[6].toDouble()));
            o->addAnimation(orbit);
        }

        this->scene->addObject(o);
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
