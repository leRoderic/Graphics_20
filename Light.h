#ifndef Light_H
#define Light_H

#include "./library/Common.h"



// Tipus de Lights
enum LightType: uint {Puntual, // == 0
                      Direccional,  // == 1
                      Spot,     // == 2
                     };

// Classe que representa els atributs d'una Light
// TO DO: A la fase 1 has d'incloure els atributs necessaris per codificar una llum

class Light {
    public:
        Light(LightType l);

        Light(vec4,vec4,vec3,vec3,vec3,vec3,LightType);

        vec4 getLightPosition();
        void setLightPosition(vec4 v);

        vec3 getIa() const;
        void setIa(const vec3 &value);

        vec3 getId();
        void setId(vec3 i);

        vec3 getIs() const;
        void setIs(const vec3 &value);

        vec3 getCoeficients() const;
        void setCoeficients(const vec3 &value);

        LightType getTipusLight() const;
        void setTipusLight(const LightType &value);

        vec3 ambient, diffuse, specular;
        vec3 atenuacio;
        vec4 position, direction;

        LightType type;
};

#endif // Light_H
