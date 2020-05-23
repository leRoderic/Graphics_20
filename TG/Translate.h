#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "TG.h"

class TranslateTG : public TG
{
public:
    vec3 traslation;
    TranslateTG(vec3 trasl);
    ~TranslateTG();
};

#endif // TRANSLATE_H
