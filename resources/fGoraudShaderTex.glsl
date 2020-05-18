#version 330

in vec4 color;
in vec2 coords;
out vec4 colorOut;

uniform sampler2D texMap;

void main()
{
    
    vec4 tex = texture2D(texMap, coords);
    colorOut = color*0.75+tex.xyzw*0.25;
}

