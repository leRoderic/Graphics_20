#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Ray.h"
#include "Hitable.h"
#include "Animation.h"
#include "Object.h"
#include "Sphere.h"
#include "BoundaryObject.h"
#include "Lambertian.h"
#include "ColorMap.h"
#include "Light.h"
#include "Camera.h"
#include "FittedPlane.h"

class Scene: public Hitable
{
public:
    Scene();
    virtual ~Scene();

    // Funcio que calcula la interseccio del raig r amb l'escena. Guarda la informacio
    // del punt d'interseccio més proper a t_min, punt que està entre t_min i t_max.
    // Retorna cert si existeix la interseccio, fals, en cas contrari
    virtual bool intersection(const Ray& raig, float t_min, float t_max, IntersectionInfo& info) const;

    // Funcio recursiva que calcula el color. Inicialment es
    // es crida a cada pixel. Tambe es crida en calcular les ombres o les reflexions.
    vec3 ComputeColorRay(Ray &ray, int depth);

    void update(int nframe);

    void setMaterials(ColorMap *cm);

    void setDimensions(vec3 p1, vec3 p2);

    vec3 BlinnPhong(vec3 point, vec3 normal, const Material *material);

    // dimensions de l'escena virtual
    vec3 pmin, pmax;

    // Vector d'objectes continguts a l'escena
    std::vector<Object *> objects;

    //Fase 1 / 3.2 / b / a
    Object *ground;

    // TODO FASE 2: Afegir llums a l'escena
    std::vector<Light *> lights;

    vec3 ambientGlobal;

    Camera *cam;
private:
    int const MAX_DEPTH = 10;
};

#endif // SCENE_H
