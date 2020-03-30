#pragma once

#include "Ray.h"
#include "Hitable.h"
#include "Material.h"
#include "Lambertian.h"
#include "Animation.h"

// Es la classe pare de tots els objectes que s'han de visualitzar.
// Es fa una classe Objectes que hereda de Hitable i ha d'implementar el metode intersection

class Object: public Hitable, public Animable {
  public:
    Object();
    Object(float d);
    virtual ~Object();

    // Metodes a implementar en les classes filles: son  metodes abstractes
    virtual bool intersection(const Ray& r, float t_min, float t_max, IntersectionInfo& info) const = 0;
    virtual void aplicaTG(TG *tg) = 0;

    float    getData();
    void    setData(float d);
    void     setMaterial(Material *m);

    Material *getMaterial();

protected:
    Material *material;   // Material de l'objecte
    float data;           // valor de les dades que representa aquest objecte, en cas que provingui d'un fitxer de dades
                          // per defecte, sino, és -1
};

