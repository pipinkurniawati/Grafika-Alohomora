#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <cstdio>

double rotate_y_atas=0; 
double rotate_y_bawah=0; 
double rotate_x_kanan=0;
double rotate_x_kiri=0;
double rotate_z_depan=0;
double rotate_z_belakang=0;

// Data read from the header of the BMP file
unsigned char header[54]; // Each BMP file begins by a 54-bytes header
unsigned int dataPos;     // Position in the file where the actual data begins
unsigned int width, height;
unsigned int imageSize;   // = width*height*3
// Actual RGB data
unsigned char * data;

GLuint image = loadBMP_custom("./my_texture.bmp");

double rotate_x = 0;
double rotate_y = 0;
double rotate_z = 0;

typedef struct {
    int position_x;
    int position_y;
    int position_z;

    float x, y, z; // menentukan vektor rotasi
} sc;

sc matrix_cube[3][3][3];

void init() {
    for(int i=-1;i<=1;i++) {
        for(int j=-1;j<=1;j++) {
            for(int k=-1;k<=1;k++) {
                matrix_cube[i][j][k].position_x = i;
                matrix_cube[i][j][k].position_y = j;
                matrix_cube[i][j][k].position_z = k;
            }
        }
    }
}

void controls(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS)
        if(key == GLFW_KEY_ESCAPE)
            glfwSetWindowShouldClose(window, GL_TRUE);
        else //  Right arrow - increase rotation by 5 degree
	        /*
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
            */
            if (key == GLFW_KEY_D) {
                for(int i=-1;i<=1;i++) {
                    for(int j=-1;j<=1;j++) {
                        for(int k=-1;k<=1;k++) {
                            if(matrix_cube[i][j][k].position_x > 0) {
                                if(matrix_cube[i][j][k].position_y == -1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_y = 1;
                                }
                                else if(matrix_cube[i][j][k].position_y == 1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_z = -1;
                                }
                                else if(matrix_cube[i][j][k].position_y == 1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_y = -1;
                                }
                                else if(matrix_cube[i][j][k].position_y == -1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_z = 1;
                                }
                            }
                        }
                    }
                }
            }
            else if (key == GLFW_KEY_A) {
            	for(int i=-1;i<=1;i++) {
                    for(int j=-1;j<=1;j++) {
                        for(int k=-1;k<=1;k++) {
                            if(matrix_cube[i][j][k].position_x < 0) {
                                if(matrix_cube[i][j][k].position_y == -1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_y = 1;
                                }
                                else if(matrix_cube[i][j][k].position_y == 1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_z = -1;
                                }
                                else if(matrix_cube[i][j][k].position_y == 1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_y = -1;
                                }
                                else if(matrix_cube[i][j][k].position_y == -1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_z = 1;
                                }
                            }
                        }
                    }
                }	
            }
                
            else if (key == GLFW_KEY_W) {
            	for(int i=-1;i<=1;i++) {
                    for(int j=-1;j<=1;j++) {
                        for(int k=-1;k<=1;k++) {
                            if(matrix_cube[i][j][k].position_y > 0) {
                                if(matrix_cube[i][j][k].position_x== -1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_x = 1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_z = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_x = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == -1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_z = 1;
                                }
                            }
                        }
                    }
                }
            }

                
            else if (key == GLFW_KEY_X) {
            	for(int i=-1;i<=1;i++) {
                    for(int j=-1;j<=1;j++) {
                        for(int k=-1;k<=1;k++) {
                            if(matrix_cube[i][j][k].position_y < 0) {
                                if(matrix_cube[i][j][k].position_x== -1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_x = 1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_z == 1) {
                                    matrix_cube[i][j][k].position_z = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_x = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == -1 && matrix_cube[i][j][k].position_z == -1) {
                                    matrix_cube[i][j][k].position_z = 1;
                                }
                            }
                        }
                    }
                }
            }
                
            else if (key == GLFW_KEY_C) {
            	for(int i=-1;i<=1;i++) {
                    for(int j=-1;j<=1;j++) {
                        for(int k=-1;k<=1;k++) {
                            if(matrix_cube[i][j][k].position_z > 0) {
                                if(matrix_cube[i][j][k].position_x== -1 && matrix_cube[i][j][k].position_y == 1) {
                                    matrix_cube[i][j][k].position_x = 1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_y == 1) {
                                    matrix_cube[i][j][k].position_y = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_y == -1) {
                                    matrix_cube[i][j][k].position_x = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == -1 && matrix_cube[i][j][k].position_y == -1) {
                                    matrix_cube[i][j][k].position_y = 1;
                                }
                            }
                        }
                    }
                }
            }
                
            else if (key == GLFW_KEY_Z) {
            	for(int i=-1;i<=1;i++) {
                    for(int j=-1;j<=1;j++) {
                        for(int k=-1;k<=1;k++) {
                            if(matrix_cube[i][j][k].position_z < 0) {
                                if(matrix_cube[i][j][k].position_x== -1 && matrix_cube[i][j][k].position_y == 1) {
                                    matrix_cube[i][j][k].position_x = 1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_y == 1) {
                                    matrix_cube[i][j][k].position_y = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == 1 && matrix_cube[i][j][k].position_y == -1) {
                                    matrix_cube[i][j][k].position_x = -1;
                                }
                                else if(matrix_cube[i][j][k].position_x == -1 && matrix_cube[i][j][k].position_y == -1) {
                                    matrix_cube[i][j][k].position_y = 1;
                                }
                            }
                        }
                    }
                }
            
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
/*
    //attempt to rotate cube
    if(x>0) glRotatef( rotate_x_kanan, 1.0, 0.0, 0.0 );
    else if(x<0) glRotatef( rotate_x_kiri, 1.0, 0.0, 0.0 );

    if(y>0) glRotatef( rotate_y_atas, 0.0, 1.0, 0.0 );
    else if(y<0) glRotatef( rotate_y_bawah, 0.0, 1.0, 0.0 );

    if(z>0) glRotatef( rotate_z_depan, 0.0, 0.0, 1.0 );
    else if(z<0) glRotatef( rotate_z_belakang, 0.0, 0.0, 1.0 );
*/
    /*glRotatef(rotate_x, matrix_cube[x][y][z].position_x, 0.0, 0.0 );
    glRotatef(rotate_y, 0.0, matrix_cube[x][y][z].position_y, 0.0 );
    glRotatef(rotate_z, 0.0, 0.0, matrix_cube[x][y][z].position_z );*/
    int x1 = x/0.7;
    int y1 = y/0.7;
    int z1 = z/0.7;

    glRotatef(rotate_x, matrix_cube[x1][y1][z1].position_x, 0.0, 0.0 );
    glRotatef(rotate_y, 0.0, matrix_cube[x1][y1][z1].position_y, 0.0 );
    glRotatef(rotate_z, 0.0, 0.0, matrix_cube[x1][y1][z1].position_z );

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
    init();
    GLFWwindow* window = initWindow(1024, 620);
    if( NULL != window )
    {
        display( window );
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}