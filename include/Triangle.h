//
// Created by QIJUN JIN on 02/03/2020.
//

#ifndef RAYDATA_TRIANGLE_H
#define RAYDATA_TRIANGLE_H

#include "Object.h"
#include "Animation.h"
#include "Translate.h"
#include <vector>
#include "Ray.h"
#include "Hitable.h"
#include "Animation.h"
#include "Object.h"
#include "Sphere.h"
#include "Lambertian.h"
#include "ColorMap.h"

class Triangle : public Object {

public:

    Triangle(vec3 p1, vec3 p2, vec3 p3, float aux, float data);

    virtual ~Triangle() {}

    virtual bool intersection(const Ray &r, float t_min, float t_max, IntersectionInfo &info) const;

    virtual void aplicaTG(TG *t);

private:

    vec3 p1;
    vec3 p2;
    vec3 p3;
    vec3 normal;

};


#endif
