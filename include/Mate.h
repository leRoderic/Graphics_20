//
// Created by Qijun Jin on 27/03/2020.
//

#ifndef RAYDATA_MATE_H
#define RAYDATA_MATE_H

#include "Material.h"

class Mate : public Material {

public:
    Mate(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha);

    virtual ~Mate();

    virtual bool scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const;
};


#endif //RAYDATA_MATE_H


