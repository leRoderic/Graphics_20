#include "Main.h"

// Metode principal del programa

int main(int argc, char **argv) {

    cout << "Init..." <<endl;
    Q_INIT_RESOURCE(resources);

    if(argc == 2 && string(argv[1]) == "wsl")
        setenv("DISPLAY", "127.0.0.1:0", true);


    //Controller *controller = new Controller("://resources/spheres2.txt", SceneFactory::VIRTUAL, RenderFactory::ONLINE);

    // TODO: Fase 1 carregar dades del fitxer de dades
    Controller *controller = new Controller("://resources/dataBCN.txt", SceneFactory::DATA, RenderFactory::ONLINE);
    controller->start(argc, argv);

    return(0);
}
