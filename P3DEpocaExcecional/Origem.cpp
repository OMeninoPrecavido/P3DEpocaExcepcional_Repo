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

//
// Vértices do quad
float quadVertices[] = {
    // Posições        // Coordenadas de textura
    -1.0f,  1.0f, 0.0f,  0.0f, 1.0f, // Topo esquerdo
    -1.0f, -1.0f, 0.0f,  0.0f, 0.0f, // Inferior esquerdo
     1.0f, -1.0f, 0.0f,  1.0f, 0.0f, // Inferior direito

    -1.0f,  1.0f, 0.0f,  0.0f, 1.0f, // Topo esquerdo
     1.0f, -1.0f, 0.0f,  1.0f, 0.0f, // Inferior direito
     1.0f,  1.0f, 0.0f,  1.0f, 1.0f  // Topo direito
};
//

#pragma endregion

#pragma region Constantes

const unsigned int height = 800;
const unsigned int width = 800;

const unsigned int minimapHeight = height / 4;
const unsigned int minimapWidth = width / 4;

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

	Shader minimapShader("minimap.vert", "minimap.frag");

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

	// IDs para o framebuffer e a textura
	GLuint minimapFBO;
	GLuint minimapTexture;

	// Passo 1: Gerar e configurar o framebuffer
	glGenFramebuffers(1, &minimapFBO);
	glBindFramebuffer(GL_FRAMEBUFFER, minimapFBO);

	// Passo 2: Criar uma textura para armazenar o minimapa
	glGenTextures(1, &minimapTexture);
	glBindTexture(GL_TEXTURE_2D, minimapTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, minimapWidth, minimapHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

	// Parâmetros de textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	// Associar a textura ao framebuffer
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, minimapTexture, 0);

	// Verificar se o framebuffer está completo
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE) {
		std::cerr << "Erro ao criar o framebuffer para o minimapa!" << std::endl;
	}

	// Desvincular o framebuffer atual
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// IDs para o VAO e VBO do quad
	GLuint quadVAO, quadVBO;

	// Geração e configuração do VAO e VBO do quad
	glGenVertexArrays(1, &quadVAO);
	glGenBuffers(1, &quadVBO);

	glBindVertexArray(quadVAO);

	glBindBuffer(GL_ARRAY_BUFFER, quadVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(quadVertices), quadVertices, GL_STATIC_DRAW);

	// Atributo de posição
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Atributo de coordenada de textura
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// Desvincular VAO e VBO
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	//Ativação do shader program
	shaderProgram.Activate();

	//Ativação do teste de profundidade
	glEnable(GL_DEPTH_TEST);

	//Cria o objeto câmera
	Camera camera(width, height, glm::vec3(0.0f, 15.0f * float(sqrt(2)), 30.0f));

	Camera minimapCam(width, height, glm::vec3(15.0f, 40.0f, 15.0f));

	#pragma endregion

	#pragma region Loop do programa

	//Loop while principal. Roda o programa até que a janela seja fechada
	while (!glfwWindowShouldClose(window)) {

		glBindFramebuffer(GL_FRAMEBUFFER, 0);

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

		//Inicialização da matriz model
		glm::mat4 model = glm::mat4(1.0f);

		//Exporta a matriz model ao seu uniform, no vertex shader
		int modelLoc = glGetUniformLocation(shaderProgram.ID, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		//Exporta a camMatrix (view * projection) ao seu uniform, no vertex shader
		camera.Matrix(shaderProgram, "camMatrix");

		//Binding do VAO
		VAO1.Bind();

		//Desenha os vértices
		glDrawElements(GL_TRIANGLES, mazeIndices.size(), GL_UNSIGNED_INT, 0);


		//

		// Passo 1: Renderizar o minimapa no framebuffer
		glBindFramebuffer(GL_FRAMEBUFFER, minimapFBO);
		glViewport(0, 0, minimapWidth, minimapHeight);
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		minimapCam.updateMinimapMatrix(45.0f, 0.1f, 100.0f);
		minimapCam.Matrix(shaderProgram, "camMatrix");
		
		glDrawElements(GL_TRIANGLES, mazeIndices.size(), GL_UNSIGNED_INT, 0);

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		VAO1.Unbind();

		// Passo 2: Renderizar o minimapa como um quad na janela principal
		int minimapX = 0;
		int minimapY = height - minimapHeight; // Para alinhar o topo do minimapa ao topo da janela principal

		glViewport(minimapX, minimapY, minimapWidth, minimapHeight);
		glDisable(GL_DEPTH_TEST);
		minimapShader.Activate();
		glUniform1i(glGetUniformLocation(minimapShader.ID, "minimapTexture"), 0); // 0 se a textura estiver na unidade de textura 0
		// Vincula a textura
		glActiveTexture(GL_TEXTURE0); // Unidade de textura 0
		glBindTexture(GL_TEXTURE_2D, minimapTexture);

		glBindVertexArray(quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);
		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
		glEnable(GL_DEPTH_TEST);
		//

		glViewport(0, 0, height, width);

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