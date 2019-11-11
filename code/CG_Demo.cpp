//
// A01653455 - Josué Giovani García Hernández
// A01652520 - Santiago Gutiérrez Bárcenas
// A01336424 - Kai Kawasaki Ueda
// A01336435 - Sergio Ugalde Marcano
//
// TC3022 - Computer Graphics
// Second Advance	
//
// Please don't change lines 9-31 (It helps me to grade)
#ifdef __APPLE__
// For XCode only: New C++ terminal project. Build phases->Compile with libraries: add OpenGL and GLUT
// Import this whole code into a new C++ file (main.cpp, for example). Then run.
// Reference: https://en.wikibooks.org/wiki/OpenGL_Programming/Installation/Mac
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#endif
#ifdef _WIN32
// For VS on Windows only: Download CG_Demo.zip. UNZIP FIRST. Double click on CG_Demo/CG_Demo.sln
// Run
#include "freeglut.h"
#endif
#ifdef __unix__
// For Linux users only: g++ CG_Demo.cpp -lglut -lGL -o CG_Demo
// ./CG_Demo
// Reference: https://www.linuxjournal.com/content/introduction-opengl-programming
#include "GL/freeglut.h"
#include "GL/gl.h"

#endif

#include <cmath>
#include <iostream>
#include <random>
#include <vector>
#include <tuple>

#include "Robot.hpp"


using namespace std;
const double PI = 3.141592653589793238463;
bool genColors = false;
bool wireframe = false;
vector<tuple<float, float, float>> colors;
// right_leg, left_leg, body_1, body_2
vector<float> angles;
vector<float> speeds;
vector<float> speeda;

std::random_device rd;
std::mt19937 gen(rd());
std::uniform_real_distribution<> dis(0, 1);
bool flag = false;
Robot* robot;

long		frames;
long		times;
long		timebase;
float		fps;
GLfloat* global_ambient;

char		bufferFPS[11];	// For on-screen text.

// Display text:
void displayText(int x, int y, char* txt);

void init() // FOR GLUT LOOP
{
	frames = 0;
	times = 0;
	timebase = 0;
	fps = 0.0f;
	robot = new Robot();

	glEnable(GL_DEPTH_TEST);            // Enable check for close and far objects.
	glEnable(GL_TEXTURE_2D);
	glClearColor(0.0, 0.0, 0.0, 0.0);    // Clear the color state.
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat diffusel0[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
	GLfloat ambientl0[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
	GLfloat specularl0[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
	GLfloat position[4] = { 2.0f, 0.5f, 1.0f, 0.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientl0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffusel0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specularl0);
	glLightfv(GL_LIGHT0, GL_POSITION, position);

	global_ambient = new GLfloat[4];
	global_ambient[0] = 0.3f;
	global_ambient[1] = 0.3f;
	global_ambient[2] = 0.3f;
	global_ambient[3] = 1.0f;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

	//glMatrixMode(GL_MODELVIEW);            // Go to 3D mode.
	//glLoadIdentity();                    // Reset 3D view matrix.
	srand(666);

}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);                // Clear color and depth buffers.
	glLoadIdentity();                                                // Reset 3D view matrix.
//    gluLookAt(10, 10, 10,                                        // Where the camera is.
	gluLookAt(-10, 10, 10,                                        // Where the camera is.
		0.0, 0.0, 0.0,                                        // To where the camera points at.
		.0, 1.0, 0.0);                                        // "UP" vector.
	robot->draw();

	displayText(5, 20, bufferFPS);

	glutSwapBuffers();                                                // Swap the hidden and visible buffers.
}

void idle()                                                            // Called when drawing is finished.
{
	// Compute frames per second:
	frames++;
	times = glutGet(GLUT_ELAPSED_TIME);
	if (times - timebase > 1000)
	{
		fps = frames * 1000.0f / (times - timebase);
		sprintf(bufferFPS, "FPS:%4.2f\n", fps);
		timebase = times;
		frames = 0;
	}

	robot->update();
	glutPostRedisplay();                                            // Display again.
}


void reshape(int x, int y)                                            // Called when the window geometry changes.
{
	glMatrixMode(GL_PROJECTION);                                    // Go to 2D mode.
	glLoadIdentity();                                                // Reset the 2D matrix.
	gluPerspective(40.0, (GLdouble)x / (GLdouble)y, 0.5, 50.0);        // Configure the camera lens aperture.
	glMatrixMode(GL_MODELVIEW);                                        // Go to 3D mode.
	glViewport(0, 0, x, y);                                            // Configure the camera frame dimensions.
	gluLookAt(0, 0, 15,                                        // Where the camera is.
		0.0, 0.0, 0.0,                                        // To where the camera points at.
		.0, 1.0, 0.0);                                        // "UP" vector.
	display();
}

int main(int argc, char* argv[]) {
	glutInit(&argc, argv);                                            // Init GLUT with command line parameters.
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH |
		GLUT_RGB);        // Use 2 buffers (hidden and visible). Use the depth buffer. Use 3 color channels.
	glutInitWindowSize(800, 800);
	glutCreateWindow("Roboto");

	init();
	glutReshapeFunc(reshape);                                        // Reshape CALLBACK function.
	glutDisplayFunc(display);                                        // Display CALLBACK function.
	glutIdleFunc(idle);                                                // Idle CALLBACK function.
	glutMainLoop();                                                    // Begin graphics program.
	return 0;                                                        // ANSI C requires a return value.
}

/*
Displays characters stored in the "txt" array at position(x, y).
*/
void displayText(int x, int y, char* txt)
{
	GLboolean lighting;
	GLint viewportCoords[4];
	glColor3f(0.0, 1.0, 0.0);
	glGetBooleanv(GL_LIGHTING, &lighting);
	glGetIntegerv(GL_VIEWPORT, viewportCoords);
	if (lighting)
	{
		glDisable(GL_LIGHTING);
	}
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0.0, viewportCoords[2], 0.0, viewportCoords[3]);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2i(x, viewportCoords[3] - y);
	while (*txt)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *txt);
		txt++;
	}
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	if (lighting)
	{
		glEnable(GL_LIGHTING);
	}
}
