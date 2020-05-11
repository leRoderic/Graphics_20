#include "Light.h"

/**
 * @brief Light::Light
 * @param t
 */
Light::Light(LightType t) {
    // TO DO: A canviar a la fase 1 de la practica 2
    ambient = vec3(0.2f);
    diffuse = vec3(0.8f);
    specular = vec3(1.0f);
    position = vec4(10,10,20,0.0f);
    direction = vec4(0.0f);
    atenuacio = vec3(0.0, 0.0, 0.0);
    this->type = t;
}


Light::Light(vec4 p, vec4 dir, vec3 a, vec3 d, vec3 s,vec3 ate, LightType t){
    this->position = p;
    this->direction = dir;
    this->ambient = a;
    this->diffuse = d;
    this->specular = s;
    this->atenuacio = ate;
    this->type = t;
}

/**
 * @brief Light::getDiffuseIntensity
 * @return
 */
vec3 Light::getId() {
    // TO DO: A canviar a la fase 1 de la practica 2
   return this->diffuse;
}

/**
 * @brief Light::setId
 * @param i
 */
void Light::setId(vec3 i) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->diffuse = i;
}

/**
 * @brief Light::getLightPosition
 */
vec4 Light::getLightPosition() {
    // TO DO: A canviar a la fase 1 de la practica 2
    return this->position;
}

/**
 * @brief Light::setLightPosition
 * @param v
 */
void Light::setLightPosition(vec4 v) {
    // TO DO: A canviar a la fase 1 de la practica 2
    this->position = v;
}


/**
 * @brief Light::getIa
 * @return
 */
vec3 Light::getIa() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return this->ambient;
}

/**
 * @brief Light::setIa
 * @param value
 */
void Light::setIa(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->ambient *= value;
}

/**
 * @brief Light::getIs
 * @return
 */
vec3 Light::getIs() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return this->specular;
}

/**
 * @brief Light::setIs
 * @param value
 */
void Light::setIs(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->specular *= value;
}

/**
 * @brief Light::getCoeficients
 * @return
 */
vec3 Light::getCoeficients() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
       return this->atenuacio;
}

/**
 * @brief Light::setCoeficients
 * @param value
 */
void Light::setCoeficients(const vec3 &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    this->atenuacio *= value;
}


/**
 * @brief Light::getTipusLight
 *
 */
LightType Light::getTipusLight() const
{
    // TO DO: A canviar a la fase 1 de la practica 2

    //return (!this->direction)? Puntual: Direccional;
    /*if(this->direction.x == 0.0 && this->direction.y == 0.0 && this->direction.z == 0.0 && this->direction.w == 0.0 )
        return Puntual;
    return Direccional;*/
    return this->type;
}

/**
 * @brief Light::setTipusLight
 * @param value
 */
void Light::setTipusLight(const LightType &value)
{
    // TO DO: A canviar a la fase 1 de la practica 2
    switch(value) {
        case Puntual:
            this->direction = vec4(0.0);
            break;
        case Direccional:
            break;
        case Spot:
            break;
    }
    this->type = value;
}
