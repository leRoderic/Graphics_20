#ifndef RAYTRACINGGLU_H
#define RAYTRACINGGLU_H

#ifdef unix
#include <GL/glut.h> //OpenGL Utility Toolkits
#else

#include <GLUT/glut.h> //OpenGL Utility Toolkits

#endif

#include "Render.h"

extern Render *rIntern;

void RenderingSceneGLU();

class RayTracingGLU : public Render
{
public:
    RayTracingGLU();
    virtual ~RayTracingGLU();

    virtual  void startRendering(int argc, char **argv);

    virtual  void initRender(string nomFitxer);
    virtual  void setPixelColor(vec3 col, int x, int y);
    virtual  void exitRender();

private:
    void (*f_render)();
};

#endif // RAYTRACINGGLU_H
