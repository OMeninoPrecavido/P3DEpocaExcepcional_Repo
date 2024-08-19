#version 330 core

//Posição do vértice
layout (location = 0) in vec3 aPos;

//Normal do vértice
layout (location = 1) in vec3 aNormal;

//Matrizes
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

//Outputs para o fragment shader
out vec3 Normal;

void main()
{
	//Determina a posição dos vértices
	gl_Position = proj * view * model * vec4(aPos, 1.0);

	//Atribui o valor para o output
	Normal = aNormal;
}