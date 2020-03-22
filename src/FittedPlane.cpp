//
// Created by oornaqbl13.alumnes on 9/3/20.
//

#include "FittedPlane.h"

FittedPlane::FittedPlane(vec3 normal, vec3 pass_point, float v) : Plane(normal, pass_point, v){
    /* TODO pasar por parametros al constructor los limites p1 y p2 */
    this->p1 = normal;
    this->p2 = pass_point;
}

FittedPlane::FittedPlane(vec3 normal, float d, float v) : Plane(normal, d, v) {
    /* TODO pasar por parametros al constructor los limites p1 y p2 */
    this->p1 = normal;
    this->p2 = vec3(0, 0, 0);
};

bool FittedPlane::intersection(const Ray &raig, float t_min, float t_max, IntersectionInfo &info) const{

    /* TODO interseccion solo posible dentro de los limites p1 y p2 */
    // Comprovem interseccio entre el pla i el raig

    // Comprovem si el normal al pla i el raig son ortogonals.
    // En aquest cas son paralels i no hi ha interseccio

    if(dot(raig.dirVector(), normal) == 0){
        return false;
    }

    // En els altres casos hi haurà interseccio (si estem en el rang de min/max).
    // Cal omplir la info.

    // PLA: Ax+By+Cz+D=0
    // on A,B,C = normal

    // 1) Calculem la D = -Ax-By-Cz
    float d = -normal[0]*point[0] - normal[1]*point[1] - normal[2]*point[2];

    // 2) Imposem que la recta p+tv compleixi l'eq del pla
    // A(p1 + tv1) + ... + D = 0
    // Aillem la t

    vec3 rp = raig.initialPoint();
    vec3 vp = raig.dirVector();
    float temp =  -normal[0]*rp[0] - normal[1]*rp[1] - normal[2]*rp[2] - d;

    temp/= normal[0]*vp[0] + normal[1]*vp[1] + normal[2]*vp[2];

    // Retornem false si no estem en el rang demanat
    if (temp > t_max || temp < t_min) {
        return false;
    }

    // Omplim el camp de info:

    info.t = temp;
    info.p = raig.pointAtParameter(info.t);

    // La normal a un pla es la mateixa per tots els punts
    info.normal = normal;
    info.mat_ptr = material;
    return true;
}

void FittedPlane::aplicaTG(TG *t){
    if (dynamic_cast<Translate *>(t)) {

        // Nomes movem el punt de pas
        vec4 newp(this->point, 1.0);
        newp = t->getTG() * newp;
        this->point.x = newp.x;
        this->point.y = newp.y;
        this->point.z = newp.z;
    }

}

