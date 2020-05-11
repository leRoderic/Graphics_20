#include "Scene.h"

/**
 * @brief Scene::Scene
 */
Scene::Scene() {
    // Inicialització de la capsa minima
    capsaMinima.pmin = vec3(-1.0, -1.0,-1.0);
    capsaMinima.a = 2;
    capsaMinima.h = 2;
    capsaMinima.p = 2;
    lightAmbientGlobal = vec3(0.3f);
}

/**
 * @brief Scene::~Scene
 */
Scene::~Scene() {
    elements.clear();
    lights.clear();
    delete camera;
}

/**
 * @brief Scene::addObject
 * @param obj
 */
void Scene::addObject(Object *obj) {
    elements.push_back(obj);
    calculCapsaMinCont3DEscena();
}

/**
 * @brief Scene::toGPU
 */
void Scene::toGPU(QGLShaderProgram *p) {
    qDebug()<<"scene to gpu";
    lightsToGPU(p);
    setAmbientToGPU(p);
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->toGPU(p);
    }
}

/**
 * @brief Scene::draw
 */
void Scene::draw() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->draw();
    }
}

/**
 * @brief Scene::drawTexture
 */
void Scene::drawTexture() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->drawTexture();
    }
}

/**
 * @brief Scene::getLightActual
 * @return
 */
Light* Scene::getLightActual() {
    // TO DO OPCIONAL: A modificar si es vol canviar el comportament de la GUI
    // Ara per ara dona com a Light actual la darrera que s'ha inserit
    return (lights[lights.size()-1]);
}

/**
 * @brief Scene::setLightActual
 * @param l
 */
void Scene::setLightActual(Light* l){
    lights[lights.size()-1]=l;
}

int lightTypeNumber(Light *l){

    if(l->getTipusLight() == Puntual){
        return 0;
    }else if (l->getTipusLight() == Direccional){
        return 1;
    }else if (l->getTipusLight() == Spot){
        return 2;
    }
    return -1;
}

/**
 * @brief Scene::lightsToGPU
 * @param program
 */
void Scene::lightsToGPU(QGLShaderProgram *program){
// TO DO: A implementar a la fase 1 de la practica 2

    struct gl_Lights{
        GLuint ambient;
        GLuint diffuse;
        GLuint specular;
        GLuint atenuacio;
        GLuint position;
        GLuint direction;
        GLuint type;
        GLuint length;
    } gl_Lights[20];

    for (int i = 0; i < lights.size(); i++) {

        gl_Lights[i].ambient = program->uniformLocation(QString("lights[%1].ambient").arg(i));
        gl_Lights[i].diffuse = program->uniformLocation(QString("lights[%1].diffuse").arg(i));
        gl_Lights[i].specular = program->uniformLocation(QString("lights[%1].specular").arg(i));
        gl_Lights[i].atenuacio = program->uniformLocation(QString("lights[%1].atenuacio").arg(i));

        gl_Lights[i].position = program->uniformLocation(QString("lights[%1].position").arg(i));
        gl_Lights[i].direction = program->uniformLocation(QString("lights[%1].direction").arg(i));

        gl_Lights[i].type = program->uniformLocation(QString("lights[%1].type").arg(i));

        gl_Lights[i].length = program->uniformLocation(QString("lights[%1].length").arg(i));


        glUniform3fv(gl_Lights[i].ambient, 1, lights[i]->ambient);
        glUniform3fv(gl_Lights[i].diffuse, 1, lights[i]->diffuse);
        glUniform3fv(gl_Lights[i].specular, 1, lights[i]->specular);
        glUniform3fv(gl_Lights[i].atenuacio, 1, lights[i]->atenuacio);

        glUniform4fv(gl_Lights[i].position, 1, lights[i]->position);
        glUniform4fv(gl_Lights[i].direction, 1, lights[i]->direction);

        glUniform1i(gl_Lights[i].type, 0);//lightTypeNumber(lights[i]));

        glUniform1i(gl_Lights[i].length, lights.size());
    }
}

void Scene::addLight(Light *l) {
    lights.push_back(l);
}

/**
 * @brief Scene::setAmbientToGPU
 * @param program
 */
void Scene::setAmbientToGPU(QGLShaderProgram *program){
    // TO DO: A implementar a la fase 1 de la practica 2
    GLuint ambient = program->uniformLocation(QString("ambientGlobal"));
    glUniform3fv(ambient, 1, this->lightAmbientGlobal);
}

/**
 * @brief Scene::setCamera
 * @param Camera *
 */
void Scene::setCamera(Camera *c) {
    camera = c;
}
/**
 * @brief Scene::calculCapsaMinCont3DEscena
 */

void Scene::calculCapsaMinCont3DEscena()
{
    Capsa3D c;
    vec3 pmax;

    if (elements.size()==1) {
        capsaMinima = elements[0]->calculCapsa3D();
        pmax[0] = capsaMinima.pmin[0]+capsaMinima.a;
        pmax[1] = capsaMinima.pmin[1]+capsaMinima.h;
        pmax[2] = capsaMinima.pmin[2]+capsaMinima.p;
    } else {
        capsaMinima.pmin[0]=200;
        capsaMinima.pmin[1]=200;
        capsaMinima.pmin[2]=200;
        pmax[0] = -200;
        pmax[1] = -200;
        pmax[2] = -200;
    }

    for (unsigned int i=0; i<elements.size(); i++) {
       c = elements[i]->calculCapsa3D();

       if (capsaMinima.pmin[0]>c.pmin[0]) capsaMinima.pmin[0] = c.pmin[0];
       if (capsaMinima.pmin[1]>c.pmin[1]) capsaMinima.pmin[1] = c.pmin[1];
       if (capsaMinima.pmin[2]>c.pmin[2]) capsaMinima.pmin[2] = c.pmin[2];
       if (pmax[0]<c.pmin[0]+c.a) pmax[0] = c.pmin[0]+c.a;
       if (pmax[1]<c.pmin[1]+c.h) pmax[1] = c.pmin[1]+c.h;
       if (pmax[2]<c.pmin[2]+c.p) pmax[2] = c.pmin[2]+c.p;
    }
    capsaMinima.a = pmax[0]-capsaMinima.pmin[0];
    capsaMinima.h = pmax[1]-capsaMinima.pmin[1];
    capsaMinima.p = pmax[2]-capsaMinima.pmin[2];
}

void Scene::update(int nframe) {
    for (unsigned int i = 0; i< elements.size(); i++) {
        if (dynamic_cast<Animable*>(elements[i]) ) elements[i]->update(nframe);
    }
}
