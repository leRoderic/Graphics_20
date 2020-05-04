#include "Material.h"


Material::Material() {
    this->diffuse = vec3(1.0f);
}

Material::Material(vec3 a, vec3 d, vec3 s, float alpha, float beta) {
    diffuse = d;
    ambient = a;
    specular = s;
    this->alpha = alpha; // Transparencia 1.0f
    this->beta = beta; // Shineness
}

/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(QGLShaderProgram *program){
}

vec3 Material::getDiffuse(vec2 point) const{
    return this->diffuse;
}

