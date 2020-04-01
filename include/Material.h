#ifndef MATERIAL_H
#define MATERIAL_H

#include <vector>
#include "Ray.h"
#include "Hitable.h"


// Classe abstracte Material. Totes les seves filles hauran de definir el metode abstracte sccater
class Material {
public:

    Material();

    Material(vec3 a, vec3 d, vec3 s, float alpha, float beta);

    ~Material();

    virtual bool scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const = 0;

    /*Para todos los materiales devolver diffuse
    (MaterialTextura sobrecarga esta función para devolver el téxel*/
    virtual vec3 getDiffuse(vec2 point) const;

    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float alpha;
    int beta;


protected:
    vec3 RandomInSphere() const;
};

#endif // MATERIAL_H
