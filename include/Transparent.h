

#ifndef RAYDATA_TRANSPARENT_H
#define RAYDATA_TRANSPARENT_H

#include "Material.h"

class Transparent : public Material {

public:
    Transparent(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha,
                const float &refraccio);

    virtual ~Transparent();

    virtual bool scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const;

    float refraccio;

};


#endif //RAYDATA_TRANSPARENT_H

