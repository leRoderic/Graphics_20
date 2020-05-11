#version 330

in vec4 position;
in vec4 normal;

out vec4 colorOut;

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

uniform Light lights[20];
uniform vec3 ambientGlobal;
uniform vec4 obs;

void main()
{
    vec3 color = vec3(1);

    for(int i = 0; i < 20; ++i)
    {
        if(lights[i].type == 1) // 1==DIRECTIONAL
        {
            float r = dot(normalize(lights[i].direction), normal);

            float v1 = 3/4;
            float v2 = 2/4;
            float v3 = 1/4;

            if(r >= v3)
                color *= 1;
            else if(r >= v2)
                color *= v3;
            else if(r >= v1)
                color *= v2;
            else
                color *= v1;

            break;  // compute with the first directional light found and exit
        }
    }

    colorOut = vec4(color, 1);
}
