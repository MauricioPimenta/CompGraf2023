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
#include "Classes/human.h"


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

GLint winLeft = -winWidth/2;
GLint winRight = winWidth/2;
GLint winBottom = -winHeight/2;
GLint winTop = winHeight/2;
GLint winCenterX = (winLeft + winRight)/2;
GLint winCenterY = (winBottom + winTop)/2;


// human to draw
GLfloat X0 = 0.0;
GLfloat Y0 = -winHeight/4;
GLfloat headsize = 50;
GLfloat red = 0.2;
GLfloat green = 0.8;
GLfloat blue = 0.2;

Human h(X0, Y0, headsize, red, green, blue);

Rect arrowX(100, 2, 0, 0, Rect::left, 1.0, 0.1, 0.1);
Rect arrowY(2, 100, 0, 0, Rect::center_b, 0.1, 1.0, 0.1);

HLine playerLimit(winWidth, winLeft, winCenterY, 0.2,0.2,0.2, true, 40);


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
    glClearColor(0.3f, 0.3f, 0.8f, 1.0f); // Black, no opacity(alpha).

    glMatrixMode(GL_PROJECTION);	// Select the projection matrix
    glOrtho(winLeft,		// X coordinate of left edge
            winRight,		// X coordinate of right edge
            winBottom,		// Y coordinate of bottom edge
            winTop,		// Y coordinate of top edge
            -100,					// Z coordinate of the “near” plane
            100);					// Z coordinate of the “far” plane

	glMatrixMode(GL_MODELVIEW); // Select the model view matrix
    glLoadIdentity();

}


void keyPress(unsigned char key, int x, int y){
	// TODO
	keyStatus[static_cast<int> (key)] = GLUT_DOWN;
}


void keyup(unsigned char key, int x, int y)
{
    keyStatus[static_cast<int>(key)] = GLUT_UP;
    glutPostRedisplay();
}


void renderScene(){
	// TODO

	// Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT);

	// Draw the objects for the scene
	h.Draw();


	// Draw the World Reference Arrows
	arrowX.Draw();
	arrowY.Draw();
	playerLimit.Draw();

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


	// Key Behaviour
	if (keyStatus[static_cast<int>('w')] == GLUT_DOWN || keyStatus[static_cast<int>('W')] == GLUT_DOWN)
	{
		// Move the player Upwards
		h.moveY(1.0);
		glutPostRedisplay();
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
	//c.setFillColor3f(0.8, 0.2, 0.2);
}

void ResetKeyStatus()
{
    int i;
    //Initialize keyStatus
    for(i = 0; i < 256; i++)
       keyStatus[i] = GLUT_UP;
}