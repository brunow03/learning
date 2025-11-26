#include "libs.h"

void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
}

void updateInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int main(int argc, char const *argv[])
{
	// INIT GLFW
	glfwInit();

	// CREATE WINDOW VARIABLES
	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 600;
	int frambufferWidth = 0;
	int frambufferHeight = 0;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); Mac OS

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "WHO AM I?", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
	// glfwGetFramebufferSize(window, &frambufferWidth, &frambufferHeight);
	// glViewport(0, 0, frambufferWidth, frambufferHeight);

	glfwMakeContextCurrent(window); // IMPORTANT!!

	// INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
	glewExperimental = GL_TRUE;

	// Error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "ERROR::MAIN.CPP::GLEW_INIT_FAILED" << "\n";
		glfwTerminate();
	}

	// MAIN LOOP
	while(!glfwWindowShouldClose(window)) 
	{
		// UPDATE INPUT ---
		glfwPollEvents();

		// UPDATE ---
		updateInput(window);

		// DRAW ---
		// Clear
		glClearColor(0.f, 0.f, 0.f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		// Draw

		// End Draw
		glfwSwapBuffers(window);
		glFlush();
	}

	// END OF PROGRAM
	glfwTerminate();

	return 0;
}