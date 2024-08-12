#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

int main(void) {

	#pragma region Constantes

	const unsigned int height = 800;
	const unsigned int width = 800;

	#pragma endregion

	#pragma region Configuração GLFW
	
	//Inicializa o GLFW
	glfwInit();

	//Configurações de versão do GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	//Configuração de profile do GLFW
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#pragma endregion

	#pragma region Criação da janela

	//Criação da janela usando o GLFW
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);

	//Cheque de erro para o caso de a janela não ser criada
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	//Coloca a janela criada no contexto atual
	glfwMakeContextCurrent(window);

	//Define o viewport do programa
	glViewport(0, 0, width, height);

	#pragma endregion

	#pragma region Loop do programa

	//Loop while principal. Roda o programa até que a janela seja fechada
	while (!glfwWindowShouldClose(window)) {

		//Define a cor do fundo
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		//Limpa o BACK BUFFER e o DEPTH BUFFER
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Troca as imagens do BACK BUFFER com as do FRONT BUFFER
		glfwSwapBuffers(window);

		//Processa os eventos do GLFW
		glfwPollEvents();
	}

	#pragma endregion

	#pragma region Destruições

	//Destrói a janela e encerra o GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	#pragma endregion
}