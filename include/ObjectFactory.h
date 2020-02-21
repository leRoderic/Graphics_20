#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "Object.h"
#include "Sphere.h"
#include "Plane.h"

class ObjectFactory
{
    static ObjectFactory *instance;
    ObjectFactory();

public:
    typedef enum {
        SPHERE,
        PLANE
    } OBJECT_TYPES;

    static ObjectFactory *getInstance() {
          if (instance==nullptr)
              instance = new ObjectFactory();
          return instance;
    }
    Object *getObject(float x, float y, float z, float val, OBJECT_TYPES t);
    ~ObjectFactory() {
        delete instance;
    }

    Object *createObject(float x, float y, float z, float aux, float v, OBJECT_TYPES t);
};

#endif // OBJECTFACTORY_H
