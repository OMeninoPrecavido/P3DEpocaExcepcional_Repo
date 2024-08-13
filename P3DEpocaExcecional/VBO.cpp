#include"VBO.h"

//Construtor -> Cria o VBO e vincula ele aos vértices fornecidos
VBO::VBO(GLfloat* vertices, GLsizeiptr size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

//Dá bind ao VBO
void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

//Dá unbind ao VBO
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

//Deleta o VBO
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}