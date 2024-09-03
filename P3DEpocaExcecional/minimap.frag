#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D minimapTexture; // A textura do minimapa

void main()
{
    FragColor = texture(minimapTexture, TexCoord); // Pegar a cor da textura
}