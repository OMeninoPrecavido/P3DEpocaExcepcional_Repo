#ifndef VBO_CLASS_H
#define VBO_CLASS_H
#define GLEW_STATIC

#include <GL\glew.h>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

class VBO
{
	public:

		//ID de refer�ncia do VBO. Gerado quando o VBO � criado
		GLuint ID;

		//Construtor -> Cria o VBO e vincula ele aos v�rtices fornecidos
		VBO(GLfloat* vertices, GLsizeiptr size);

		//D� bind ao VBO
		void Bind();

		//D� unbind ao VBO
		void Unbind();

		//Deleta o VBO
		void Delete();
};

#endif