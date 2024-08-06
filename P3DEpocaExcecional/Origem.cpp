#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>

#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "opengl32.lib")

int main(void) {
	GLFWwindow* window;

	if (!glfwInit()) return -1;

	window = glfwCreateWindow(800, 600, "Window", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;
}