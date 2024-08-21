#include"EBO.h"

//Construtor -> Gera o EBO e vincula ele aos índices
EBO::EBO(std::vector<GLuint>& indices)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
}

//Dá bind ao EBO
void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

//Dá unbind ao EBO
void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

//Deleta EBO
void EBO::Delete()
{
	glDeleteBuffers(1, &ID);
}