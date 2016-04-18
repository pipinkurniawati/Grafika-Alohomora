#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;


static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}


int main(int argc, char** argv)
{     
	GLFWwindow* window;
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
	  exit(EXIT_FAILURE);
	window = glfwCreateWindow(1280, 640, "Rubik", NULL, NULL);
	if (!window)
	{
	  glfwTerminate();
	  exit(EXIT_FAILURE);
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	while (!glfwWindowShouldClose(window))
	{
		float ratio;
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		ratio = width / (float) height;
		glViewport(0, 0, width, height);
		glClear(GL_COLOR_BUFFER_BIT);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

	    // Row 1 Front
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.6f, 0.3f, 0.1f);
		glVertex3f(-0.3f, 0.3f, 0.1f);
		glVertex3f(-0.3f, 0.6f, 0.1f);
		glVertex3f(-0.6f, 0.6f, 0.1f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.2f, 0.3f, 0.1f);
		glVertex3f(0.1f, 0.3f, 0.1f);
		glVertex3f(0.1f, 0.6f, 0.1f);
		glVertex3f(-0.2f, 0.6f, 0.1f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.2f, 0.3f, 0.1f);
		glVertex3f(0.5f, 0.3f, 0.1f);
		glVertex3f(0.5f, 0.6f, 0.1f);
		glVertex3f(0.2f, 0.6f, 0.1f);
		glEnd();

		// Row 2 Front
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.6f, -0.1f, 0.1f);
		glVertex3f(-0.3f, -0.1f, 0.1f);
		glVertex3f(-0.3f, 0.2f, 0.1f);
		glVertex3f(-0.6f, 0.2f, 0.1f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.2f, -0.1f, 0.1f);
		glVertex3f(0.1f, -0.1f, 0.1f);
		glVertex3f(0.1f, 0.2f, 0.1f);
		glVertex3f(-0.2f, 0.2f, 0.1f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.2f, -0.1f, 0.1f);
		glVertex3f(0.5f, -0.1f, 0.1f);
		glVertex3f(0.5f, 0.2f, 0.1f);
		glVertex3f(0.2f, 0.2f, 0.1f);
		glEnd();

		// Row 3 Front
		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.6f, -0.5f, 0.1f);
		glVertex3f(-0.3f, -0.5f, 0.1f);
		glVertex3f(-0.3f, -0.2f, 0.1f);
		glVertex3f(-0.6f, -0.2f, 0.1f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-0.2f, -0.5f, 0.1f);
		glVertex3f(0.1f, -0.5f, 0.1f);
		glVertex3f(0.1f, -0.2f, 0.1f);
		glVertex3f(-0.2f, -0.2f, 0.1f);
		glEnd();

		glBegin(GL_QUADS);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.2f, -0.5f, 0.1f);
		glVertex3f(0.5f, -0.5f, 0.1f);
		glVertex3f(0.5f, -0.2f, 0.1f);
		glVertex3f(0.2f, -0.2f, 0.1f);
		glEnd();


        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}