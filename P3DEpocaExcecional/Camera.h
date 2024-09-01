#ifndef CAMERA_CLASS_H
#define CAMERA_CLASS_H

#include <GL\glew.h>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

#include<GLFW/glfw3.h>

#define GLM_ENABLE_EXPERIMENTAL //Macro para que determinadas funções da glm possam ser usadas
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>

#include"shaderClass.h"

class Camera
{
public:
	//Principais vetores da câmera
	glm::vec3 Position;
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 cameraMatrix = glm::mat4(1.0f);
	glm::vec3 AddToCamTarget;

	//Altura e largura da janela
	int width;
	int height;

	//Escala ortogonal
	float orthogonalScale = 20.0f;

	//Velocidade da câmer
	float speed = 0.05f;

	//Construtor -> Recebe a altura e largura da janela e a posição da câmera
	Camera(int width, int height, glm::vec3 position);

	//Atualiza a matriz da câmera (view * projection)
	void updateMatrix(float FOVdeg, float nearPlane, float farPlane);

	//Exporta a matriz da câmera ao vertex shader
	void Matrix(Shader& shader, const char* uniform);

	//Recebe os inputs para a movimentação da câmera
	void Inputs(GLFWwindow* window);
};
#endif
