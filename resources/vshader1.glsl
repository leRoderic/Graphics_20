#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 vColor;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

struct GL_Material {
    vec3 diffuse;
};

uniform GL_Material material;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    //color = vColor;
    color = vec4(1,0,0, 1.0f);
}
