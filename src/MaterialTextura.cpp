//
// Created by user on 1/4/20.
//

#include "MaterialTextura.h"

MaterialTextura::MaterialTextura(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha, const QString &textureFile) : Material(){
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->beta = beta;
    this->alpha = alpha;

    this->texture = new Texture(textureFile);
}

Texture* MaterialTextura::getTexture(void) const {return this->texture;}

void MaterialTextura::setTexture(Texture &texture) {
    this->texture = &texture;
}

bool MaterialTextura::scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {
    //vec3 target = rec.p + rec.normal + this->RandomInSphere();
    //r_out.push_back(Ray(rec.p, target - rec.p));
    //color = diffuse;
    return false;
}

vec3 MaterialTextura::getDiffuse(vec2 point) const{
    return  this->texture->getColorPixel(point);
}
