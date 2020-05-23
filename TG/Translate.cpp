#include "Translate.h"

TranslateTG::TranslateTG(vec3 trasl): traslation(trasl)
{
    //Find translate function in mat.h
    matTG = Common::Translate(traslation);
}

TranslateTG::~TranslateTG()
{

}

