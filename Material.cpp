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
    GL_Material.a = program->uniformLocation("material.ambient");
    GL_Material.s = program->uniformLocation("material.specular");
    GL_Material.beta = program->uniformLocation("material.beta");
    GL_Material.alpha = program->uniformLocation("material.alpha");

    glUniform3fv(GL_Material.d, 1, this->diffuse);
    glUniform3fv(GL_Material.a, 1, this->ambient);
    glUniform3fv(GL_Material.s, 1, this->specular);
    glUniform1f(GL_Material.beta, this->beta);
    glUniform1f(GL_Material.alpha, this->alpha);
}

vec3 Material::getDiffuse() const{
    return this->diffuse;
}

