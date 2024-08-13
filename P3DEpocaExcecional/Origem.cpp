#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

//V�rtices do tri�ngulo
GLfloat vertices[] =
{ // COORDENADAS //
		-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower left corner
		0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f, // Lower right corner
		0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f // Upper corner
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
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

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
	VBO VBO1(vertices, sizeof(vertices));

	//Especifica��o dos atributos a ser interpretados pelo VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

	//Unbinding do VBO e VAO
	VAO1.Unbind();
	VBO1.Unbind();

	//Ativa��o do shader program
	shaderProgram.Activate();

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

		//Binding do VAO
		VAO1.Bind();

		//Desenha os v�rtices
		glDrawArrays(GL_TRIANGLES, 0, 3);

		//Troca as imagens do BACK BUFFER com as do FRONT BUFFER
		glfwSwapBuffers(window);

		//Processa os eventos do GLFW
		glfwPollEvents();
	}

	#pragma endregion

	#pragma region Destrui��es

	VAO1.Delete();
	VBO1.Delete();

	shaderProgram.Delete();

	//Destr�i a janela e encerra o GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	#pragma endregion
}