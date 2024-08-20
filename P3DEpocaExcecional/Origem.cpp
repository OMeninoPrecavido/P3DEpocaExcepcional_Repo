#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

//V�rtices do bloco de ch�o
GLfloat floorBlockVertices[] =
{ //     COORDINATES     /        NORMALS        /        COLORS         //
	-0.5f, 0.0f,  0.5f,     0.0f, -1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.0f, -1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.0f, -1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.0f, -1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Bottom side

	-0.5f, 0.0f,  0.5f,     -1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Left Side
	-0.5f, 0.0f, -0.5f,     -1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Left Side
	-0.5f, 1.0f,  0.5f,     -1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Left Side
	-0.5f, 1.0f, -0.5f,     -1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Left Side

	 0.5f, 0.0f,  0.5f,      1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Right Side
	 0.5f, 0.0f, -0.5f,      1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Right Side
	 0.5f, 1.0f,  0.5f,      1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Right Side
	 0.5f, 1.0f, -0.5f,      1.0f, 0.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Right Side

	-0.5f, 0.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.2f, 0.2f, 0.6f, // Front Side
	 0.5f, 0.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.2f, 0.2f, 0.6f, // Front Side
	-0.5f, 1.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.2f, 0.2f, 0.6f, // Front Side
	 0.5f, 1.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.2f, 0.2f, 0.6f, // Front Side

	-0.5f, 0.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.2f, 0.2f, 0.6f, // Back Side
	 0.5f, 0.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.2f, 0.2f, 0.6f, // Back Side
	-0.5f, 1.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.2f, 0.2f, 0.6f, // Back Side
	 0.5f, 1.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.2f, 0.2f, 0.6f, // Back Side

	-0.5f, 1.0f,  0.5f,      0.0f, 1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Top side
	-0.5f, 1.0f, -0.5f,      0.0f, 1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Top side
	 0.5f, 1.0f, -0.5f,      0.0f, 1.0f,  0.0f,     0.2f, 0.2f, 0.6f, // Top side
	 0.5f, 1.0f,  0.5f,      0.0f, 1.0f,  0.0f,     0.2f, 0.2f, 0.6f // Top side
};

//V�rtices do bloco de parede
GLfloat wallBlockVertices[] =
{ //     COORDINATES     /        NORMALS       //
	-0.5f, 0.0f,  0.5f,     0.0f, -1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.0f, -1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.0f, -1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.0f, -1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Bottom side

	-0.5f, 0.0f,  0.5f,     -1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Left Side
	-0.5f, 0.0f, -0.5f,     -1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Left Side
	-0.5f, 2.0f,  0.5f,     -1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Left Side
	-0.5f, 2.0f, -0.5f,     -1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Left Side

	 0.5f, 0.0f,  0.5f,      1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Right Side
	 0.5f, 0.0f, -0.5f,      1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Right Side
	 0.5f, 2.0f,  0.5f,      1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Right Side
	 0.5f, 2.0f, -0.5f,      1.0f, 0.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Right Side

	-0.5f, 0.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.6f, 0.2f, 0.2f, // Front Side
	 0.5f, 0.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.6f, 0.2f, 0.2f, // Front Side
	-0.5f, 2.0f,  0.5f,      0.0f, 0.0f,  1.0f,     0.6f, 0.2f, 0.2f, // Front Side
	 0.5f, 2.0f,  0.5f,      0.0f, 0.0f,  1.0f,		0.6f, 0.2f, 0.2f, // Front Side

	-0.5f, 0.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.6f, 0.2f, 0.2f, // Back Side
	 0.5f, 0.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.6f, 0.2f, 0.2f, // Back Side
	-0.5f, 2.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.6f, 0.2f, 0.2f, // Back Side
	 0.5f, 2.0f, -0.5f,      0.0f, 0.0f, -1.0f,     0.6f, 0.2f, 0.2f, // Back Side

	-0.5f, 2.0f,  0.5f,      0.0f, 1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Top side
	-0.5f, 2.0f, -0.5f,      0.0f, 1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Top side
	 0.5f, 2.0f, -0.5f,      0.0f, 1.0f,  0.0f,     0.6f, 0.2f, 0.2f, // Top side
	 0.5f, 2.0f,  0.5f,      0.0f, 1.0f,  0.0f,     0.6f, 0.2f, 0.2f // Top side
};

//�ndices dos v�rtices dos blocos de ch�o/parede
GLuint blockIndices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side

	4, 6, 5, // Left side
	5, 6, 7, // Left side

	8, 9, 10, // Right side
	9, 10, 11, // Right side

	12, 13, 14, // Front side
	13, 14, 15, // Front side

	16, 17, 18, // Back side
	17, 18, 19, // Back side

	20, 21, 22, // Top side
	20, 22, 23 // Top side
};

