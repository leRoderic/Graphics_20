//
// Created by Qijun Jin on 28/03/2020.
//

#ifndef RAYDATA_METALL_H
#define RAYDATA_METALL_H

#include "Material.h"

class Metall : public Material {

public:
    Metall(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha);

    virtual ~Metall();

    virtual bool scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const;
};


#endif //RAYDATA_METALL_H

