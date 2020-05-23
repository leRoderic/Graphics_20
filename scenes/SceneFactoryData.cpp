#include "SceneFactoryData.h"
#include "Light.h"

#include <objects/plane.h>

SceneFactoryData::SceneFactoryData()
{

}

Scene *SceneFactoryData::createScene(QString filename) {
    return nullptr;
}

Scene *SceneFactoryData::makeScene(QString filename, QString gObj, QString cmFile, float xmin, float y, float zmin,
                                     float xmax, float zmax) {
    Scene *s = new Scene();

    DataReader *sc = new DataReader(s);
    sc->setParameters(vec4(xmin, y, zmin, 1), vec4(xmax, y, zmax, 1), gObj, this->createColorMap(cmFile));

    Plane *p = new Plane(vec4(xmin, y, zmin, 1), vec4(xmax, y, zmin, 1), vec4(xmin, y, zmax, 1), vec4(xmax, y, zmax, 1));
    p->setTexture(new QOpenGLTexture(QImage("://resources/textures/2k_venus_surface.jpg")));
    s->addObject(p);

    sc->readFile(filename);
    s->lightAmbientGlobal = vec3(0.3f);

    Light *light = new Light(vec4(10, 20, 20,0), vec4(0.0f),vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Puntual);
    //light->setTipusLight(Puntual);
    s->addLight(light);

    //Light *dir_light = new Light(vec4(10, 20, 20,0), vec4(1.0f),vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Direccional);
    //dir_light->setTipusLight(Direccional);
    //s->addLight(dir_light);

    Light* spotlight = new Light(vec4(10, 20, 20, 0), vec4(1.0f), vec3(0.2f), vec3(0.8f), vec3(1.0f), vec3(0.0f), Spot, 0.25);
    s->addLight(spotlight);

    return s;
}

vector<vec3> SceneFactoryData::createColorMap(QString f) {

    QFile file(f);
    vector<vec3> colors;

    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Error opening the file" << std::endl;
        return colors;
    }
    // Reads .GPL files from ColorBrewer, ONLY. Don't try other .GPL sources. This is not bulletproof.
    QTextStream in(&file);
    QRegExp re("\\d*");

    while (!in.atEnd()) {
        QString line = in.readLine();

        QStringList fields = line.split(" ");
        if (QString::compare("Name:", fields[0], Qt::CaseInsensitive) == 0){
            qDebug() << "Reading color palette file: " + fields[1];
        }
        else if (re.exactMatch(fields[0])){
            colors.push_back(vec3(fields[0].toInt()/255, fields[1].toInt()/255, fields[2].toInt()/255));
        }
    }
    qDebug() << QString::number(colors.size()) + " colors read";
    file.close();

    return colors;
}
