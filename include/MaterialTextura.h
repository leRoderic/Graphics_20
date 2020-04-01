//
// Created by user on 1/4/20.
//

#ifndef RAYDATA_MATERIALTEXTURA_H
#define RAYDATA_MATERIALTEXTURA_H

#include "Texture.h"
#include "Material.h"


class MaterialTextura : public Material {

public:
    MaterialTextura(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha, const QString &textureFile);
    ~MaterialTextura();

    Texture* getTexture(void) const;
    void setTexture(Texture& texture);

    virtual bool scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const;

protected:
    Texture* texture;

private:


};


#endif //RAYDATA_MATERIALTEXTURA_H
