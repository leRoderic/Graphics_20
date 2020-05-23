//
// Created by abdel on 30/03/2020.
//

#ifndef RAYDATA_SCALE_H
#define RAYDATA_SCALE_H


#include "TG.h"

class Scale : public TG {
public:
    glm::vec3 scale;
    float escala;
    Scale(glm::vec3 scale);
    Scale(float esc);
    ~Scale();
};


#endif //RAYDATA_SCALE_H
