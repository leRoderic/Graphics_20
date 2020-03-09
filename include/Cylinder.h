//
// Created by abdel on 06/03/2020.
//

#ifndef CYLINDER_H
#define CYLINDER_H

#include "Object.h"
#include "Animation.h"
#include "Translate.h"
#include "Circle.h"


class Cylinder: public Object  {
public:
    Cylinder(vec3 center, float radius, float high);
    virtual ~Cylinder();
    virtual bool intersection(const Ray& r, float t_min, float t_max, IntersectionInfo& info) const;
    bool intersect(const Ray& r, float t_min, float t_max, IntersectionInfo& info) const;
    virtual void aplicaTG(TG *t);
private:
    // Centre cilindre
    vec3 center;
    // Radi cilindre
    float radius;
    // Altura cilindre
    float high;

    double const EPSILON = 0.0000000000001;

    Circle *top1;
    Circle *top2;
    vec3 normal1;
    vec3 normal2;

};


#endif //CYLINDER
