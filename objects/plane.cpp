#include "plane.h"
#include <cmath>

Plane::Plane(vec4 v1, vec4 v2, vec4 v3, vec4 v4):Object(6, NULL){

    this->points[0] = v1;
    this->points[1] = v2;
    this->points[2] = v3;
    this->points[3] = v4;
    this->points[4] = v2;
    this->points[5] = v3;

    this->normals[0] = vec4(0,1,0,0);
    this->normals[1] = vec4(0,1,0,0);
    this->normals[2] = vec4(0,1,0,0);
    this->normals[3] = vec4(0,1,0,0);
    this->normals[4] = vec4(0,1,0,0);
    this->normals[5] = vec4(0,1,0,0);

    this->texCoord[0] = vec2(0,0);
    this->texCoord[1] = vec2(1,0);
    this->texCoord[2] = vec2(0,1);
    this->texCoord[3] = vec2(1,1);
    this->texCoord[4] = vec2(1,0);
    this->texCoord[5] = vec2(0,1);

    this->material = new Material();

}

Plane::~Plane(){
    delete this->material;
}
