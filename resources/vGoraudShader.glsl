#version 330

const int PUNTUAL = 0;
const int DIRECCIONAL = 1;
const int SPOT = 2;

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 normals;

struct Material {
    vec3 difuse;
    vec3 ambient;
    vec3 specular;
    float alpha;
    float beta;
};

struct Light {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    vec3 atenuacio;
    vec4 position;
    vec4 direction;
    int type;
    int length;
};

uniform Material material;
uniform Light lights[20];
uniform mat4 model_view;
uniform mat4 projection;

uniform vec4 obs;
uniform vec3 ambientGlobal;

out vec4 color;

void main(){

    vec4 L, N, V, H;
    vec3 ambient, specular, diffuse;
    vec3 colorPart = vec3(0.0f, 0.0f, 0.0f);
    float d, atenuacio;

    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    N = vec4(normalize(normals.xyz, 0.0f));

    for(int i = 0; i < lights[0].length; i++){

        if(lights[i].type == PUNTUAL){
            L = vec4(normalize(lights[i].position.xyz - vPosition.xyz, 0.0f));
        }else if (lights[i].type == DIRECCIONAL){
            L = -vec4(normalize(lights[i].direction, 0.0f));
        }else if(lights[i].type == SPOT){
            break; // not implemented yet
        }

        V = vec4(normalize(vPosition.xyz - obs.xyz), 0.0f);
        H = vec4(normalize(L.xyz + V.xyz), 0.0f);

        ambient = material.ambient * lights[i].ambient;
        diffuse = material.difuse * lights[i].diffuse * max(dot(L, N), 0.0f);
        specular = material.specular * lights[i].specular * pow(max(dot(N, H), 0.0f), Material.beta);

        d = length(lights[i].position.xyz - vPosition.xyz);
        atenuacio = dot(lights[i].atenuacio, vec3(1.0f, d, pow(d, 2)));

        colorPart += (ambient + atenuacio*(diffuse + specular) + material.ambient * ambientGlobal);

    }
    color = vec4(colorPart, 1.0f);
}
