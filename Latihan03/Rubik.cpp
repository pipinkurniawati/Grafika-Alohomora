#include <GL/glut.h>	// Header File For The GLUT Library
#include <GL/gl.h>		// Header File For The OpenGL32 Library
#include <GL/glu.h>		// Header File For The GLu32 Library
#include <unistd.h>		// Header File For sleeping

/* ASCII code for the escape key. */
#define ESCAPE 27

/* The number of our GLUT window */
int window;

/* rotation angle for the triangle. */
float rtri = 0.0f;

/* rotation angle for the quadrilateral. */
float rquad = 0.0f;

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int width, int height);

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ResizeGLScene(int width, int height);

/* The main drawing function. */
void DrawGLScene();

/* The function called whenever a key is pressed. */
void keyPressed(unsigned char key, int x, int y);

/* Main program */
int main(int argc, char **argv) {
	// Initialise GLUT state
	glutInit(&argc, argv);

	// Select type of display mode
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);

	// Get a 640 x 480 window
	glutInitWindowSize(640, 480);

	// Top left the window position
	glutInitWindowPosition(0, 0);

	// Open a window
	window = glutCreateWindow("Rubik's Cube");

	// Register the function to do all OpenGL drawing
	glutDisplayFunc(&DrawGLScene);

	// If there are no events, redraw GLScene
	glutIdleFunc(&DrawGLScene);

	// Register the function called when window is resized
	glutReshapeFunc(&ResizeGLScene);

	// Register the function called when keypressed
	glutKeyboardFunc(&keyPressed);

	// Initialise window
	InitGL(640, 480);

	// Start event processing engine
	glutMainLoop();
	
	return 0;
}

/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
  glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
  glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
  glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
  glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();				// Reset The Projection Matrix

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

  glMatrixMode(GL_MODELVIEW);
}

/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
  if (Height==0)				// Prevent A Divide By Zero If The Window Is Too Small
    Height=1;

  glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

/* The main drawing function. */
void DrawGLScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear the screen and the depth buffer

	// Row 1 Front
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.9f, 0.1f);
	glVertex3f(0.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.1f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.9f, 0.1f);
	glVertex3f(1.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.1f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.9f, 0.1f);
	glVertex3f(2.1f, 0.9f, 0.1f);
	glEnd();

	// Row 2 Front
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.9f, 0.1f);
	glVertex3f(0.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.1f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.9f, 0.1f);
	glVertex3f(1.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.1f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.9f, 0.1f);
	glVertex3f(2.1f, 1.9f, 0.1f);
	glEnd();

	// Row 3 Front
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.1f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.9f, 0.1f);
	glVertex3f(0.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.1f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.9f, 0.1f);
	glVertex3f(1.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -10.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(2.1f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.9f, 0.1f);
	glVertex3f(2.1f, 2.9f, 0.1f);
	glEnd();

	// Row 1 Back
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.9f, 0.1f);
	glVertex3f(0.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.1f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.9f, 0.1f);
	glVertex3f(1.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.1f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.9f, 0.1f);
	glVertex3f(2.1f, 0.9f, 0.1f);
	glEnd();

	// Row 2 Back
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.9f, 0.1f);
	glVertex3f(0.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.1f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.9f, 0.1f);
	glVertex3f(1.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.1f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.9f, 0.1f);
	glVertex3f(2.1f, 1.9f, 0.1f);
	glEnd();

	// Row 3 Back
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.1f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.9f, 0.1f);
	glVertex3f(0.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(1.1f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.9f, 0.1f);
	glVertex3f(1.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.1f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.9f, 0.1f);
	glVertex3f(2.1f, 2.9f, 0.1f);
	glEnd();

	// Row 1 Bottom
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.1f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.1f, 0.1f);
	glVertex3f(0.9f, 0.9f, 0.1f);
	glVertex3f(0.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.1f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.1f, 0.1f);
	glVertex3f(1.9f, 0.9f, 0.1f);
	glVertex3f(1.1f, 0.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(2.1f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.1f, 0.1f);
	glVertex3f(2.9f, 0.9f, 0.1f);
	glVertex3f(2.1f, 0.9f, 0.1f);
	glEnd();

	// Row 2 Bottom
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.1f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.1f, 0.1f);
	glVertex3f(0.9f, 1.9f, 0.1f);
	glVertex3f(0.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.1f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.1f, 0.1f);
	glVertex3f(1.9f, 1.9f, 0.1f);
	glVertex3f(1.1f, 1.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(2.1f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.1f, 0.1f);
	glVertex3f(2.9f, 1.9f, 0.1f);
	glVertex3f(2.1f, 1.9f, 0.1f);
	glEnd();

	// Row 3 Bottom
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(0.1f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.1f, 0.1f);
	glVertex3f(0.9f, 2.9f, 0.1f);
	glVertex3f(0.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.1f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.1f, 0.1f);
	glVertex3f(1.9f, 2.9f, 0.1f);
	glVertex3f(1.1f, 2.9f, 0.1f);
	glEnd();

	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -13.0f);
	glRotatef(90.0f, 1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 1.0f);
	glVertex3f(2.1f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.1f, 0.1f);
	glVertex3f(2.9f, 2.9f, 0.1f);
	glVertex3f(2.1f, 2.9f, 0.1f);
	glEnd();

	glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
	usleep(100);

	if (key == ESCAPE) {
		glutDestroyWindow(window);
		exit(0);
	}
}
