#include "Object.h"


Object::Object()
{
    data = -1;
    material = nullptr;
}

Object::Object(float d)
  {
    data = d;
    material = nullptr;
  }

Object::~Object()
{
    // TO DO Fase 2: Quan s'incloguin nous materials, cal retocar aquest destructor
    if (material!=nullptr)
        if (dynamic_cast<Lambertian *>(material))
            delete (Lambertian *)material;
}

float Object::getData() {
    return data;
}

void Object::setData(float d) {
    this->data = d;
}

void Object::setMaterial(Material *m) {
    material = m;
}

Material *Object::getMaterial() {
    return material;
}
