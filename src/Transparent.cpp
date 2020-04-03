
#include "Transparent.h"

Transparent::Transparent(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta,
                         const float &alpha, const float &refraccio)
        : Material() {
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->beta = beta;
    this->alpha = alpha;
    this->refraccio = refraccio;
}

Transparent::~Transparent() {

}

bool Transparent::scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {

    vec3 N = normalize(rec.normal);
    vec3 V = normalize(r_in.dirVector());
    float cos = dot(N, V);
    float snell = 1.0003f / refraccio;
    vec3 p0 = rec.p;

    if (cos > 0.01) {
        N = -N;
        snell = 1.f / snell;
    }

    vec3 v_refract = refract(V, N, snell);
    r_out.push_back(Ray(p0, v_refract));
    color = vec3(alpha);

    if (dot(v_refract, v_refract) < 0.01) {
        vec3 v_reflect = reflect(V, N);
        r_out.push_back(Ray(p0, v_reflect));
        color = specular;
    }

    return true;
}
