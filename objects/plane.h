#ifndef PLANE_H
#define PLANE_H

#include "library/Common.h"
#include "cara.h"
#include <QObject>
#include <vector>
#include <QGLShaderProgram>
#include <QOpenGLTexture>
#include <QFile>
#include <QRegularExpression>
#include <QDebug>
#include <QString>
#include <QStringList>
#include "./TG/TG.h"
#include "Material.h"
#include "Object.h"

class Plane: public Object {
public:

    Plane(vec4 v1, vec4 v2, vec4 v3, vec4 v4);
    ~Plane();

};

#endif // PLANE_H
