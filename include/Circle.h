//
// Created by abdel on 08/03/2020.
//

#ifndef CIRCLE_H
#define CIRCLE_H


#include "Object.h"
#include "Animation.h"
#include "Translate.h"
#include "Plane.h"

class Circle : public Plane{

public:
    Circle(vec3 normal, vec3 pass_point , float radius);
    virtual ~Circle(){}
    virtual bool intersection(const Ray& r, float t_min, float t_max, IntersectionInfo& info) const;

    virtual void aplicaTG(TG *t);

private:
    vec3 normal;
    vec3 center;
    float radius;
    double const EPSILON = 0.000001;
};


#endif //CIRCLE_H
