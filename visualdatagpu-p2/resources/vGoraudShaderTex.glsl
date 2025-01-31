#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 normals;
layout (location = 2) in vec2 vCoords;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;
out vec2 coords;

struct Material {
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float alpha;
    float beta;
};

struct Light{
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
uniform vec4 obs;
uniform vec3 ambientGlobal;

void main(){
    coords = vCoords;
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    vec4 L, N, V, H;
    vec3 ambient, specular, diffuse;
    vec3 colorPart = vec3(0.0f, 0.0f, 0.0f);
    float d, atenuacio;

    N = vec4(normalize(normals.xyz), 0.0f);

    //color = vec4(colorPart, 1.0f);

    for(int i = 0; i < lights[0].length; i++){

        if(lights[i].type == 0){
            L = vec4(normalize(lights[i].position.xyz - vPosition.xyz), 0.0f);
        }else if (lights[i].type == 1){
            L = normalize(-lights[i].direction);
        }else if(lights[i].type == 2){
            break; // not implemented yet
        }

        V = vec4(normalize(obs.xyz - vPosition.xyz), 0.0f);
        H = vec4(normalize(L.xyz + V.xyz), 0.0f);

        ambient = material.ambient* lights[i].ambient;
        diffuse = material.diffuse * lights[i].diffuse * max(dot(L, N), 0.0f);
        specular = material.specular * lights[i].specular * pow(max(dot(N, H), 0.0f), material.beta);

        d = length(lights[i].position.xyz - vPosition.xyz);
        atenuacio = dot(lights[i].atenuacio, vec3(1.0f, d, pow(d, 2)));

        if(atenuacio == 0.0f){
            colorPart += ambient + (diffuse + specular);
        }else{
            colorPart += ambient + atenuacio/(diffuse + specular);
        }
    }
    colorPart+= material.ambient * ambientGlobal;
    color = vec4(colorPart, 1.0f);
    //color = vec4(material.diffuse.xzx, 1.0f);
}
