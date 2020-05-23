#include "Translate.h"

Translate::Translate(vec3 trasl): traslation(trasl)
{
    //Find translate function in mat.h
    matTG = Common::Translate(traslation);
}

Translate::~Translate()
{

}

