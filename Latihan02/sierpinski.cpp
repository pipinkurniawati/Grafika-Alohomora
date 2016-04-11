#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int depth = 4; 

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int depth = 3;
//The recursive function that'll draw all the upside down triangles
void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)
{
  //Draw the 3 sides as black lines
    glBegin(GL_TRIANGLES);
    glVertex3f(x1, y1, 0.f);
    glVertex3f(x2, y2, 0.f);
    glVertex3f(x3, y3, 0.f);
    glColor3f(r, g, b);
    glEnd();

  //Calls itself 3 times with new corners, but only if the current number of recursions is smaller than the maximum depth
  if(n < depth)
  {
    //Smaller triangle 1
    r = 1;
    g = 0;
    b = 0;
    subTriangle
    (
      n+1, //Number of recursions for the next call increased with 1
      (x1 + x2) / 2 + (x2 - x3) / 2, //x coordinate of first corner
      (y1 + y2) / 2 + (y2 - y3) / 2, //y coordinate of first corner
      (x1 + x2) / 2 + (x1 - x3) / 2, //x coordinate of second corner
      (y1 + y2) / 2 + (y1 - y3) / 2, //y coordinate of second corner
      (x1 + x2) / 2, //x coordinate of third corner
      (y1 + y2) / 2,  //y coordinate of third corner
      r,g,b
    );
    
    //Smaller triangle 2
    r = 0;
    g = 1;
    b = 0;
    subTriangle
    (
      n+1, //Number of recursions for the next call increased with 1
      (x3 + x2) / 2 + (x2 - x1) / 2, //x coordinate of first corner
      (y3 + y2) / 2 + (y2 - y1) / 2, //y coordinate of first corner
      (x3 + x2) / 2 + (x3 - x1) / 2, //x coordinate of second corner
      (y3 + y2) / 2 + (y3 - y1) / 2, //y coordinate of second corner
      (x3 + x2) / 2, //x coordinate of third corner
      (y3 + y2) / 2, //y coordinate of third corner
      r,g,b
    );
    
    //Smaller triangle 3
    r = 0;
    g = 0;
    b = 1;
    subTriangle
    (
      n+1, //Number of recursions for the next call increased with 1
      (x1 + x3) / 2 + (x3 - x2) / 2, //x coordinate of first corner
      (y1 + y3) / 2 + (y3 - y2) / 2, //y coordinate of first corner
      (x1 + x3) / 2 + (x1 - x2) / 2, //x coordinate of second corner
      (y1 + y3) / 2 + (y1 - y2) / 2, //y coordinate of second corner
      (x1 + x3) / 2, //x coordinate of third corner
      (y1 + y3) / 2,  //y coordinate of third corner
      r,g,b
    );
  }
}

int main(void)
{
    
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(640, 480, "Triangle", NULL, NULL);
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

<<<<<<< HEAD
        subTriangle(1, -1.0, -0.58, 1.0, -0.58, 0.0, 1.15);
=======
        float r = 1;
        float g = 1;
        float b = 1;

        subTriangle(1, -0.4f, 0.1f, 0.4f, 0.1f, 0.0f, -0.6f, r, g, b);
>>>>>>> 88ba09c3a01083ba688209abb9e44c82a0641986

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}