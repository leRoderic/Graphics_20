#ifndef TRANSLATE_H
#define TRANSLATE_H

#include "TG.h"

class Translate : public TG
{
public:
    vec3 traslation;
    Translate(vec3 trasl);
    ~Translate();
};

#endif // TRANSLATE_H
