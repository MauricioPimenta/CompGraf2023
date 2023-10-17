/**************************************************************************************
 * jogo.cpp - Codigo principal do jogo 2D
 *
 *
 * Implements a 2D game using OpenGL, GLU and GLUT (freeglut)
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/


/*
 * Libraries
 */

// OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>		// Include freeglut_std.h
#include <GL/freeglut.h>	// Include freeglut_std.h and freeglut_ext.h

// c and c++ libraries
#include <stdio.h>

// Local Libraries + Project Classes
#include "Classes/rect.h"
#include "Classes/circle.h"


/*
 * Constants
 */
#define INC_KEY 1
#define INC_KEYIDLE 1

#define GAME_TITLE	"Jogo do Bebum"


/*
 * Global Variables
 */

//Key status
int keyStatus[256];

// Window dimensions
GLint winWidth = 500;
GLint winHeight = 700;

// Viewing dimensions
GLint ViewingWidth = winWidth;
GLint ViewingHeight = winHeight;

// Circle to test drawing
Circle c = Circle();
Rect R = Rect();


/*
 * Function Declarations
 */
void loadConfig();
void ResetKeyStatus();

/*
 * Callback Functions
 */

void init(void)
{
    ResetKeyStatus();

    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).

    glMatrixMode(GL_PROJECTION);	// Select the projection matrix
    glOrtho(-(ViewingWidth/2),		// X coordinate of left edge
            (ViewingWidth/2),		// X coordinate of right edge
            -(ViewingHeight/2),		// Y coordinate of bottom edge
            (ViewingHeight/2),		// Y coordinate of top edge
            -100,					// Z coordinate of the “near” plane
            100);					// Z coordinate of the “far” plane
    glMatrixMode(GL_MODELVIEW); // Select the model view matrix
    glLoadIdentity();

}


void keyPress(unsigned char key, int x, int y){
	// TODO
}


void keyup(unsigned char key, int x, int y)
{
    keyStatus[(int)(key)] = 0;
    glutPostRedisplay();
}


void renderScene(){
	// TODO

	// Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);

	//R.Draw();
	c.Draw();

	glutSwapBuffers(); // Draw the new frame of the game.
}


void idle(void){
	// TODO
	// A static variable to keep the value after leaving the function call
	static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);	// in miliseconds

	static GLdouble RenderInterval = 1000*(1/60); // time to render based on 60fps - in miliseconds
	static GLdouble RenderTime = 0;

	// Pega o tempo que passou do inicio da aplicacao
	GLdouble currentTime = glutGet(GLUT_ELAPSED_TIME);	// in miliseconds

	// Calcula o tempo decorrido desde a ultima frame.
	GLdouble timeDiference = currentTime - previousTime;	// in ms
	RenderTime += timeDiference;
	// Atualiza o tempo do ultimo frame ocorrido
	previousTime = currentTime;

	if (RenderTime >= RenderInterval)
	{
		// Redraw Everything and reset RenderTime
		RenderTime = 0;
		glutPostRedisplay();
	}

	// Check resizing of the window
	GLint width = glutGet(GLUT_WINDOW_WIDTH);
	GLint height = glutGet(GLUT_WINDOW_HEIGHT);

	if (width !=  winWidth || height != winHeight)
	{
		glPushMatrix();	// Saves the Matrix Stack

		// The color the windows will redraw. Its done to erase the previous frame.
		//glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).

		glMatrixMode(GL_PROJECTION);	// Select the projection matrix
		// Reset the Projection Matrix
		glLoadIdentity();
		// And multiply the Projection Matrix by the new Ortho
		glOrtho(-(width/2),		// X coordinate of left edge
				(width/2),		// X coordinate of right edge
				-(height/2),		// Y coordinate of bottom edge
				(height/2),		// Y coordinate of top edge
				-100,					// Z coordinate of the “near” plane
				100);					// Z coordinate of the “far” plane
		glMatrixMode(GL_MODELVIEW); // Select the projection matrix

		glPopMatrix();	// Load the Matrix Stack

		glutPostRedisplay();	// Redraw
	}

}


/*
 * Main Function
 */
int main (int argc, char** argv)
{
	// Load Configuration File
	loadConfig();

	// Initialize openGL with Double buffer and RGB color without transparency.
    // Its interesting to try GLUT_SINGLE instead of GLUT_DOUBLE.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Create the window.
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(150,50);
    glutCreateWindow(GAME_TITLE);

    // Define callbacks.
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyPress);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);

    init();

	// glutMainLoopEvent();
    glutMainLoop();

    return 0;
}


/*
 * Local Functions
 */

void loadConfig(){
	// TODO
	c.setFillColor3f(0.8, 0.2, 0.2);
}

void ResetKeyStatus()
{
    int i;
    //Initialize keyStatus
    for(i = 0; i < 256; i++)
       keyStatus[i] = 0;
}