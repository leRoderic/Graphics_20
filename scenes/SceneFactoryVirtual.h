//
// Created by anna on 18/01/2020.
//

#ifndef RAYDATA_SCENEFACTORYVIRTUAL_H
#define RAYDATA_SCENEFACTORYVIRTUAL_H

#include "SceneFactory.h"
#include "SceneReader.h"

class SceneFactoryVirtual : public SceneFactory
{
public:
    SceneFactoryVirtual();

    virtual Scene    *createScene(QString nomFitxer);
    virtual Scene    *createScene();

private:
    void OneSphere(Scene *s);
};


#endif //RAYDATA_SCENEFACTORYVIRTUAL_H
