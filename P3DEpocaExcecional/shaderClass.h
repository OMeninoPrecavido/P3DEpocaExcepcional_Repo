#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H
#define GLEW_STATIC

#include<GL\glew.h>
#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<cerrno>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

//Lê os ficheiros shader .vert e .frag e transforma-os em uma string
std::string get_file_contents(const char* filename);

class Shader
{
	public:

		//ID de referência do shader. Gerado quando o shader program é criado
		GLuint ID;

		//Construtor -> Cria um shader program a partir de um vertex shader e um fragment shader
		Shader(const char* vertexFile, const char* fragmentFile);

		//Ativa o Shader Program
		void Activate();

		//Deleta o Shader Program
		void Delete();

	private:

		//Checa se os diferentes shaders compilaram corretamente
		void compileErrors(unsigned int shader, const char* type);
};


#endif
