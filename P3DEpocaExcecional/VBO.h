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

		//ID de referência do VBO. Gerado quando o VBO é criado
		GLuint ID;

		//Construtor -> Cria o VBO e vincula ele aos vértices fornecidos
		VBO(GLfloat* vertices, GLsizeiptr size);

		//Dá bind ao VBO
		void Bind();

		//Dá unbind ao VBO
		void Unbind();

		//Deleta o VBO
		void Delete();
};

#endif