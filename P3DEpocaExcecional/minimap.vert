#version 330 core

// Entrada dos vértices do quad (posições e coordenadas de textura)
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoords;

// Saída para o fragment shader
out vec2 TexCoords;

void main()
{
    // Passa as coordenadas de textura para o fragment shader
    TexCoords = aTexCoords;
    
    // Calcula a posição final do vértice
    gl_Position = vec4(aPos, 1.0);
}