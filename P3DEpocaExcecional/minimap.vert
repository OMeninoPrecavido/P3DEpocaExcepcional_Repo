#version 330 core
layout (location = 0) in vec2 aPos;   // Posições do quad
layout (location = 1) in vec2 aTexCoord; // Coordenadas de textura do quad

out vec2 TexCoord;

uniform mat4 model; // Matriz de transformação de modelo

void main()
{
    // Transformação do modelo aplicada à posição do vértice
    gl_Position = model * vec4(aPos, 0.0, 1.0);
    TexCoord = aTexCoord; // Passar as coordenadas de textura para o fragment shader
}