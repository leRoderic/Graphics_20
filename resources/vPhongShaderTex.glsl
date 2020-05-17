#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 normals;
layout (location = 2) in vec2 vCoord;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 pos;
out vec4 normal;
out vec2 coord;

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    pos = vPosition;
    normal = normals;
    coord = vCoord;
}
