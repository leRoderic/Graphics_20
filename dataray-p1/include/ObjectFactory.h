#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "Object.h"
#include "Sphere.h"
#include "Plane.h"
#include "Triangle.h"
#include "BoundaryObject.h"
#include "Circle.h"
#include "Cylinder.h"

class ObjectFactory
{
    static ObjectFactory *instance;
    ObjectFactory();

public:
    typedef enum {
        SPHERE,
        PLANE,
        FITTED_PLANE,
        TRIANGLE,
        BROBJECT,
        CYLINDER,
        CIRCLE
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

    Object *createObject(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float aux,
                 float v, OBJECT_TYPES t);
    Object *createObject(QString s, float data, OBJECT_TYPES t);
};

#endif // OBJECTFACTORY_H
