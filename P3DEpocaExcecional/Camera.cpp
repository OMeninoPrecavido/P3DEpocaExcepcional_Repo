#include"Camera.h"

//Construtor -> Recebe a altura e largura da janela e a posição da câmera
Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
	AddToCamTarget = glm::vec3(0.0f, 0.0f, 0.0f);
}

//Atualiza a matriz da câmera (view * projection)
void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	//Inicialização das matrizes view e projection
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	//Posiciona a câmera
	glm::vec3 cameraTarget = glm::vec3(30.0f / 2.0f, 0.0f, 30.0f / 2.0f);
	glm::vec3 up = glm::vec3(0.0f, 0.0f, -1.0f);

	view = glm::lookAt(Position, cameraTarget + AddToCamTarget , up);

	//Para outro efeito de movimentação:
	//view = glm::lookAt(Position, cameraTarget, up);

	//Adiciona perspectiva a cena
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	//Define o valor da matriz da câmera
	cameraMatrix = projection * view;
}

//Exporta a matriz da câmera ao vertex shader
void Camera::Matrix(Shader& shader, const char* uniform)
{
	//Expora a matriz da câmera ao vertex shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

//Recebe os inputs para a movimentação da câmera
void Camera::Inputs(GLFWwindow* window)
{
	//Inputs para a movimentação
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(0.0f, 0.0f, -1.0f);
		AddToCamTarget += speed * glm::vec3(0.0f, 0.0f, -1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(-1.0f, 0.0f, 0.0f);
		AddToCamTarget += speed * glm::vec3(-1.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(0.0f, 0.0f, 1.0f);
		AddToCamTarget += speed * glm::vec3(0.0f, 0.0f, 1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(1.0f, 0.0f, 0.0f);
		AddToCamTarget += speed * glm::vec3(1.0f, 0.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(0.0f, 1.0f, 0.0f);
		AddToCamTarget += speed * glm::vec3(0.0f, 1.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(0.0f, -1.0f, 0.0f);
		AddToCamTarget += speed * glm::vec3(0.0f, -1.0f, 0.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
	{
		speed = 0.4f;
	}
	else if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE)
	{
		speed = 0.1f;
	}
}