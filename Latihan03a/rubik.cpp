#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <cstdio>

double rotate_y_atas=0; 
double rotate_y_bawah=0; 
double rotate_x_kanan=0;
double rotate_x_kiri=0;
double rotate_z_depan=0;
double rotate_z_belakang=0;

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        else //  Right arrow - increase rotation by 5 degree
	        if (key == GLFW_KEY_D) 
            	rotate_x_kanan += 45;
	        else if (key == GLFW_KEY_A)
	            rotate_x_kiri += 45;
	        else if (key == GLFW_KEY_W)
	            rotate_y_atas += 45;
	        else if (key == GLFW_KEY_X)
	            rotate_y_bawah += 45;
	        else if (key == GLFW_KEY_C)
	            rotate_z_depan += 45;
	        else if (key == GLFW_KEY_Z)
	            rotate_z_belakang += 45;
	}

GLFWwindow* initWindow(const int resX, const int resY)
{
    if(!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return NULL;
    }
    glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing

    // Open a window and create its OpenGL context
    GLFWwindow* window = glfwCreateWindow(resX, resY, "Solid Color Cube", NULL, NULL);

    if(window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window.\n");
        glfwTerminate();
        return NULL;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, controls);

    // Get info of GPU and supported OpenGL version
    printf("Renderer: %s\n", glGetString(GL_RENDERER));
    printf("OpenGL version supported %s\n", glGetString(GL_VERSION));

    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    return window;
}

GLfloat* drawCube(float x, float y, float z, float a)
{
    GLfloat vertices[] =
    {
        -0.3+x, -0.3+y, -0.3+z,   -0.3+x, -0.3+y,  0.3+z,   -0.3+x,  0.3+y,  0.3+z,   -0.3+x,  0.3+y, -0.3+z,
        0.3+x, -0.3+y, -0.3+z,    0.3+x, -0.3+y,  0.3+z,    0.3+x,  0.3+y,  0.3+z,    0.3+x,  0.3+y, -0.3+z,
        -0.3+x, -0.3+y, -0.3+z,   -0.3+x, -0.3+y,  0.3+z,    0.3+x, -0.3+y,  0.3+z,    0.3+x, -0.3+y, -0.3+z,
        -0.3+x,  0.3+y, -0.3+z,   -0.3+x,  0.3+y,  0.3+z,    0.3+x,  0.3+y,  0.3+z,    0.3+x,  0.3+y, -0.3+z,
        -0.3+x, -0.3+y, -0.3+z,   -0.3+x,  0.3+y, -0.3+z,    0.3+x,  0.3+y, -0.3+z,    0.3+x, -0.3+y, -0.3+z,
        -0.3+x, -0.3+y,  0.3+z,   -0.3+x,  0.3+y,  0.3+z,    0.3+x,  0.3+y,  0.3+z,    0.3+x, -0.3+y,  0.3+z 
    };

    GLfloat colors[] =
    {
        0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,
        1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,
        0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,
        1, 1, 0,   1, 1, 0,   1, 1, 0,   1, 1, 0,
        0, 1, 1,   0, 1, 1,   0, 1, 1,   0, 1, 1,
        1, 0, 1,   1, 0, 1,   1, 0, 1,   1, 0, 1
    };

    glPushMatrix();

    //attempt to rotate cube
    if(x>0) glRotatef( rotate_x_kanan, 1.0, 0.0, 0.0 );
    else if(x<0)  glRotatef( rotate_x_kiri, 1.0, 0.0, 0.0 );
    
    if(y>0) glRotatef( rotate_y_atas, 0.0, 1.0, 0.0 );
    else if(y<0) glRotatef( rotate_y_bawah, 0.0, 1.0, 0.0 );

    if(z>0) glRotatef( rotate_z_depan, 0.0, 0.0, 1.0 );
    else if(z<0) glRotatef( rotate_z_belakang, 0.0, 0.0, 1.0 );

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);
    glPopMatrix();

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    return vertices;
}

void display( GLFWwindow* window )
{
    while(!glfwWindowShouldClose(window))
    {
        // Scale to window size
        GLint windowWidth, windowHeight;
        glfwGetWindowSize(window, &windowWidth, &windowHeight);
        glViewport(0, 0, windowWidth, windowHeight);

        // Draw stuff
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
        gluPerspective( 60, (double)windowWidth / (double)windowHeight, 0.1, 100 );

        glMatrixMode(GL_MODELVIEW_MATRIX);
        glTranslatef(0,0,-5);

        GLfloat* cubes[3][3][3];

        for (int i=-1; i<2; i++){
        	for (int j=-1; j<2; j++){
        		for (int k=-1; k<2; k++){
        			cubes[i+1][j+1][k+1] = drawCube((float)i*0.7f, (float)j*0.7f, (float)k*0.7f, 0);
        		}
        	}
        }


        // Update Screen
        glfwSwapBuffers(window);

        // Check for any input, or window movement
        glfwPollEvents();
    }
}

int main(int argc, char** argv)
{
    GLFWwindow* window = initWindow(1024, 620);
    if( NULL != window )
    {
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}