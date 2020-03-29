
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

    vec3 N = normalize(rec.normal);//Normal a la intersecció
    vec3 V = normalize(r_in.dirVector());//Vector del raig incident
    float cos = dot(N, V);//Cos de la Normal i el raig incident
    float snell = 1.0003f / refraccio;// medi2 / medi1
    vec3 p0 = rec.p;//punt d'intersecció

    if (cos > 0.01) {//Contrari
        N = -N;
        snell = 1.f / snell;
    }

    vec3 v_refract = refract(V, N, snell);// vector refractat normalitzat
    r_out.push_back(Ray(p0, v_refract));//raig refractat
    color = vec3(alpha);

    if (dot(v_refract, v_refract) < 0.01) {//No hi ha refracció sinó reflexió
        vec3 v_reflect = reflect(V, N);//vector reflectit normalitzat
        r_out.push_back(Ray(p0, v_reflect));//raig reflectit
        color = specular;
    }

    return true;
}
