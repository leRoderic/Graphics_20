#version 330

in vec4 position;
in vec4 normal;

out vec4 colorOut;

struct light {
    vec3 ambient, diffuse, specular;
    vec3 atenuacio;
    vec4 position, direction;
};

uniform light dir_light;

void main()
{
    float r = dot(normalize(dir_light.direction), normal);

    float v1 = 3/4;
    float v2 = 2/4;
    float v3 = 1/4;

    vec3 color = vec3(1);

    if(r >= v3)
        color *= 1;
    else if(r >= v2)
        color *= v3;
    else if(r >= v1)
        color *= v2;
    else
        color *= v1;

    colorOut = vec4(color, 1);
}
