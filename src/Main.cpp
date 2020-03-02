#include "Main.h"

// Metode principal del programa

int main(int argc, char **argv) {


    cout << "Init..." <<endl;
    Q_INIT_RESOURCE(resources);

    Controller *controller = new Controller("://resources/spheres2.txt", SceneFactory::VIRTUAL, RenderFactory::ONLINE);

    // TODO: Fase 1 carregar dades del fitxer de dades
    // Controller *controller = new Controller(":/resources/data0.txt", SceneFactory::DATA, RenderFactory::ONLINE);
    controller->start(argc, argv);


    return(0);
}
