#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#define GLEW_STATIC

#include <GL\glew.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;

	Vertex Move(glm::vec3 moveVec) {
		glm::vec3 newPos = position + moveVec;
		return Vertex{ glm::vec3(newPos), glm::vec3(normal), glm::vec3(color) };
	}
};

class VBO
{
	public:

		//ID de refer�ncia do VBO. Gerado quando o VBO � criado
		GLuint ID;

		//Construtor -> Cria o VBO e vincula ele aos v�rtices fornecidos
		VBO(std::vector<Vertex>& vertices);

		//D� bind ao VBO
		void Bind();

		//D� unbind ao VBO
		void Unbind();

		//Deleta o VBO
		void Delete();
};

#endif