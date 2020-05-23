#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "RenderFactory.h"
#include "SceneFactory.h"
#include "SceneFactoryData.h"
#include "SceneFactoryVirtual.h"

class Controller
{
    Render *render;

public:
    Controller(QString fileName, SceneFactory::SCENE_FACTORIES s, RenderFactory::RENDER_TYPES  rt);
    void start(int argc, char **argv);

private:
    static SceneFactory *createFactory(SceneFactory::SCENE_FACTORIES factory);

};

#endif // CONTROLLER_H
