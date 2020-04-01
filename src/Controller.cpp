#include "Controller.h"

Controller::Controller(QString fileName, SceneFactory::SCENE_FACTORIES s, RenderFactory::RENDER_TYPES rt)
{


    // ETAPA 1: Coonstrucció de l'escena
    // Pot ser una escena virtual (no provinent de dades)
    // O pot ser una escena que prové de dades geolocalitzades (Visualization Mapping)
    // S'usa un Abstract Factory per a construir l'escena, la camera
    // TODO Fase 2: crear les llums i pasar-les a l'escena
    SceneFactory *scFac = createFactory(s);

    Scene *scene;

    scene = scFac->createScene(fileName);
    // TODO Fase 1: Cal posar les dimensions de l'escena virtual usant setDimensions de la classe Scene
    scene->setDimensions(vec3(-5.0f), vec3(5.0f));

    Camera *camera;
    camera = scFac->createCamera();

    scene->cam = camera;

    // Es crea aqui només un ColorMap
    // TODO Fase 2: Cal tenir en compte tants ColorMaps com numero de propietats, en el cas que el fitxer de dades en
    //  tingui més d'una. On es pot fer això millor?
    ColorMap *colorMap = scFac->createColorMap(ColorMapStatic::ColorMapType::COLOR_MAP_TYPE_PLASMA);
    scene->setMaterials(colorMap);

    // ETAPA 2: Inicialitzacio del Rendering
    // usa un Factory Template per a construir el tipus de render
     render = RenderFactory::getInstance()->getRender(rt);
     render->setScene(scene);
     render->setCamera(camera);

}

void Controller::start(int argc, char **argv) {
    // ETAPA 2: Activació del Rendering
    render->startRendering(argc, argv);
}

SceneFactory* Controller::createFactory(SceneFactory::SCENE_FACTORIES factory)
{
    if(factory == SceneFactory::SCENE_FACTORIES::VIRTUAL)
    {
        return new SceneFactoryVirtual();
    }
    else if(factory == SceneFactory::SCENE_FACTORIES::DATA)
    {
        return new SceneFactoryData();
    }
    return nullptr;
}
