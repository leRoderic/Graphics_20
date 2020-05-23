//
// Created by oornaqbl13.alumnes on 9/3/20.
//

#ifndef RAYDATA_FITTEDPLANE_H
#define RAYDATA_FITTEDPLANE_H


#include "Plane.h"

class FittedPlane : public Plane {

public:
    FittedPlane(vec3 normal, vec3 pass_point, float v);

    FittedPlane(vec3 limit1, vec3 limit2, vec3 normal, float d, float v);

    FittedPlane(vec3 normal, float d, float v);

    virtual ~FittedPlane(){}
    virtual bool intersection(const Ray &r, float t_min, float t_max, IntersectionInfo &info) const;
    virtual void aplicaTG(TG *t);


protected:
    vec3 p1;
    vec3 p2;

private:


};


#endif //RAYDATA_FITTEDPLANE_H
