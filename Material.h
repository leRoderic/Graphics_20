#ifndef MATERIAL_H
#define MATERIAL_H

#include "library/Common.h"
#include <QGLShaderProgram>


// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    Material();
    Material(vec3 a, vec3 d, vec3 s, float alpha, float beta);

    void toGPU(QGLShaderProgram *program);

    vec3 getDiffuse(vec2 point) const;

    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float alpha;
    int beta;

protected:
    GLuint buffer;

};

#endif // MATERIAL_H
