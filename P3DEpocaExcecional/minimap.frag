#version 330 core

// Entrada do vertex shader
in vec2 TexCoords;

// Saída da cor final do fragmento
out vec4 FragColor;

// Uniform para a textura do minimapa
uniform sampler2D minimapTexture;

void main()
{
    // Busca a cor da textura usando as coordenadas de textura
    FragColor = texture(minimapTexture, TexCoords);
}