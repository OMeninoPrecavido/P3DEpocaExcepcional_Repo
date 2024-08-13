#include"shaderClass.h"

//Lê os ficheiros shader .vert e .frag e transforma-os em uma string
std::string get_file_contents(const char* filename)
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

//Construtor -> Cria um shader program a partir de um vertex shader e um fragment shader
Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	//Lê os ficheiros .vert e .frag e transforma-os em strings
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	//Transforma as strings geradas em c strings (arrays de caracteres)
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	//VERTEX SHADER OBJECT

	//Cria o vertex shader object
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//Vincula o código do vertex shader ao vertex shader object
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	//Compila o vertex shader em código maquina
	glCompileShader(vertexShader);
	//Checka se o vertex shader compilou corretamente
	compileErrors(vertexShader, "VERTEX");

	//FRAGMENT SHADER OBJECT

	//Cria o fragment shader object
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//Vincula o código do fragment shader o fragment shader object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	//Compila o fragment shader em código máquina
	glCompileShader(fragmentShader);
	//Checa se o fragmente shader compilou corretamente
	compileErrors(fragmentShader, "FRAGMENT");

	//SHADER PROGRAM

	//Cria o shader program object e coloca sua referência no ID
	ID = glCreateProgram();
	//Vincula os vertex e fragment shader criados ao shader program object
	glAttachShader(ID, vertexShader);
	glAttachShader(ID, fragmentShader);
	//"Confirma" o vínculo
	glLinkProgram(ID);
	//Checa se os shaders foram vinculados corretamente
	compileErrors(ID, "PROGRAM");

	//Deleta o vertex shader object e o fragment shader object
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

}

//Ativa o Shader Program
void Shader::Activate()
{
	glUseProgram(ID);
}

//Deleta o shader program
void Shader::Delete()
{
	glDeleteProgram(ID);
}

//Checa se os diferentes shaders compilaram corretamente
void Shader::compileErrors(unsigned int shader, const char* type)
{
	//Guarda o status de compilação
	GLint hasCompiled;
	//Char array pra guardar a mensagem de erro
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_COMPILATION_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << "SHADER_LINKING_ERROR for:" << type << "\n" << infoLog << std::endl;
		}
	}
}