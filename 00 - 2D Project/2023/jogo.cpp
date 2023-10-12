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
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>		// Include freeglut_std.h
#include <GL/freeglut.h>	// Include freeglut_std.h and freeglut_ext.h
#include <stdio.h>

#include "rect.h"


/*
 * Constants
 */
#define INC_KEY 1
#define INC_KEYIDLE 1


/*
 * Global Variables
 */

//Key status
int keyStatus[256];

// Window dimensions
const GLint Width = 500;
const GLint Height = 700;

// Viewing dimensions
const GLint ViewingWidth = 200;
const GLint ViewingHeight = 500;

/*
 * Function Declarations
 */
void loadConfig(FILE* f);
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
    glMatrixMode(GL_MODELVIEW); // Select the projection matrix
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
}

void idle(void){
	// TODO
}

/*
 * Main Function
 */
int main (int argc, char** argv)
{
	// Load Configuration File
	void loadConfig(FILE* f);

	// Initialize openGL with Double buffer and RGB color without transparency.
    // Its interesting to try GLUT_SINGLE instead of GLUT_DOUBLE.
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Create the window.
    glutInitWindowSize(Width, Height);
    glutInitWindowPosition(150,50);
    glutCreateWindow("");

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

void loadConfig(FILE* f){
	// TODO
}

void ResetKeyStatus()
{
    int i;
    //Initialize keyStatus
    for(i = 0; i < 256; i++)
       keyStatus[i] = 0;
}