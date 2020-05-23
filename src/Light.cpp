#include "Light.h"

Light::Light(vec3 pos, vec3 ambient, vec3 diffuse, vec3 specular, vec3 atenuacio) {

    this->pos = pos;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->atenuacio = atenuacio;

}

Light::~Light() {

}

