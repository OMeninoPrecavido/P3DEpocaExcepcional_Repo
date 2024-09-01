#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"
#include"Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

#pragma region Vértices e índices

//Vértices do bloco de chão
std::vector<Vertex> floorBlockVertices =
{ //			COORDINATES			     /			  NORMALS		     /		    	COLORS		    //
	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Bottom side
	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Bottom side
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Bottom side
	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Bottom side

	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Left side
	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Left side
	Vertex{glm::vec3(-0.5f, 1.0f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Left side
	Vertex{glm::vec3(-0.5f, 1.0f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Left side

	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Right side
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Right side
	Vertex{glm::vec3( 0.5f, 1.0f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Right side
	Vertex{glm::vec3( 0.5f, 1.0f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Right side

	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Front side
	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Front side
	Vertex{glm::vec3(-0.5f, 1.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Front side
	Vertex{glm::vec3( 0.5f, 1.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Front side

	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Back side
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Back side
	Vertex{glm::vec3(-0.5f, 1.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Back side
	Vertex{glm::vec3( 0.5f, 1.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Back side

	Vertex{glm::vec3(-0.5f, 1.0f,  0.5f), glm::vec3( 0.0f, 1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Top side
	Vertex{glm::vec3(-0.5f, 1.0f, -0.5f), glm::vec3( 0.0f, 1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Top side
	Vertex{glm::vec3( 0.5f, 1.0f, -0.5f), glm::vec3( 0.0f, 1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}, // Top side
	Vertex{glm::vec3( 0.5f, 1.0f,  0.5f), glm::vec3( 0.0f, 1.0f,  0.0f), glm::vec3(0.2f, 0.2f, 0.6f)}  // Top side
};

//Vértices do bloco de parede
std::vector<Vertex> wallBlockVertices =
{ //			COORDINATES			     /			  NORMALS		     /		    	COLORS		    //
	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Bottom side
	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Bottom side
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Bottom side
	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f), glm::vec3( 0.0f, -1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Bottom side

	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Left side
	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Left side
	Vertex{glm::vec3(-0.5f, 2.0f,  0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Left side
	Vertex{glm::vec3(-0.5f, 2.0f, -0.5f), glm::vec3(-1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Left side

	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Right side
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Right side
	Vertex{glm::vec3( 0.5f, 2.0f,  0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Right side
	Vertex{glm::vec3( 0.5f, 2.0f, -0.5f), glm::vec3( 1.0f,  0.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Right side

	Vertex{glm::vec3(-0.5f, 0.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Front side
	Vertex{glm::vec3( 0.5f, 0.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Front side
	Vertex{glm::vec3(-0.5f, 2.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Front side
	Vertex{glm::vec3( 0.5f, 2.0f,  0.5f), glm::vec3( 0.0f,  0.0f,  1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Front side

	Vertex{glm::vec3(-0.5f, 0.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Back side
	Vertex{glm::vec3( 0.5f, 0.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Back side
	Vertex{glm::vec3(-0.5f, 2.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Back side
	Vertex{glm::vec3( 0.5f, 2.0f, -0.5f), glm::vec3( 0.0f,  0.0f, -1.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Back side

	Vertex{glm::vec3(-0.5f, 2.0f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Top side
	Vertex{glm::vec3(-0.5f, 2.0f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Top side
	Vertex{glm::vec3( 0.5f, 2.0f, -0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}, // Top side
	Vertex{glm::vec3( 0.5f, 2.0f,  0.5f), glm::vec3( 0.0f,  1.0f,  0.0f), glm::vec3(0.6f, 0.2f, 0.2f)}  // Top side
};

//Índices dos vértices dos blocos de chão/parede
std::vector<GLuint> blockIndices =
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

#pragma endregion

#pragma region Constantes

const unsigned int height = 800;
const unsigned int width = 800;

#pragma endregion

int main(void) {

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

	//Inicialização da GLEW
	GLenum err = glewInit();

	//Define o viewport do programa
	glViewport(0, 0, width, height);

	#pragma endregion

	#pragma region Objetos do programa

	//Aqui serão armazenados os vértices e índices do labirinto
	std::vector<Vertex> maze;
	std::vector<GLuint> mazeIndices;

	//Abre o ficheiro com o layout do labirinto
	const std::string filename = "labirinto.txt";
	std::ifstream file(filename);

	//Verifica se o arquivo foi aberto com sucesso
	if (!file.is_open()) {
		std::cerr << "Não foi possível abrir o arquivo: " << filename << std::endl;
	}

	//O bloco de código abaixo realiza a leitura do ficheiro e produz um conjunto de vértices e um conjunto de
	//índices que forma um labirinto de acordo com os dados do ficheiro.
	char ch;
	GLuint XVal = 0;
	GLuint ZVal = 0;
	while (file.get(ch)) {

		std::vector<Vertex> newBlockVertices;
		std::vector<GLuint> newBlockIndices;

		if (ch == '0') {
			for (Vertex vert : floorBlockVertices)
			{
				newBlockVertices.push_back(vert.Move(glm::vec3(XVal + 1.0f, 0.0f, ZVal + 1.0f)));
			}
			for (GLuint idx : blockIndices)
			{
				newBlockIndices.push_back(idx + maze.size());
			}
			XVal++;
		}
		else if (ch == '1') {
			for (Vertex vert : wallBlockVertices)
			{
				newBlockVertices.push_back(vert.Move(glm::vec3(XVal + 1.0f, 0.0f, ZVal + 1.0f)));
			}
			for (GLuint idx : blockIndices)
			{
				newBlockIndices.push_back(idx + maze.size());
			}
			XVal++;
		}
		else if (ch == '\n') {
			XVal = 0;
			ZVal++;
		}

		maze.insert(maze.end(), newBlockVertices.begin(), newBlockVertices.end());
		mazeIndices.insert(mazeIndices.end(), newBlockIndices.begin(), newBlockIndices.end());
	}

	//Fecha o arquivo
	file.close();

	//Criação do shader program a partir dos shaders
	Shader shaderProgram("default.vert", "default.frag");

	//Criação e binding do VAO
	VAO VAO1;
	VAO1.Bind();

	//Criação do VBO
	VBO VBO1(maze);

	//Criação do EBO
	EBO EBO1(mazeIndices);

	//Especificação dos atributos a ser interpretados pelo VAO
	VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, sizeof(Vertex), (void*)0);
	VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, sizeof(Vertex), (void*)(3 * sizeof(float)));
	VAO1.LinkAttrib(VBO1, 2, 3, GL_FLOAT, sizeof(Vertex), (void*)(6 * sizeof(float)));

	//Unbinding do VBO, VAO e EBO
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	//Ativação do shader program
	shaderProgram.Activate();

	//Ativação do teste de profundidade
	glEnable(GL_DEPTH_TEST);

	//Cria o objeto câmera
	Camera camera(width, height, glm::vec3(0.0f, 15.0f * float(sqrt(2)), 30.0f));

	#pragma endregion

	#pragma region Loop do programa

	//Loop while principal. Roda o programa até que a janela seja fechada
	while (!glfwWindowShouldClose(window)) {

		//Define a cor do fundo
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);

		//Limpa o BACK BUFFER e o DEPTH BUFFER
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Recebe os inputs da câmera
		camera.Inputs(window);

		//Atualiza a matriz da câmera
		camera.updateMatrix(45.0f, 0.1f, 1000.0f);

		//Ativação do shader program
		shaderProgram.Activate();

		//Inicialização das matrizes model, view e projection
		glm::mat4 model = glm::mat4(1.0f);

		//Exporta a matriz model ao seu uniform, no vertex shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		//Exporta a camMatrix (view * projection) ao seu unfirom, no vertex shader
		camera.Matrix(shaderProgram, "camMatrix");

		//Binding do VAO
		VAO1.Bind();

		//Desenha os vértices
		glDrawElements(GL_TRIANGLES, mazeIndices.size(), GL_UNSIGNED_INT, 0);

		//Troca as imagens do BACK BUFFER com as do FRONT BUFFER
		glfwSwapBuffers(window);

		//Processa os eventos do GLFW
		glfwPollEvents();
	}

	#pragma endregion

	#pragma region Destruições

	//Deleta o VAO, VBO e EBO
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();

	//Deleta o shader program
	shaderProgram.Delete();

	//Destrói a janela e encerra o GLFW
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

	#pragma endregion
}