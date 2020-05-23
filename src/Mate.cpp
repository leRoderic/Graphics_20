//
// Created by Qijun Jin on 27/03/2020.
//

#include "Mate.h"

Mate::Mate(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha)
        : Material() {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->beta = beta;
    this->alpha = alpha;
}

Mate::~Mate() {

}

bool Mate::scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {
    vec3 target = rec.p + rec.normal + this->RandomInSphere();
    r_out.push_back(Ray(rec.p, target - rec.p));
    color = diffuse;
    return true;
}
