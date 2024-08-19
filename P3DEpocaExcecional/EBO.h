#ifndef EBO_CLASS_H
#define EBO_CLASS_H
#define GLEW_STATIC

#include <GL\glew.h>

class EBO
{
	public:

		//ID de referência do EBO. Gerado quando o EBO é criado
		GLuint ID;

		//Construtor -> Gera o EBO e vincula ele aos índices
		EBO(GLuint* indices, GLsizeiptr size);

		//Dá bind ao EBO
		void Bind();

		//Dá unbind ao EBO
		void Unbind();

		//Deleta o EBO
		void Delete();
};

#endif