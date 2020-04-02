//
// Created by user on 1/4/20.
//

#include "MaterialTextura.h"
MaterialTextura::MaterialTextura(const QString &textureFile) : Material(){
    this->diffuse = vec3(0.2,0.2,1.0);//0.5,0.5,0.5
    this->specular = vec3(0.0,0.0,0.0);
    this->ambient = vec3(0.1,0.1,0.1);
    this->alpha = 0.0;
    this->beta = 1.0;
    this->texture = new Texture(textureFile);
}

MaterialTextura::MaterialTextura(const vec3 &ambient, const vec3 &diffuse, const vec3 &specular, const int &beta, const float &alpha, const QString &textureFile) : Material(){
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
    this->beta = beta;
    this->alpha = alpha;

    this->texture = new Texture(textureFile);
}

bool MaterialTextura::scatter(const Ray &r_in, const IntersectionInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {
    return false;
}

vec3 MaterialTextura::getDiffuse(vec2 point) const{
    return  this->texture->getColorPixel(point);
}

MaterialTextura::~MaterialTextura() {

    delete this->texture;
}
