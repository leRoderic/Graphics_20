#include "Triangle.h"

Triangle::Triangle(vec3 p1, vec3 p2, vec3 p3, float aux, float d) : Object(d) {

    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    this->normal = normalize(cross(p2 - p1, p3 - p1));
}

bool Triangle::intersection(const Ray &raig, float t_min, float t_max, IntersectionInfo &info) const {

    if (dot(raig.dirVector(), normal) == 0) return false;

    float d = -normal[0] * p1.x - normal[1] * p1.y - normal[2] * p1.z; //

    vec3 rp = raig.initialPoint();
    vec3 vp = raig.dirVector();

    float temp = -normal[0] * rp[0] - normal[1] * rp[1] - normal[2] * rp[2] - d; //
    temp /= normal[0] * vp[0] + normal[1] * vp[1] + normal[2] * vp[2]; //
    vec3 point = raig.pointAtParameter(temp); //

    float e1 = dot(cross((p3 - p1), (point - p1)), normal);
    float e2 = dot(cross((p2 - p3), (point - p3)), normal);
    float e3 = dot(cross((p1 - p2), (point - p2)), normal);

    if ((e1 < 0 && e2 < 0 && e3 < 0) || (e1 > 0 && e2 > 0 && e3 > 0)) {
        if (temp < t_max && temp > t_min) {
            info.t = temp;
            info.p = point;
            info.normal = normal;
            info.mat_ptr = material;
            return true;
        } else {
            info.t = temp;
            info.p = point;
            info.normal = -normal;
            info.mat_ptr = material;
            return true;
        }
    }
    return false;
}

void Triangle::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {

        vec4 newp(p1, 1.0);
        newp = t->getTG() * newp;
        p1.x = newp.x;
        p1.y = newp.y;
        p1.z = newp.z;
    }
}
