#version 330 core

//Outputs do fragment shader
out vec4 FragColor;

//Inputs vindos do vertex shader
in vec3 Normal;
in vec3 Color;

void main()
{
	//Direção da luz direcional
	vec3 lightDirection = normalize(vec3(-1.0f, -0.5f, 0.0f));

	//Iluminação ambiente
	float ambient = 0.50f;

	//Normal do vértice
	vec3 normal = normalize(Normal);

	//Cor do vértice
	vec3 color = Color;

	//Produto escalar entre a normal e a direção da luz
	float diffuse = max(dot(normal, lightDirection), 0.0f);

	FragColor = vec4(color, 1.0f) * (ambient + diffuse);
}