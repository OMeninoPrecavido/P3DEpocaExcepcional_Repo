#ifndef EBO_CLASS_H
#define EBO_CLASS_H
#define GLEW_STATIC

#include <GL\glew.h>
#include <vector>

class EBO
{
	public:

		//ID de refer�ncia do EBO. Gerado quando o EBO � criado
		GLuint ID;

		//Construtor -> Gera o EBO e vincula ele aos �ndices
		EBO(std::vector<GLuint>& indices);

		//D� bind ao EBO
		void Bind();

		//D� unbind ao EBO
		void Unbind();

		//Deleta o EBO
		void Delete();
};

#endif