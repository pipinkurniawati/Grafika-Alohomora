#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <cstdio>
#include <iostream>
using namespace std;

double rotate_y_atas=0; 
double rotate_y_bawah=0; 
double rotate_x_kanan=0;
double rotate_x_kiri=0;
double rotate_z_depan=0;
double rotate_z_belakang=0;

typedef struct {
    float x;
    float y;
    float z;
    float o;
    GLfloat vertices[72];
    GLfloat colors[72] = 
    {
        0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,
        1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,
        0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,
        1, 1, 0,   1, 1, 0,   1, 1, 0,   1, 1, 0,
        0, 1, 1,   0, 1, 1,   0, 1, 1,   0, 1, 1,
        1, 0, 1,   1, 0, 1,   1, 0, 1,   1, 0, 1
    };
} Cube;

Cube cubes[3][3][3] = {};

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        else //  Right arrow - increase rotation by 5 degree
	        if (key == GLFW_KEY_D) {
            	rotate_x_kanan += 90;
                for (int i=0; i<3; i++){
                    for (int j=0; j<3; j++){
                        for (int k=0; k<3; k++){
                            if (cubes[i][j][k].y==0){
                                if (cubes[i][j][k].z<0){
                                    cubes[i][j][k].y-=0.7;
                                    cubes[i][j][k].z=0;
                                } else {
                                    cubes[i][j][k].y+=0.7;
                                    cubes[i][j][k].z=0;
                                }
                            } else if (cubes[i][j][k].z==0){
                                if (cubes[i][j][k].y<0){
                                    cubes[i][j][k].z-=0.7;
                                    cubes[i][j][k].y=0;
                                } else {
                                    cubes[i][j][k].z+=0.7;
                                    cubes[i][j][k].y=0;
                                }
                            } else {
                                if (cubes[i][j][k].z>0 && cubes[i][j][k].y>0){
                                    cubes[i][j][k].y-=1.4;
                                } else if (cubes[i][j][k].z>0 && cubes[i][j][k].y<0){
                                    cubes[i][j][k].z-=1.4;
                                } else if (cubes[i][j][k].z<0 && cubes[i][j][k].y<0){
                                    cubes[i][j][k].y+=1.4;
                                } else {
                                    cubes[i][j][k].z+=1.4;
                                }
                            }
                        }
                    }
                }
	        } else if (key == GLFW_KEY_A) {
	            rotate_x_kiri += 90;
	        } else if (key == GLFW_KEY_W) {
	            rotate_y_atas += 90;
	        } else if (key == GLFW_KEY_X) {
	            rotate_y_bawah += 90;
	        } else if (key == GLFW_KEY_C) {
	            rotate_z_depan += 90;
	        } else if (key == GLFW_KEY_Z) {
	            rotate_z_belakang += 90;
            }
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


Cube initCube(float x, float y, float z, float o)
{
    Cube c;
    c.o = o;
    c.x = x;
    c.y = y;
    c.z = z;

    c.vertices[0]= -o+x; c.vertices[1]= -o+y; c.vertices[2]= -o+z;
    c.vertices[3]=   -o+x; c.vertices[4]= -o+y; c.vertices[5]=  o+z;
    c.vertices[6]=   -o+x; c.vertices[7]=  o+y; c.vertices[8]=  o+z;
    c.vertices[9]=   -o+x; c.vertices[10]=  o+y; c.vertices[11]= -o+z;

    c.vertices[12]= o+x; c.vertices[13]= -o+y; c.vertices[14]= -o+z;
    c.vertices[15]=    o+x;c.vertices[16]= -o+y; c.vertices[17]=  o+z;
    c.vertices[18]=    o+x; c.vertices[19]=  o+y; c.vertices[20]=  o+z;
    c.vertices[21]=    o+x; c.vertices[22]=  o+y; c.vertices[23]= -o+z;

    c.vertices[24]= -o+x; c.vertices[25]= -o+y; c.vertices[26]= -o+z;
    c.vertices[27]=   -o+x; c.vertices[28]= -o+y; c.vertices[29]=  o+z;
    c.vertices[30]=    o+x; c.vertices[31]= -o+y; c.vertices[32]=  o+z;
    c.vertices[33]=    o+x; c.vertices[34]= -o+y; c.vertices[35]= -o+z;

    c.vertices[36]= -o+x; c.vertices[37]=  o+y; c.vertices[38]= -o+z;
    c.vertices[39]=   -o+x; c.vertices[40]=  o+y; c.vertices[41]=  o+z; 
    c.vertices[42]=    o+x; c.vertices[43]=  o+y; c.vertices[44]=  o+z; 
    c.vertices[45]=    o+x; c.vertices[46]=  o+y; c.vertices[47]= -o+z;

    c.vertices[48]= -o+x; c.vertices[49]= -o+y; c.vertices[50]= -o+z; 
    c.vertices[51]=   -o+x; c.vertices[52]=  o+y; c.vertices[53]= -o+z; 
    c.vertices[54]=    o+x; c.vertices[55]=  o+y; c.vertices[56]= -o+z; 
    c.vertices[57]=    o+x; c.vertices[58]= -o+y; c.vertices[59]= -o+z;

    c.vertices[60]= -o+x; c.vertices[61]= -o+y; c.vertices[62]=  o+z;
    c.vertices[63]=   -o+x; c.vertices[64]=  o+y; c.vertices[65]=  o+z;
    c.vertices[66]=    o+x; c.vertices[67]=  o+y; c.vertices[68]=  o+z;
    c.vertices[69]=    o+x; c.vertices[70]= -o+y; c.vertices[71]=  o+z;

    return c;
}

void drawCube(Cube c)
{
    glPushMatrix();

    //attempt to rotate cube
    if(c.x>0) glRotatef( rotate_x_kanan, 1.0, 0.0, 0.0 );
    else if(c.x<0)  glRotatef( rotate_x_kiri, 1.0, 0.0, 0.0 );
    
    if(c.y>0) glRotatef( rotate_y_atas, 0.0, 1.0, 0.0 );
    else if(c.y<0) glRotatef( rotate_y_bawah, 0.0, 1.0, 0.0 );

    if(c.z>0) glRotatef( rotate_z_depan, 0.0, 0.0, 1.0 );
    else if(c.z<0) glRotatef( rotate_z_belakang, 0.0, 0.0, 1.0 );

    /* We have a color array and a vertex array */
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, c.vertices);
    glColorPointer(3, GL_FLOAT, 0, c.colors);

    /* Send data : 24 vertices */
    glDrawArrays(GL_QUADS, 0, 24);

    /* Cleanup states */
    glDisableClientState(GL_COLOR_ARRAY);
    glDisableClientState(GL_VERTEX_ARRAY);

    glPopMatrix();

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

        for (int i=0; i<3; i++){
            for (int j=0; j<3; j++){
                for (int k=0; k<3; k++){
                    drawCube(cubes[i][j][k]);
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
    
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            for (int k=0; k<3; k++){
                cubes[i][j][k] = initCube((float)((i-1)*0.7f), (float)((j-1)*0.7f), (float)((k-1)*0.7f), 0.3);
            }
        }
    }

    if( NULL != window )
    {
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}