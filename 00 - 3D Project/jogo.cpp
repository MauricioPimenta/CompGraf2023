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
#include <array>
#include <vector>
#include <math.h>

// Local Libraries + Project Classes
#include "Classes/rect.h"
#include "Classes/circle.h"
#include "Classes/human.h"
#include "Classes/barril.h"
#include "Classes/camera.h"

#include "Classes/imageloader.h"
#include "Classes/objloader.h"



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
//char usedKeys[] = {'w', 'W', 'a', 'A', 's', 'S', 'd', 'D'};

// State of the mouse button
std::array<bool, 2> mButtonPressed = {false, false};
int lastX = 0, lastY = 0;
double camXYAngle = 0;
double camXZAngle = 0;


// Window dimensions
GLint winWidth = 500;
GLint winHeight = 700;

GLdouble winLeft = -winWidth/2;
GLdouble winRight = winWidth/2;
GLdouble winBottom = -winHeight/2;
GLdouble winTop = winHeight/2;
GLdouble winCenterX = (winLeft + winRight)/2;
GLdouble winCenterY = (winBottom + winTop)/2;


// Program Vars
bool animate = true;	// Enable Animation

// Cameras
// Enum for active camera
enum activeCamera{
	CAM1,
	CAM2,
	CAM3
};
camera* Cam1 = new camera(75, {0, 0, 100},{0,0,0},{0,1,0}, 1, 1000);
camera* Cam2 = new camera(50, {0, 0, 100}, {0, 0, 0}, {0, 1, 0}, 1, 1000);
camera* Cam3 = new camera(90, {0, 0, 100},
							  {0, 0, 0},
							  {1, 0, 0}, 1, 200);

camera* activeCam = Cam1;

// Game Setting


// Arena 3D
GLfloat arenaHeight = 100;
GLfloat arenaWidth = winWidth;
GLfloat arenaLenght = winHeight;

Rect *arenaFloor = new Rect(arenaWidth, arenaLenght, 0, 0, 0, Rect::center, 1, 0.2, 0.2);


/*
 * 3D Meshes used
 */
mesh soldier;
mesh gun;


// human to draw
GLfloat X0 = winCenterX;
GLfloat Y0 = -winHeight/4;
GLfloat headsize = 200;
GLfloat red = 0.2;
GLfloat green = 0.8;
GLfloat blue = 0.2;

//Human h(X0, Y0, headsize, red, green, blue);
Human* h = new Human(0, 0, headsize, red, green, blue);

Rect arrowX(100, 2, 0, 0, 0, Rect::left, 1.0, 0.1, 0.1);
Rect arrowY(2, 100, 0, 0, 0, Rect::center_b, 0.1, 1.0, 0.1);

HLine playerLimit(winWidth, winLeft, winCenterY, 0.2,0.2,0.2, true, 40);

Circle* c = new Circle(50, 0, 0, 0.8, 0.2, 0.8);


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
    // Initialize atributes and variables that depend on OpenGL
	ResetKeyStatus();

    // The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.3f, 0.3f, 0.8f, 1.0f); // Bluuish, no opacity(alpha).

	// enable 3D shading and lights
	//glShadeModel (GL_FLAT);
    glShadeModel (GL_SMOOTH);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	// Load Meshes from files
	soldier.loadMesh("./Models/soldier_with_Gun.obj");


	glViewport (0, 0, (GLsizei) winWidth, (GLsizei) winHeight);

	// Select the projection matrix
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	activeCam->setPerspective((GLfloat)winWidth/(GLfloat)winHeight);


	// Change the matrix mode to the model view matrix
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	// Allocate space temporarily to get the transformation matrix
	GLfloat* modelMatrix = new GLfloat[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, modelMatrix);

	// Initialize the Transformations Matrix for the Human
	h->setTransformMatrix(modelMatrix);
	delete modelMatrix;

	// Define the Default Camera - CAM1
	activeCam->lookAt();

	// Define a light source
	GLfloat lightPos[] = {0, 0, 300, 1.0};	// Position of the light source
	GLfloat lightAmb[] = {0.2, 0.2, 0.2, 1.0};	// Ambient light intensity
	GLfloat lightDif[] = {0.7, 0.7, 0.7, 1.0};	// Diffuse light intensity
	GLfloat lightSpe[] = {1.0, 1.0, 1.0, 1.0};	// Specular light intensity

	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpe);

}


