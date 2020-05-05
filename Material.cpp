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

    GL_Material.d = program->uniformLocation("material.diffuse");

    glUniform3fv(GL_Material.d, 1, this->diffuse);
}

vec3 Material::getDiffuse() const{
    return this->diffuse;
}

