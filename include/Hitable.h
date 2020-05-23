#ifndef HITABLE_H
#define HITABLE_H

/*
 * File:   hitable.h
 * Author: anna
 *
 * Created on 17 de enero de 2020, 17:45
 */

#include "Ray.h"

class Material;

class IntersectionInfo
{
public:
    float     t; // t del raig on s'ha intersecat
    vec3      p;  // punt del raig on hi ha la intersecció
    vec3      normal; // normal en el punt d'intersecció
    const Material *mat_ptr; // material de l'objecte que s'ha intersectat

    IntersectionInfo():
        t(std::numeric_limits<float>::infinity()),
        p(0.0f),
        normal(0.0f),
        mat_ptr(NULL)
        {}

    //  "operator =" per la classe  IntersectionInfo
    IntersectionInfo &operator =(const IntersectionInfo &rhs) {
      p = rhs.p;
      mat_ptr = rhs.mat_ptr;
      normal = rhs.normal;
      t = rhs.t;
      return *this;
    }
};

class Hitable
{
public:
    Hitable();
    ~Hitable();
    // S'obliga a implementar-lo en les classes filles: es un metode abstracte
    virtual bool intersection(const Ray& r, float t_min, float t_max, IntersectionInfo& info) const = 0;
};

#endif // HITABLE_H