void renderScene(){
	// TODO

	// Clear the screen.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// The color the windows will redraw. Its done to erase the previous frame.
    glClearColor(0.3f, 0.3f, 0.8f, 1.0f); // Bluuish, no opacity(alpha).

	// enable 3D shading and lights
	//glShadeModel (GL_FLAT);
    glShadeModel (GL_SMOOTH);
	//glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

	// Att camera Position
	double zoom = activeCam->getCamFOV();
	double Px = zoom*sin(camXZAngle*M_PI/180)*cos((camXYAngle*M_PI/180));
	double Py = zoom*sin((camXYAngle*M_PI/180));
	double Pz = zoom*cos(camXZAngle*M_PI/180)*cos((camXYAngle*M_PI/180));
	activeCam->setCamPosition({Px, Py, Pz});

	activeCam->setPerspective((GLfloat)winWidth/(GLfloat)winHeight);
	activeCam->lookAt();

	// Draw the objects for the scene
	//h->Draw();
	h->Draw3D();
	//soldier.draw();
	//c->Draw();
	//c->Draw3D();
	//arenaFloor->Draw();

	//glutSolidCube(10);
	glTranslatef(0, 10, 10);
	glutSolidCylinder(5, 10, 10, 10);

	// Draw the World Reference Arrows
	//arrowX.Draw();
	//arrowY.Draw();
	//playerLimit.Draw();

	glutSwapBuffers(); // Draw the new frame of the game.
}


void idle(void){
	// TODO
	/*
	 * Render time definition
	 */
		// A static variable to keep the value after leaving the function call
		static GLdouble previousTime = glutGet(GLUT_ELAPSED_TIME);	// in miliseconds
		int fps = 120;	// Frames per second
		static GLdouble RenderInterval = 1000*(1/fps); // time to render based on 120fps - in miliseconds
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

	/*
	 * Check resizing of the window
	 * If the window is resized, the projection matrix must be updated
	 */
		// GLint width = glutGet(GLUT_WINDOW_WIDTH);
		// GLint height = glutGet(GLUT_WINDOW_HEIGHT);

		// if (width !=  winWidth || height != winHeight)
		// {
		// 	glPushMatrix();	// Saves the Matrix Stack

		// 	// The color the windows will redraw. Its done to erase the previous frame.
		// 	//glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black, no opacity(alpha).

		// 	glMatrixMode(GL_PROJECTION);	// Select the projection matrix
		// 	// Reset the Projection Matrix
		// 	glLoadIdentity();
		// 	// And multiply the Projection Matrix by the new Ortho
		// 	glOrtho(-(width/2),		// X coordinate of left edge
		// 			(width/2),		// X coordinate of right edge
		// 			-(height/2),		// Y coordinate of bottom edge
		// 			(height/2),		// Y coordinate of top edge
		// 			-100,					// Z coordinate of the “near” plane
		// 			100);					// Z coordinate of the “far” plane
		// 	glMatrixMode(GL_MODELVIEW); // Select the projection matrix

		// 	glPopMatrix();	// Load the Matrix Stack

		// 	glutPostRedisplay();	// Redraw
		// }


	/*
	* Key Behaviour - Movement
	*/
		// Up and Down Movement
		// UP - w
		if (keyStatus[static_cast<int>('w')] == GLUT_DOWN || keyStatus[static_cast<int>('W')] == GLUT_DOWN)
		{
			// Move the player upwards only if it is below the center of the screen
			if (h->getPositionY() <= winCenterY){
				h->moveXYZf(0, 1.0, 0);
			}
			// only allow for one key pressed each time - this prevent locking the movement when
			// the player press the keys with 'shift' pressed and then releases the 'shift' key
			// FIX: this is not working properly quando the CAPSLOCK is on because of the 'if' order below.
			if (keyStatus[static_cast<int>('w')] == GLUT_DOWN){
				keyStatus[static_cast<int>('W')] = GLUT_UP;
			}
			if (keyStatus[static_cast<int>('W')] == GLUT_DOWN){
				keyStatus[static_cast<int>('w')] = GLUT_UP;
			}

			//glutPostRedisplay();
		}
		// DOWN - s
		else if (keyStatus[static_cast<int>('s')] == GLUT_DOWN || keyStatus[static_cast<int>('S')] == GLUT_DOWN)
		{
			// Move the player downwards (-y) when not on the bottom of the screen
			if (h->getPositionY() >= (winBottom + h->getheadSize())){
				h->moveXYZf(0, -1.0, 0);
			}

			if (keyStatus[static_cast<int>('s')] == GLUT_DOWN){
				keyStatus[static_cast<int>('S')] = GLUT_UP;
			}
			if (keyStatus[static_cast<int>('S')] == GLUT_DOWN){
				keyStatus[static_cast<int>('s')] = GLUT_UP;
			}

			//glutPostRedisplay();
		}

		// Left and Right Movement
		// LEFT - a
		if (keyStatus[static_cast<int>('a')] == GLUT_DOWN || keyStatus[static_cast<int>('A')] == GLUT_DOWN)
		{
			// Move the player to the left (-x) if not on the left limit of the screen
			if (h->getPositionX() >= (winLeft+h->getheadSize()))
				h->moveXYZf(-1.0, 0, 0);


			if (keyStatus[static_cast<int>('a')] == GLUT_DOWN)
				keyStatus[static_cast<int>('A')] = GLUT_UP;

			if (keyStatus[static_cast<int>('A')] == GLUT_DOWN)
				keyStatus[static_cast<int>('a')] = GLUT_UP;

			//glutPostRedisplay();
		}
		// RIGHT - d
		else if (keyStatus[static_cast<int>('d')] == GLUT_DOWN || keyStatus[static_cast<int>('D')] == GLUT_DOWN)
		{
			// Move the player to the right (+x) if not on the right limit of the screen
			if (h->getPositionX() <= (winRight - h->getheadSize()))
				h->moveXYZf(+1.0, 0, 0);

			if (keyStatus[static_cast<int>('d')] == GLUT_DOWN)
				keyStatus[static_cast<int>('D')] = GLUT_UP;

			if (keyStatus[static_cast<int>('D')] == GLUT_DOWN)
				keyStatus[static_cast<int>('d')] = GLUT_UP;


			//glutPostRedisplay();
		}

}


