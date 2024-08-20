#version 330 core

//Posi��o do v�rtice
layout (location = 0) in vec3 aPos;

//Normal do v�rtice
layout (location = 1) in vec3 aNormal;

//Cor do shader
layout (location = 2) in vec3 aColor;

//Matrizes
uniform mat4 model;
uniform mat4 view;
uniform mat4 proj;

//Outputs para o fragment shader
out vec3 Normal;
out vec3 Color;

void main()
{
	//Determina a posi��o dos v�rtices
	gl_Position = proj * view * model * vec4(aPos, 1.0);

	//Atribui o valor para o output
	Normal = aNormal;
	Color = aColor;
}