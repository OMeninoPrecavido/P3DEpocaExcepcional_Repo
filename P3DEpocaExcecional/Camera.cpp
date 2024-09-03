#include"Camera.h"

//Construtor -> Recebe a altura e largura da janela e a posi��o da c�mera
Camera::Camera(int width, int height, glm::vec3 position)
{
	Camera::width = width;
	Camera::height = height;
	Position = position;
	AddToCamTarget = glm::vec3(0.0f, 0.0f, 0.0f);
}

//Atualiza a matriz da c�mera (view * projection)
void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane)
{
	//Inicializa��o das matrizes view e projection
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	//Posiciona a c�mera
	glm::vec3 cameraTarget = glm::vec3(15.0f, 0.0f, 15.0f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	view = glm::lookAt(Position, cameraTarget + AddToCamTarget , up);

	//Para outro efeito de movimenta��o:
	//view = glm::lookAt(Position, cameraTarget, up);

	//Adiciona perspectiva a cena

	// Definir os limites da proje��o ortogr�fica
	float aspectRatio = (float)width / height;
	float orthoScale = orthogonalScale; // ajuste conforme necess�rio
	float left = -orthoScale * aspectRatio;
	float right = orthoScale * aspectRatio;
	float bottom = -orthoScale;
	float top = orthoScale;

	//projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);
	projection = glm::ortho(left, right, bottom, top, nearPlane, farPlane);

	//Define o valor da matriz da c�mera
	cameraMatrix = projection * view;
}

//Atualiza a matriz da c�mera do minimapa
void Camera::updateMinimapMatrix(float FOVdeg, float nearPlane, float farPlane) {
	//Inicializa��o das matrizes view e projection
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	//Posiciona a c�mera
	glm::vec3 cameraTarget = glm::vec3(30.0f / 2.0f, 0.0f, 30.0f / 2.0f);
	glm::vec3 up = glm::vec3(0.0f, 0.0f, -1.0f);

	view = glm::lookAt(Position, cameraTarget, up);

	//Adiciona perspectiva a cena
	projection = glm::perspective(glm::radians(FOVdeg), (float)width / height, nearPlane, farPlane);

	//Define o valor da matriz da c�mera
	cameraMatrix = projection * view;
}

//Exporta a matriz da c�mera ao vertex shader
void Camera::Matrix(Shader& shader, const char* uniform)
{
	//Expora a matriz da c�mera ao vertex shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

//Recebe os inputs para a movimenta��o da c�mera
void Camera::Inputs(GLFWwindow* window)
{
	//Inputs para a movimenta��o
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(1.0f, 0.0f, -1.0f);
		AddToCamTarget += speed * glm::vec3(1.0f, 0.0f, -1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(-1.0f, 0.0f, -1.0f);
		AddToCamTarget += speed * glm::vec3(-1.0f, 0.0f, -1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(-1.0f, 0.0f, 1.0f);
		AddToCamTarget += speed * glm::vec3(-1.0f, 0.0f, 1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * glm::vec3(1.0f, 0.0f, 1.0f);
		AddToCamTarget += speed * glm::vec3(1.0f, 0.0f, 1.0f);
	}
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		orthogonalScale += speed;
	}
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		orthogonalScale -= speed;
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
