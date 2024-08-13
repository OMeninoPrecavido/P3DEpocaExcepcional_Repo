#include "VAO.h"

//Construtor -> Gera o VAO e seu ID
VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

//Define um atributo dos vértices a ser interpretado pelo VAO
void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset); //Define o atributo e suas características
	glEnableVertexAttribArray(layout); //"Salva" o atributo
	VBO.Unbind();
}

//Dá bind ao VAO
void VAO::Bind()
{
	glBindVertexArray(ID);
}

//Dá unbind ao VAO
void VAO::Unbind()
{
	glBindVertexArray(0);
}

//Deleta VAO
void VAO::Delete()
{
	glDeleteVertexArrays(1, &ID);
}