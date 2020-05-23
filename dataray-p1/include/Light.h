#ifndef LIGHT_H
#define LIGHT_H

#include "Ray.h"

class Light {
public:

    Light(vec3 pos, vec3 ambient, vec3 diffuse, vec3 specular, vec3 atenuacio);

    virtual ~Light();


    vec3 pos;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 atenuacio;

};

#endif //LIGHT_H
