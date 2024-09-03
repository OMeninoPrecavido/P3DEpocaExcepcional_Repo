#version 330 core
layout (location = 0) in vec2 aPos;   // Posi��es do quad
layout (location = 1) in vec2 aTexCoord; // Coordenadas de textura do quad

out vec2 TexCoord;

uniform mat4 model; // Matriz de transforma��o de modelo

void main()
{
    // Transforma��o do modelo aplicada � posi��o do v�rtice
    gl_Position = model * vec4(aPos, 0.0, 1.0);
    TexCoord = aTexCoord; // Passar as coordenadas de textura para o fragment shader
}