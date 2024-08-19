#ifndef EBO_CLASS_H
#define EBO_CLASS_H
#define GLEW_STATIC

#include <GL\glew.h>

class EBO
{
	public:

		//ID de refer�ncia do EBO. Gerado quando o EBO � criado
		GLuint ID;

		//Construtor -> Gera o EBO e vincula ele aos �ndices
		EBO(GLuint* indices, GLsizeiptr size);

		//D� bind ao EBO
		void Bind();

		//D� unbind ao EBO
		void Unbind();

		//Deleta o EBO
		void Delete();
};

#endif