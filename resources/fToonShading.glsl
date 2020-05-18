#version 330

in vec4 pos;
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
    float radius;
    int length;
};

uniform Light lights[20];
uniform vec3 ambientGlobal;
uniform vec4 obs;

void main()
{
    /*vec3 color = vec3(1.);

    for(int i = 0; i < 20; ++i)
    {
        if(lights[i].type == 1) // 1==DIRECTIONAL
        {
            float r = dot(normalize(lights[i].direction), normal);

            color *= r;

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
    }*/
    vec3 color = vec3(0.0f);
    vec4 N = normalize(normal);
    vec4 L;
    for (int i = 0; i < lights[0].length; i++) {
        if (lights[i].type == 0){ // llum puntual
            L = normalize(lights[i].position - pos);
        }
        else if (lights[i].type == 1){ // llum direccional
            L = normalize(-lights[i].direction);
        }
        else { // llum spot
            //NO IMPLEMENTAT
            L = vec4(0.0f);
        }

        float r = dot(L,N);

        if (r > 0.95)
            color += vec3(0.9,0.6,0.6);
        else if (r > 0.75)
            color += vec3(0.8,0.5,0.5);
        else if (r > 0.5)
            color += vec3(0.6,0.4,0.4);
        else if (r > 0.25)
            color += vec3(0.4,0.3,0.3);
        else
            color += vec3(0.25,0.2,0.2);

    }

    colorOut = vec4(color,1.0);
}
