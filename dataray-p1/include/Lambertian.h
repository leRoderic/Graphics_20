#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material
{

public:
    Lambertian(const vec3& color);
    virtual ~Lambertian();
    virtual bool scatter(const Ray& r_in, const IntersectionInfo& rec, vec3& color, std::vector<Ray>& r_out) const;
};

#endif // LAMBERTIAN_H
