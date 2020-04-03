#include "Sphere.h"

Sphere::Sphere(vec3 cen, float r, float d) :Object(d) {
    center = cen;
    radius = r;
    factor = d;
}

bool Sphere::intersection(const Ray& raig, float t_min, float t_max, IntersectionInfo& info) const {
    vec3 oc = raig.initialPoint() - center;
    float a = dot(raig.dirVector(), raig.dirVector());
    float b = dot(oc, raig.dirVector());
    float c = dot(oc, oc) - radius*radius;
    float discriminant = b*b - a*c;
    if (discriminant > 0) {
        float temp = (-b - sqrt(discriminant))/a;
        if (temp < t_max && temp > t_min) {
            info.t = temp;
            info.p = raig.pointAtParameter(info.t);
            info.normal = (info.p - center) / radius;
            info.mat_ptr = material;
            return true;
        }
        temp = (-b + sqrt(discriminant)) / a;
        if (temp < t_max && temp > t_min) {
            info.t = temp;
            info.p = raig.pointAtParameter(info.t);
            info.normal = (info.p - center) / radius;
            info.mat_ptr = material;
            return true;
        }
    }
    return false;
}

void Sphere::aplicaTG(TG *t) {
    vec4 c(center, 1.0);
    c = t->getTG() * c;
    if (dynamic_cast<Translate *>(t)) {
        center.x = c.x;
        center.y = c.y;
        center.z = c.z;
    }
    if (dynamic_cast<Scale *>(t)) {
        this->radius *= t->matTG[0][0];
    }
}

