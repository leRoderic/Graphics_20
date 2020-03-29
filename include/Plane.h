#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Animation.h"
#include "Translate.h"
#include "glm/gtx/constants.hpp"


class Plane: public Object{
public:
    Plane(vec3 normal, vec3 pass_point, float v);

    Plane(vec3 normal, float d, float v);

    virtual ~Plane(){}
    virtual bool intersection(const Ray &r, float t_min, float t_max, IntersectionInfo &info) const;
    virtual void aplicaTG(TG *t);

protected:
    vec3 normal;
    vec3 point;
};

#endif // PLANE_H
