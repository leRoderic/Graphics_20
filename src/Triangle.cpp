#include "Triangle.h"

Triangle::Triangle(vec3 p1, vec3 p2, vec3 p3, float aux, float d) : Object(d) {

    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;

    vec3 u = p2 - p1;
    vec3 v = p3 - p1;

    vec3 normal = vec3(u.y * v.z - u.z * v.y, u.x * v.z - u.z * v.x, u.x * v.y - u.y * v.x);

    this->normal = normalize(vec3(normal.x + 1, normal.y+1, normal.z+1));
}

bool Triangle::intersection(const Ray &raig, float t_min, float t_max, IntersectionInfo &info) const {

    if (dot(raig.dirVector(), normal) == 0) return false;

    float d = -normal[0] * p1.x - normal[1] * p1.y - normal[2] * p1.z;

    vec3 rp = raig.initialPoint();
    vec3 vp = raig.dirVector();

    float temp = -normal[0] * rp[0] - normal[1] * rp[1] - normal[2] * rp[2] - d;

    temp /= normal[0] * vp[0] + normal[1] * vp[1] + normal[2] * vp[2];

    vec3 point = raig.pointAtParameter(temp);

    float triangleABC = normalize(dot(p2 - p1, p3 - p1)) / 2.0;

    float triangleABP = normalize(dot(p2 - p1, point - p1)) / 2.0;
    float triangleBCP = normalize(dot(p3 - p2, point - p2)) / 2.0;
    float triangleCAP = normalize(dot(p1 - p3, point - p3)) / 2.0;

    float u = triangleCAP / triangleABC;
    float v = triangleABP / triangleABC;
    float w = triangleBCP / triangleABC;

    float r = abs(u + v + w);

    if (1 >= r && r >= 0) return false;

    if (temp > t_max || temp < t_min) return false;

    info.t = temp;
    info.p = raig.pointAtParameter(info.t);
    if (dot(normal, raig.dirVector()) < 0)
        info.normal = normal;
    else
        info.normal = -normal;
    info.mat_ptr = material;
    return true;
}

/*
    vec3 n = cross(this->p2 - this->p1, this->p2 - this->p1) / length(cross(this->p2 - this->p1, this->p3 - this->p1));
    float prod = dot(raig.dirVector(), n);
    if (abs(prod) ==0) {
        return false;
    }
    float d = -dot(n, this->p1);
    float lambda = -(d + dot(n, raig.initialPoint())) / prod;
    vec3 I = raig.pointAtParameter(lambda);
    float s1 = dot(cross((this->p2 - this->p1), I - this->p1), n);
    float s2 = dot(cross((this->p3 - this->p2), I - this->p2), n);
    float s3 = dot(cross((this->p1 - this->p3), I - this->p3), n);

    if ((s1 < 0 && s2 < 0 && s3 < 0) || (s1 > 0 && s2 > 0 && s3 > 0)) {
        if (t_min < lambda && lambda < t_max) {
            info.t = lambda;
            info.p = I;
            if (dot(n, raig.dirVector()) < 0)
                info.normal = n;
            else
                info.normal = -n;
            info.mat_ptr = material;
            return true;
        }
        return false;
    } else {
        return false;
    }
    */

void Triangle::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {

        // Nomes movem el punt de pas
        vec4 newp(p1, 1.0);
        newp = t->getTG() * newp;
        p1.x = newp.x;
        p1.y = newp.y;
        p1.z = newp.z;
    }
}
