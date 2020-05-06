#version 330

layout (location = 0) in vec4 vPosition;
//layout (location = 1) in vec4 vColor;

struct Material {
    vec3 difuse;
};
uniform Material material;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    //color = vColor;
    color = vec4(1,0,0,1);
}


/*#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;

struct Material {
    vec3 difuse;
    vec3 ambient;
    vec3 specular;
    float beta;
    float alpha;
};
uniform Material material;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

void main(){

    vec3 L, V, H;

    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;
    color = vColor;
    int numLights = 1;

    for(int i = 0; i < numLights; i++){

    }
}*/
