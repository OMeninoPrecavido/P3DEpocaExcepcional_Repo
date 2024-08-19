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

//V�rtices do tri�ngulo
GLfloat vertices[] =
{ // COORDENADAS //
	-0.5f, 0.0f,  0.5f,
	-0.5f, 0.0f, -0.5f,
	 0.5f, 0.0f, -0.5f,
	 0.5f, 0.0f,  0.5f,
	 0.0f, 0.8f,  0.0f
};

GLuint indices[] =
{
	0, 1, 2,
	0, 2, 3,
	0, 1, 4,
	1, 2, 4,
	2, 3, 4,
	3, 0, 4
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
	VBO VBO1(vertices, sizeof(vertices));

	EBO EBO1(indices, sizeof(indices));

	//Especifica��o dos atributos a ser interpretados pelo VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

	//Unbinding do VBO e VAO
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

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

		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(shaderProgram.ID, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(shaderProgram.ID, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));

		//Binding do VAO
		VAO1.Bind();

		//Desenha os v�rtices
		glDrawElements(GL_TRIANGLES, sizeof(indices) / sizeof(int), GL_UNSIGNED_INT, 0);

		//Troca as imagens do BACK BUFFER com as do FRONT BUFFER
		glfwSwapBuffers(window);

		//Processa os eventos do GLFW
		glfwPollEvents();
	}

	#pragma endregion

	#pragma region Destrui��es

	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();

	shaderProgram.Delete();

	//Destr�i a janela e encerra o GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

	#pragma endregion
}