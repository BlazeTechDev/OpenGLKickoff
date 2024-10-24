#version 330 core

in vec3 vertex;

uniform float delta;

out vec4 FragColor;

void main()
{
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f) * sin(delta + vertex.length());
} 