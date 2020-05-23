#ifndef RENDER_H
#define RENDER_H

#include "Scene.h"
#include "Camera.h"

class Render
{
protected:
    // Scene: scena virtual dels objectes amb els seus materials i textures i les llums
    Scene *scene;
    // Camera: on está l'observador
    Camera *cam;

public:
    virtual ~Render() {}
    void setScene(Scene *s);
    void setCamera(Camera *c);


    virtual void startRendering(int argc, char **argv);

    virtual void initRender(string nomFitxer) = 0;
    virtual void setPixelColor(vec3 color, int x, int y) = 0;
    virtual void exitRender();

    // rendering: metode principal de recorregut de cadascun dels pixels del viewport
    void rendering();

    // renderingScene: metode que fa les inicialitzacions, el rendering i el final segons
    // en quin render es faci: PPM, GLU o animacio
    virtual void renderingScene();

    void cleanup();
};


#endif // RENDER_H
