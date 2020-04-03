//
// Created by abdel on 08/03/2020.
//

#include "Circle.h"

Circle::Circle(vec3 normal, vec3 pass_point, float radius) : Plane(normal, pass_point, radius) {
    this->normal = normal;
    this->center = pass_point;
    this->radius = radius;
}

bool Circle::intersection(const Ray& raig, float t_min, float t_max, IntersectionInfo& info) const {
    //Comprovem que hi ha interseccio amb el pla.
    if (Plane::intersection(raig, t_min, t_max, info)) {
        float x2 = (info.p.x - center.x) * (info.p.x - center.x);
        float z2 = (info.p.z - center.z) * (info.p.z - center.z);
        //Equacio d'un cercle (x - cx)²+ (z - cz)² = r
        //Comprovar que el punt d'interseccio es troba dins del cercle.
        if ((x2 + z2) - radius <= EPSILON && (x2 + z2) >= EPSILON) {
            return true;
        }
    }
    return false;
}

void Circle::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {
        vec4 c(center, 1.0);
        c = t->getTG() * c;
        center.x = c.x;
        center.y = c.y;
        center.z = c.z;
    }
    if (dynamic_cast<Scale *>(t)) {
        this->radius *= t->matTG[0][0];
    }
}
