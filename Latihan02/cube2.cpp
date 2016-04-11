#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}
int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Cube", NULL, NULL);
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

        glBegin(GL_POLYGON);
        glColor3f(1.f, 0.f, 0.f);
        glVertex3f(-0.500000, -0.500000, 0.500000);
        glVertex3f(0.500000, -0.500000, 0.500000);
        glVertex3f(0.500000, 0.500000, 0.500000);
        glVertex3f(-0.500000, 0.500000, 0.500000);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.f, 1.f, 0.f);
        glVertex3f(-0.500000, 0.500000, 0.500000);
        glVertex3f(0.500000, 0.500000, 0.500000);
        glVertex3f(0.500000, 0.500000, -0.500000);
        glVertex3f(-0.500000, -0.500000, -0.500000);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.f, 0.f, 1.f);
        glVertex3f(-0.500000, 0.500000, -0.500000);
        glVertex3f(0.500000, 0.500000, -0.500000);
        glVertex3f(0.500000, -0.500000, -0.500000);
        glVertex3f(-0.500000, -0.500000, -0.500000);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.f, 1.f, 0.f);
        glVertex3f(-0.500000, -0.500000, -0.500000);
        glVertex3f(0.500000, -0.500000, -0.500000);
        glVertex3f(0.500000, -0.500000, 0.500000);
        glVertex3f(-0.500000, -0.500000, 0.500000);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.f, 1.f, 1.f);
        glVertex3f(0.500000, -0.500000, 0.500000);
        glVertex3f(0.500000, -0.500000, -0.500000);
        glVertex3f(0.500000, 0.500000, -0.500000);
        glVertex3f(0.500000, 0.500000, 0.500000);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.f, 0.f, 1.f);
        glVertex3f(-0.500000, -0.500000,-0.500000);
        glVertex3f(-0.500000, -0.500000, 0.500000);
        glVertex3f(-0.500000, 0.500000, 0.500000);
        glVertex3f(-0.500000, 0.500000, -0.500000);
        glEnd();

        static float alpha = 0;
        //attempt to rotate cube
        glRotatef(alpha, 1, 1, 0);
        alpha += 0.01;

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}