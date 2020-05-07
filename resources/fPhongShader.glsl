#version 330

in vec4 pos;
in vec4 normal;

out vec4 color;

struct Material {
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float beta;
    float alfa;
};

uniform Material material;

//0->puntual 1->direcciona 2->spot
struct Lights {
    vec4 position;
    vec4 direction;
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    vec3 attenuacio;
    int len;
    int tipus;
};

uniform Lights llums[20];

uniform vec3 ambientGlobal;

uniform vec4 obs;

void main()
{
    vec3 resultat = vec3(0.0f);
    vec4 L, H, V;
    vec4 N = vec4(normalize(normal),0.0f); // vector normal

    vec3 kd = material.diffuse;
    vec3 ka = material.ambient;
    vec3 ks = material.specular;

    for ( int i = 0; i < llums[0].len; i++) {

        vec3 id = llums[i].diffuse;
        vec3 ia = llums[i].ambient;
        vec3 is = llums[i].specular;

        float d = length(llums[i].position - pos);

        float atenuacio = 1.0/dot(llums[i].attenuacio, vec3(1.0f, d, pow(d, 2)));

        if (llums[i].tipus == 0){ // llum puntual
            L = vec4(normalize(llums[i].position.xyz - pos.xyz),0.0f);
        }
        else if (llums[i] == 1){ // llum direccional
            L = normalize(-llums[i].direction);
        }
        else { // llum spot
            //NO IMPLEMENTAT
            L = vec4(0.0f);
        }

        // H vector mig -> L + V
        V = normalize(obs - pos);
        H = vec4(normalize(L.xyz + V.xyz),0.0f);

        vec3 ambient = ka * ia;
        vec3 diffuse = kd * id * max(dot(L,N), 0.0f);
        vec3 specular = ks * is * (float) pow(max(dot(N, H), 0.0f), material->beta);

        resultat += atenuacio * (diffuse + specular) + ambient;
    }
     resultat = ambientGlobal * material.ambient + resultat;

     color = vec4(resultat, 1.0f);

}

