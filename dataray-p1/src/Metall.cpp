

#include "Metall.h"

Metall::Metall(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha)
        : Material() {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->beta = beta;
    this->alpha = alpha;
}

Metall::~Metall() {

}

bool Metall::scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {

    vec3 v = reflect(normalize(rec.p - r_in.initialPoint()), rec.normal); // Vector de reflexió
    vec3 p0 = rec.p + vec3(0.01) * v; // Tractar acné
    r_out.push_back(Ray(p0, v));
    color = specular;
    return true;
}
