#include "Material.h"

Material::Material() {
    this->diffuse = vec3(1.0f);
}

Material::~Material()
{}

Material::Material(vec3 a, vec3 d, vec3 s, float alpha, float beta) {
    diffuse = d;
    ambient = a;
    specular = s;
    this->alpha = alpha; // Transparencia 1.0f
    this->beta = beta; // Shineness
}

vec3 Material::RandomInSphere() const {
    vec3 p;
    do {
        p = 2.0f*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    } while (glm::length(p) >=  1.0f);
    return p;
}

vec3 Material::getDiffuse(vec2 point) const{
    return this->diffuse;
}
