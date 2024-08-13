#version 330 core

//Positions/Coordinates
layout (location = 0) in vec3 aPos;

void main()
{
	//Outputs the positions/coordinates of all vertices
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
}