void keyPress(unsigned char key, int x, int y){
	keyStatus[static_cast<int> (key)] = GLUT_DOWN;
	switch (key)
	{
	case '1':
		activeCam = Cam1;
		break;
	case '2':
		activeCam = Cam2;
		break;
	case '3':
		activeCam = Cam3;
		break;
	case 27:	// ESC
		exit(0);
	default:
		break;
	}

}


void keyup(unsigned char key, int x, int y)
{
    keyStatus[static_cast<int>(key)] = GLUT_UP;
    glutPostRedisplay();
}


void mouse_motion(int x, int y)
{
	//TODO: Camera Movement with mouse if it is CAM3
    if (!mButtonPressed[0])
        return;
	else
	{
		camXYAngle += y - lastY;
		camXZAngle -= x - lastX;

		lastX = x;
		lastY = y;
	}

}

void mouse_callback(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        mButtonPressed[0] = true;
    }
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        mButtonPressed[0] = true;
    }
}

void reshape(GLint w, GLint h){
	// Ajusta o tamanho da tela com a janela de visualizacao
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
	// TODO: substitute with the active camera perspective
        activeCam->setPerspective((GLfloat)w/(GLfloat)h);
		//gluPerspective (45, (GLfloat)h/(GLfloat)w, 1, 1000);
    else
        gluPerspective (45, (GLfloat)w/(GLfloat)h, 1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
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
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create the window.
    glutInitWindowSize(winWidth, winHeight);
    glutInitWindowPosition(150,50);
    glutCreateWindow(GAME_TITLE);

    // Define callbacks.
    glutDisplayFunc(renderScene);
	glutReshapeFunc(reshape);
    glutKeyboardFunc(keyPress);
    glutIdleFunc(idle);
    glutKeyboardUpFunc(keyup);

	glutMotionFunc(mouse_motion);
    glutMouseFunc(mouse_callback);

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