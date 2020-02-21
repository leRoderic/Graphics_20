#include "Material.h"



Material::Material():
    diffuse(1.0f)
  {}

Material::~Material()
{}

Material::Material(vec3 a, vec3 d, vec3 s, vec3 k, float beta){
    diffuse = d;
}

vec3 Material::RandomInSphere() const {
    vec3 p;
    do {
        p = 2.0f*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    } while (glm::length(p) >=  1.0f);
    return p;
}

