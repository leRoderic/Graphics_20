#include "DataReader.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <sstream>
#include <include/ObjectFactory.h>
#include <include/Mate.h>
#include <include/MaterialTextura.h>

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

// TO-DO: Fase 1: Cal afegir més tipus d'objectes
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

    Object *o;

    if (QString::compare(" plane", fields[1], Qt::CaseInsensitive) == 0) {
        // TO-DO Fase 1: Cal fer un pla acotat i no un pla infinit. Les dimensions del pla acotat seran les dimensions de l'escena en x i z


        float y = -1.0f;
        y = fields[5].toDouble();

        /*float dx = (xMax - xMin)/2;
        float dz = (zMax - zMin)/2;
        vec3 p1 = vec3(xMin - xMin - dx, y, zMin - zMin - dz);
        vec3 p2 = vec3(xMax - xMax + dx, y, zMax - zMax + dz);*/
        pMin = vec3(-5, -5, -5);
        pMax = vec3(5, 5, 5);

        o = ObjectFactory::getInstance()->createObject(pMin.x, y, pMin.z, pMax.x, y, pMax.z, fields[2].toDouble(),
                                                       fields[3].toDouble(), fields[4].toDouble(),
                                                       y, 0, ObjectFactory::OBJECT_TYPES::FITTED_PLANE);
        o->setMaterial(new MaterialTextura(vec3(1), vec3(1), vec3(1), 1, 1, fields[6].simplified()));
        //Fase 1 / 3.2 / b / a
        scene->ground = (FittedPlane *) o;
        // TODO Fase 4: llegir textura i afegir-la a l'objecte. Veure la classe Texture
    }else if(QString::compare(" sphere", fields[1], Qt::CaseInsensitive) == 0){
        // TO-DO: Fase 3: Si cal instanciar una esfera com objecte base i no un pla, cal afegir aqui un else
        o = ObjectFactory::getInstance()->createObject(fields[2].toDouble(), fields[3].toDouble(),
                                                       fields[4].toDouble(), 0, 0, 0, 0, 0, 0,
                                                       fields[5].toDouble(), 0, ObjectFactory::OBJECT_TYPES::SPHERE);
        scene->ground = (Sphere *) o;

    }

    //scene->objects.push_back(o);

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
    cout<<fields[4].toStdString()<<endl;
    if (QString::compare(" sphere", fields[4], Qt::CaseInsensitive) == 0) {
        spMin = fields[2].toDouble();
        spMax = fields[3].toDouble();
        props.push_back(ObjectFactory::OBJECT_TYPES::SPHERE);
    }else if (QString::compare(" cylinder", fields[4], Qt::CaseInsensitive) == 0) {
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
    float scaledX, scaledZ, scaledData;

    for (int i=0; i<numProp; i++) {
        // TODO Fase 1: Cal colocar els objectes al seu lloc del mon virtual, escalats segons el valor i
        //  amb el seu color corresponent segons el seu ColorMap

        //obenim Xscene = ((Xread - Xminread)*(Xmaxscene - Xminscene) / (Xmaxread - Xminread)) + Xminscene
        //scaledX = ((fields[1].toDouble() - pMin.x)*(xMax - xMin) / (pMax.x - pMin.x)) + pMin.x;
        //scaledZ = ((fields[2].toDouble() - pMin.z)*(zMax - zMin) / (pMax.z - pMin.z)) + pMin.z;
        scaledX = (fields[1].toDouble() - xMin) / (xMax - xMin) * (pMax.x - pMin.x) + pMin.x;
        scaledZ = pMax.z - (fields[2].toDouble() - zMin) / (zMax - zMin) * (pMax.z - pMin.z);
        /*vec3 planeCenter(xMax-xMin, 0, zMax - zMin);
        vec3 pos(scaledX*planeCenter.x, 0, scaledZ*planeCenter.z);
        scaledX = pos.x;
        scaledZ = pos.z;*/

        if (props.back() == ObjectFactory::OBJECT_TYPES::SPHERE) {

            //scaledData = (((fields[3].toDouble() - spMin) * (255 - 0)) / (spMax - spMin)) + 0;
            scaledData = (fields[3].toDouble() - spMin) / (spMax - spMin);
            o = ObjectFactory::getInstance()->createObject(scaledX, 0.0f, scaledZ, scaledZ, 0, scaledX, scaledZ, 0,
                                                           scaledX, 1, scaledData, props.back());
            //o->aplicaTG(new Translate(vec3(scaledX,0,scaledZ)));
            o->setMaterial(new Mate(vec3(0.2f), vec3(0.8, 0.8, 0), vec3(1.0f), 10, 0.0f));
            o->aplicaTG(new Scale(vec3(scaledData)));
        } else if (props.back() == ObjectFactory::OBJECT_TYPES::CYLINDER) {
            scaledData = (((fields[3].toDouble() - cyMin) * (255 - 0)) / (cyMax - cyMin)) + 0;
            o =  ObjectFactory::getInstance()->createObject(scaledX, 0.0f, scaledZ,0, 0, 0, 0, 0, 0, 2, scaledData, props.back());
        }else if(props.back() == ObjectFactory::OBJECT_TYPES::BROBJECT) {
            scaledData = (((fields[3].toDouble() - brMin) * (255 - 0)) / (brMax - brMin)) + 0;
            o =  ObjectFactory::getInstance()->createObject(objFile, scaledData, props.back());
        }

        scene->objects.push_back(o);
    }
}
