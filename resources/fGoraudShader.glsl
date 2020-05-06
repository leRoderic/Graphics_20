#version 330

in vec4 color;
out vec4 colorOut;

struct Material {

    vec3 difuse;
};

uniform Material material;

void main()
{
    colorOut = color;
}

