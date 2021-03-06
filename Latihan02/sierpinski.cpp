#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <iostream>
using namespace std;

<<<<<<< HEAD
=======
int depth = 6; 

>>>>>>> ca689ebbf6e76613816dc9a04dbef17c50efeb26
static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

<<<<<<< HEAD
int depth = 6;
//The recursive function that'll draw all the upside down triangles
void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)
{
  //Draw the 3 sides as black lines
    glBegin(GL_TRIANGLES);
    glColor3f(r, g, b);
    glVertex3f(x1, y1, 0.f);
    glColor3f(r, g, b);
    glVertex3f(x2, y2, 0.f);

    glVertex3f(x3, y3, 0.f);
    glEnd();

  if (n == depth-1){
=======
//The recursive function that'll draw all the upside down triangles
void subTriangle(int n, float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)
{
  if (n == depth){
>>>>>>> ca689ebbf6e76613816dc9a04dbef17c50efeb26
    r=1, g=0, b=0;
  } else if (n == depth-1){
    r=0, g=1, b=0;
  } else if (n == depth-2){
    r=0, g=0, b=1;
  } else if (n == depth-3){
    r=1, g=1, b=0;
  } else if (n == depth-4){
    r=0, g=1, b=1;
  } else {
    r=1, g=0, b=1;
  }

  //Draw the 3 sides as black lines
  glBegin(GL_TRIANGLES);
  glColor3f(r, g, b);
  glVertex3f(x1, y1, 0.f);
  glColor3f(r, g, b);
  glVertex3f(x2, y2, 0.f);
  glColor3f(r, g, b);
  glVertex3f(x3, y3, 0.f);
  glEnd();

  /*cout << "n: " << n << endl;
  cout << "x1: " << x1 << " y1: " << y1 << endl;
  cout << "x2: " << x2 << " y2: " << y2 << endl;
  cout << "x3: " << x3 << " y3: " << y3 << endl;
  cout << "r: " << r << " g: " << g << " b: " << b << endl << endl;*/
  
  //Calls itself 3 times with new corners, but only if the current number of recursions is smaller than the maximum depth
  if(n < (depth))
  {
    //Smaller triangle 1
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

int main(int argc, char** argv)
{
    if (argc < 2){
      exit(0);
    } else {
      depth = atoi(argv[1]);
      
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

          glBegin(GL_TRIANGLES);
          glColor3f(1.f, 1.f, 1.f);
          glVertex3f(-0.8f, -0.6f, 0.f);
          glColor3f(1.f, 1.f, 1.f);
          glVertex3f(0.8f, -0.6f, 0.f);
          glColor3f(1.f, 1.f, 1.f);
          glVertex3f(0.f, 0.8f, 0.f);
          glEnd();

          float r = 1;
          float g = 1;
          float b = 1;

          subTriangle(1, -0.4f, 0.1f, 0.4f, 0.1f, 0.0f, -0.6f, r, g, b);

          glfwSwapBuffers(window);
          glfwPollEvents();
      }
      glfwDestroyWindow(window);
      glfwTerminate();
      exit(EXIT_SUCCESS);
    }
}