//V�rtices da pir�mide
GLfloat vertices[] =
{ //     COORDINATES     /        NORMALS       //
	-0.5f, 1.0f,  0.5f,     0.0f, -1.0f, 0.0f, // Bottom side
	-0.5f, 0.0f, -0.5f,     0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f, -0.5f,     0.0f, -1.0f, 0.0f, // Bottom side
	 0.5f, 0.0f,  0.5f,     0.0f, -1.0f, 0.0f, // Bottom side

	-0.5f, 0.0f,  0.5f,     -0.8f, 0.5f,  0.0f, // Left Side
	-0.5f, 0.0f, -0.5f,     -0.8f, 0.5f,  0.0f, // Left Side
	 0.0f, 0.8f,  0.0f,     -0.8f, 0.5f,  0.0f, // Left Side

	-0.5f, 0.0f, -0.5f,     0.0f, 0.5f, -0.8f, // Non-facing side
	 0.5f, 0.0f, -0.5f,     0.0f, 0.5f, -0.8f, // Non-facing side
	 0.0f, 0.8f,  0.0f,     0.0f, 0.5f, -0.8f, // Non-facing side

	 0.5f, 0.0f, -0.5f,     0.8f, 0.5f,  0.0f, // Right side
	 0.5f, 0.0f,  0.5f,     0.8f, 0.5f,  0.0f, // Right side
	 0.0f, 0.8f,  0.0f,     0.8f, 0.5f,  0.0f, // Right side

	 0.5f, 0.0f,  0.5f,     0.0f, 0.5f,  0.8f, // Facing side
	-0.5f, 0.0f,  0.5f,     0.0f, 0.5f,  0.8f, // Facing side
	 0.0f, 0.8f,  0.0f,     0.0f, 0.5f,  0.8f  // Facing side
};

//�ndices usados pelo EBO
GLuint indices[] =
{
	0, 1, 2, // Bottom side
	0, 2, 3, // Bottom side
	4, 6, 5, // Left side
	7, 9, 8, // Non-facing side
	10, 12, 11, // Right side
	13, 15, 14 // Facing side
};

int main(void) {

	#pragma region Constantes

	const unsigned int height = 800;
	const unsigned int width = 800;

	#pragma endregion

	#pragma region Configura��o GLFW
	
	//Inicializa o GLFW
	glfwInit();

	//Configura��es de vers�o do GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Configura��o de profile do GLFW
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#pragma endregion

	#pragma region Cria��o da janela

	//Cria��o da janela usando o GLFW
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);

	//Cheque de erro para o caso de a janela n�o ser criada
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Coloca a janela criada no contexto atual
	glfwMakeContextCurrent(window);

	//Inicializa��o da GLEW
	GLenum err = glewInit();

	//Define o viewport do programa
	glViewport(0, 0, width, height);

	#pragma endregion

	#pragma region Objetos do programa

	//Cria��o do shader program a partir dos shaders
	Shader shaderProgram("default.vert", "default.frag");

	//Cria��o e binding do VAO
	VAO VAO1;
	VAO1.Bind();

	//Cria��o do VBO
	VBO VBO1(floorBlockVertices, sizeof(floorBlockVertices));

	//Cria��o do EBO
	EBO EBO1(blockIndices, sizeof(blockIndices));

	//Especifica��o dos atributos a ser interpretados pelo VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 9 * sizeof(float), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 3, GL_FLOAT, 9 * sizeof(float), (void*)(6 * sizeof(float)));

	//Unbinding do VBO, VAO e EBO
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	//Ativa��o do shader program
	shaderProgram.Activate();

	// Variables that help the rotation of the pyramid
	float rotation = 0.0f;
	double prevTime = glfwGetTime();

	//Ativa��o do teste de profundidade
	glEnable(GL_DEPTH_TEST);

	#pragma endregion

	#pragma region Loop do programa

	//Loop while principal. Roda o programa at� que a janela seja fechada
	while (!glfwWindowShouldClose(window)) {

		//Define a cor do fundo
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		//Limpa o BACK BUFFER e o DEPTH BUFFER
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Ativa��o do shader program
		shaderProgram.Activate();

		// Simple timer
		double crntTime = glfwGetTime();
		if (crntTime - prevTime >= 1 / 60)
		{
			rotation += 0.1f;
			prevTime = crntTime;
		}

		//Inicializa��o das matrizes model, view e projection
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		//Rotaciona o modelo
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));

		//Posiciona a c�mera
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -4.0f));

		//Adiciona a perspectiva
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		//Vincula as matrizes aos seus respectivos uniforms
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		//Binding do VAO
		VAO1.Bind();

		//Desenha os v�rtices
		glDrawElements(GL_TRIANGLES, sizeof(blockIndices) / sizeof(int), GL_UNSIGNED_INT, 0);

		//Troca as imagens do BACK BUFFER com as do FRONT BUFFER
		glfwSwapBuffers(window);

		//Processa os eventos do GLFW
		glfwPollEvents();
	}

	#pragma endregion

	#pragma region Destrui��es

	//Deleta o VAO, VBO e EBO
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();

	//Deleta o shader program
	shaderProgram.Delete();

	//Destr�i a janela e encerra o GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

	#pragma endregion
}