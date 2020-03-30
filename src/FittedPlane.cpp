//
// Created by oornaqbl13.alumnes on 9/3/20.
//

#include "FittedPlane.h"

FittedPlane::FittedPlane(vec3 normal, vec3 pass_point, float v) : Plane(normal, pass_point, v) {
    /* TO-DO pasar por parametros al constructor los limites p1 y p2 */
    this->p1 = normal;
    this->p2 = pass_point;
}

FittedPlane::FittedPlane(vec3 limit1, vec3 limit2, vec3 normal, float d, float v) : Plane(normal, d, v) {
    //this->normal = normal;
    this->p1 = limit1;
    this->p2 = limit2;
}

FittedPlane::FittedPlane(vec3 normal, float d, float v) : Plane(normal, d, v) {
    /* TO-DO pasar por parametros al constructor los limites p1 y p2 */
    this->p1 = normal;
    this->p2 = vec3(0, 0, 0);
};

bool FittedPlane::intersection(const Ray &raig, float t_min, float t_max, IntersectionInfo &info) const {
    if (Plane::intersection(raig, t_min, t_max, info)) {
        if (info.p.x <= p1.x && info.p.x >= p2.x && info.p.z <= p1.y && info.p.z >= p2.y) {
            return true;
        }
    }
    return false;
}

void FittedPlane::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {
        // Nomes movem el punt de pas
        vec4 newp(this->point, 1.0);
        newp = t->getTG() * newp;
        this->point.x = newp.x;
        this->point.y = newp.y;
        this->point.z = newp.z;
    }
    if (dynamic_cast<Scale *>(t)) {
        //consideramos la y del p2 y p1 como la componente z, usamos un vec2 para definir la xmin/max y zmin/max.
        vec4 cmin(p2.x, 1.0, p2.y, 1.0);
        vec4 cmax(p1.x, 1.0, p1.y, 1.0);
        cmin = t->getTG() * cmin;
        cmax = t->getTG() * cmax;
        p2.x *= cmin.x;
        p2.y *= cmin.z;
        p1.x *= cmax.x;
        p1.y *= cmax.z;
    }

}