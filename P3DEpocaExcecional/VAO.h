#ifndef VAO_CLASS_H
#define VAO_CLASS_H
#define GLEW_STATIC

#include <GL\glew.h>
#include "VBO.h"

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

class VAO
{
	public:

		//ID de refer�ncia do VAO. Gerado quando o VAO � criado
		GLuint ID;

		//Construtor -> Gera o VAO e seu ID
		VAO();

		//Define um atributo dos v�rtices a ser interpretado pelo VAO
		void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

		//D� bind ao VAO
		void Bind();

		//D� Unbind ao VAO
		void Unbind();

		//Deleta o VAO
		void Delete();
};

#endif
