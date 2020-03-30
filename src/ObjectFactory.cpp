#include <include/FittedPlane.h>
#include "ObjectFactory.h"

ObjectFactory *ObjectFactory::instance = nullptr;

ObjectFactory::ObjectFactory()
{

}

//! createObject
/*!
  \sa testMe()
  \param x coordenada x on cal colocar el centre de l'objecte.
  \param y coordenada x on cal colocar el centre de l'objecte.
  \param z coordenada x on cal colocar el centre de l'objecte.
  \param aux paràmetre addicional per codificar el radi de l'esfera o la d del pla.
  \param v valor d'escala que cal aplicar a l'objecte
  \param t tipus d'objecte a construir: SPHERE, PLANE, ....
*/
Object *
ObjectFactory::createObject(float x, float y, float z, float x2, float y2, float z2, float x3, float y3, float z3,
                            float aux, float v, OBJECT_TYPES t) {
    
    Object *o;
    // TO-DO Fase 1: Incloure diferents objectes: CILINDRES, TRIANGLES, BR_OBJECTES
    switch (t) {
        case SPHERE:
            o = new Sphere(vec3(x, y, z), aux, v);
            std::cerr << "Sphere created at " << x << ", " << y << ", " << z << std::endl;
            break;
        case PLANE:
            o = new Plane(vec3(x, y, z), vec3(x2, y2, z2), v);
            std::cerr << "Plane created at " << x << ", " << y << ", " << z << std::endl;
            break;
        case FITTED_PLANE:
            //o = new FittedPlane(vec3(x, y, z), aux, v);
            o = new FittedPlane(vec3(x, y, z), vec3(x2, y2, z2), vec3(x3, y3, z3), aux, v);
            std::cerr << "Fitted plane created at " << x << ", " << y << ", " << z << std::endl;
            break;
        case CYLINDER:
            o = new Cylinder(vec3(x, y, z), aux, v);
            std::cerr << "Cylinder created at " << x << ", " << y << ", " << z << std::endl;
            break;
        case CIRCLE:
            o = new Circle(vec3(x, y, z), vec3(x, y, z), v);
            std::cerr << "Circle created at " << x << ", " << y << ", " << z << std::endl;
            break;
        case TRIANGLE:
            o = new Triangle(vec3(x, y, z), vec3(x2, y2, z2), vec3(x3, y3, z3), aux, v);
            std::cerr << "Triangle created at " << x << ", " << y << ", " << z << std::endl;
            break;
        default:
            std::cerr << "Unknown object" << std::endl;
            break;
    }
    return o;
}

Object *ObjectFactory::createObject(QString s, float data, OBJECT_TYPES t) {

    Object *o;
    switch(t){
        case BROBJECT:
            o = new BoundaryObject(s, data);
            break;
        default:
            break;
    }
    return o;
}