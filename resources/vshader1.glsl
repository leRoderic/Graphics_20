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

    color = vColor;
    color = vec4(1,0,0,1);
}
