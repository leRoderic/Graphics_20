//
// Created by abdel on 06/03/2020.
//

#include <iostream>
#include "Cylinder.h"

Cylinder::Cylinder(vec3 center, float height, float d) : Object(d) {
    this->center = center;
    this->radius = 1.0f;
    this->height = height;
    this->normal1 = vec3(0.0,1.0,0.0);
    this->normal2 = vec3(0.0,-1.0,0.0);
    this->top1 = new Circle(normal1, this->center + vec3(0, height, 0), radius);
    this->top2 = new Circle(normal2, this->center, radius);
}

Cylinder::~Cylinder() {
    delete top1;
    delete top2;
}

//Interseccio amb els laterals del cilindre
bool Cylinder::intersect(const Ray &raig, float t_min, float t_max, IntersectionInfo &info) const {
    //https://inmensia.com/articulos/raytracing/cilindroycono.html
    /*Equacio a resoldre per a trobar la intersecció-> a*t^2 + b*t + c = 0 on:
    *
     * a = dx’^2 + dz’^2
     * b = 2 * (ox’ * dx’ + oz’ * dz’) --> (d = d - centre)
     * c = ox’^2 + oz’^2 – 1 --> (d = d - centre)
    */
    float a = ((raig.dirVector().x * raig.dirVector().x) + (raig.dirVector().z * raig.dirVector().z));
    float b = 2 * (raig.dirVector().x * (raig.initialPoint().x - center.x) +
                   raig.dirVector().z * (raig.initialPoint().z - center.z));
    float c = ((raig.initialPoint().x - center.x) * (raig.initialPoint().x - center.x)) +
              ((raig.initialPoint().z - center.z) * (raig.initialPoint().z - center.z)) - 1;
    float discriminant = b * b - 4 * a * c;
    float temp1, temp2; //(-b +- SQRT(b² – 4 * a * c) ) / (2 * a)
    //Si a < EPSILON o l'arrel es < que ESPSILON, llavors no hi ha intersecció
    if (a < EPSILON || discriminant < EPSILON) {
        return false;
    }
        //Raig tangent al cilindre, una unica intersecció
    else if (discriminant > 0 - EPSILON && discriminant < 0 + EPSILON) {
        temp1 = temp2 = -b / (2 * a);
    }
        //Sino tenim 2 interseccions i hem d'agafar la mes petita
    else {
        temp1 = (-b + sqrtf(discriminant))/(2 * a);
        temp2 = (-b - sqrtf(discriminant))/(2 * a);
    }
    if(temp2 < temp1 && temp2 >= 0){
        temp1 = temp2;
    }
    if(temp1 < 0){
        return false;
    }
    if(temp1 < t_max+EPSILON && temp1 > t_min-EPSILON){
        //Calculem les coordenades del punt d'intersecció.
        vec3 t = raig.pointAtParameter(temp1);
        //Si la intersecció és més petita que l'alçada, voldra dir es troba dins del cilindre.
        if (t.y < center.y + height + EPSILON && t.y > center.y - EPSILON) {
            info.t = temp1;
            info.p = raig.pointAtParameter(info.t);
            info.normal = (info.p - center)/radius;
            info.mat_ptr = material;
            return true;
        }
    }
    return false;
}

bool Cylinder::intersection(const Ray& raig, float t_min, float t_max, IntersectionInfo& info) const {
    bool intersecta = false;
    float intersect_cilindre(std::numeric_limits<float>::infinity());
    float intersect_top1(std::numeric_limits<float>::infinity());
    float intersect_top2(std::numeric_limits<float>::infinity());

    //calcul de'interseccions

    if (intersect(raig, t_min, t_max, info)) {
        intersect_cilindre = info.t;
        intersecta = true;
    }
    if (top1->intersection(raig, t_min, t_max, info)) {
        intersect_top1 = info.t;
        intersecta = true;
    }
    if (top2->intersection(raig, t_min, t_max, info)) {
        intersect_top2 = info.t;
        intersecta = true;
    }
    if(intersecta) {
        float temp(std::numeric_limits<float>::infinity());
        //Busquem la intersecció mes petita
        if (intersect_cilindre < temp) {
            temp = intersect_cilindre;
        }
        if (intersect_top1 < temp) {
            temp = intersect_top1;
        }
        if (intersect_top2 < temp) {
            temp = intersect_top2;
        }
        info.t = temp;
        info.p = raig.pointAtParameter(info.t);
        info.normal = vec3(info.p.x,0,info.p.z);
        info.mat_ptr = material;
    }
    return intersecta;
}

void Cylinder::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {
        vec4 c(center, 1.0);
        c = t->getTG() * c;
        center.x = c.x;
        center.y = c.y;
        center.z = c.z;

        std::cerr << "Cylinder translated to " << center.x << ", " << center.y << ", " << center.z << std::endl;
    }
    //Augmentem l'altura
    if (dynamic_cast<Scale *>(t)) {
        vec4 c(1.0, 1.0, 1.0, 1.0);
        c = t->getTG() * c;
        this->height *= c.x;
        std::cerr << "Cylinder scaled by " << t->matTG[0][0] << std::endl;
    }
    //reconstruim tapes
    if (top1 != NULL) {
        delete top1;
        top1 = new Circle(normal1, this->center + vec3(0, height, 0), radius);
    }
    if (top2 != NULL) {
        delete top2;
        top2 = new Circle(normal2, this->center, radius);
    }

}