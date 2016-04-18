#include "GLFW/glfw3.h"
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

double rotate_y_atas=0; 
double rotate_y_bawah=0; 
double rotate_x_kanan=0;
double rotate_x_kiri=0;


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else //  Right arrow - increase rotation by 5 degree
        if (key == GLFW_KEY_RIGHT)
            rotate_x_kanan += 45;
        
        else if (key == GLFW_KEY_LEFT)
            rotate_x_kiri += 45;

        else if (key == GLFW_KEY_UP)
            rotate_y_atas += 45;

        else if (key == GLFW_KEY_DOWN)
            rotate_y_bawah += 45;
 

}

int main(void)
{
    GLFWwindow* window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(1280, 640, "Triangle", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    glfwSetKeyCallback(window, key_callback);

    glEnable(GL_DEPTH_TEST);

    while (!glfwWindowShouldClose(window))
    {
        float ratio;
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        ratio = width / (float) height;
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        
        // Rotate when user changes rotate_x and rotate_y
        
        //Red side - FRONT
        glPushMatrix();
        for(int i=-1;i<=1;i++) {
            for(int j=-1;j<=1;j++) {
                if(i>0) glRotatef( rotate_x_kanan, 1.0, 0.0, 0.0 );
                else if(i<0)  glRotatef( rotate_x_kiri, 1.0, 0.0, 0.0 );
                
                if(j>0) glRotatef( rotate_y_atas, 0.0, 1.0, 0.0 );
                else if(j<0) glRotatef( rotate_y_bawah, 0.0, 1.0, 0.0 );

                glBegin(GL_QUADS);
                
                glColor3f( 1.0, 0.0, 0.0 );     
                glVertex3f(  (i*0.8)+0.3, (j*0.8)-0.3, -1.0 );
                glColor3f( 1.0, 1.0, 0.0 );  
                glVertex3f(  (i*0.8)+0.3, (j*0.8)+0.3, -1.0 );
                glColor3f( 0.0, 1.0, 0.0 );  
                glVertex3f( (i*0.8)-0.3,  (j*0.8)+0.3, -1.0 );
                glColor3f( 0.0, 0.0, 1.0 );  
                glVertex3f( (i*0.8)-0.3, (j*0.8)-0.3, -1.0 );

                glEnd();
            }
        }
        glPopMatrix();
/*
        glEnd();
        glPopMatrix();


        glPushMatrix();
        // Rotate when user changes rotate_x and rotate_y
        glRotatef( rotate_x, 1.0, 0.0, 0.0 );
        glRotatef( rotate_y, 0.0, 1.0, 0.0 );

        // White side - BACK
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  1.0, 1.0 );
        glVertex3f(  0.5, -0.5, 0.5 );
        glVertex3f(  0.5,  0.5, 0.5 );
        glVertex3f( -0.5,  0.5, 0.5 );
        glVertex3f( -0.5, -0.5, 0.5 );
        glEnd();
        glPopMatrix();

        // Purple side - RIGHT
        glBegin(GL_POLYGON);
        glColor3f(  1.0,  0.0,  1.0 );
        glVertex3f( 0.5, -0.5, -0.5 );
        glVertex3f( 0.5,  0.5, -0.5 );
        glVertex3f( 0.5,  0.5,  0.5 );
        glVertex3f( 0.5, -0.5,  0.5 );
        glEnd();

        // Green side - LEFT
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  1.0,  0.0 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

        // Blue side - TOP
        glBegin(GL_POLYGON);
        glColor3f(   0.0,  0.0,  1.0 );
        glVertex3f(  0.5,  0.5,  0.5 );
        glVertex3f(  0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5, -0.5 );
        glVertex3f( -0.5,  0.5,  0.5 );
        glEnd();

        // Red side - BOTTOM
        glBegin(GL_POLYGON);
        glColor3f(   1.0,  0.0,  0.0 );
        glVertex3f(  0.5, -0.5, -0.5 );
        glVertex3f(  0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5,  0.5 );
        glVertex3f( -0.5, -0.5, -0.5 );
        glEnd();

 */
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}