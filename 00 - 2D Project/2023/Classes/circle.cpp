/**************************************************************************************
 * circle.cpp
 *
 * Implementation of the functions of Class Circle.h used to define and draw
 * a Circle using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta	-- October 2023 --
 *************************************************************************************/

/*
 * Libraries
 */

#include "circle.h"
#include <cmath>


/*
 * Constants
 */
#define RED		0
#define GREEN	1
#define BLUE	2

/*
 * Implementation of Functions
 */


void Circle::DrawCircle(GLfloat radius, GLfloat* Color){

	// Define vertices Color with RGB values between 0.0 and 1.0
	glColor3f (Color[RED], Color[GREEN], Color[BLUE]);

	float ang = 10;
	GLfloat X1 = PositionX;
	GLfloat Y1 = PositionY + radius;

	glBegin(GL_POLYGON);
		glVertex2f(X1, Y1);
		for (int i = 0; i < 360; i = i + ang)
		{
			GLfloat Vx = PositionX + radius*cos(90-i);
			GLfloat Vy = PositionY + radius*sin(90-i);
			glVertex2f(Vx,Vy);
		}
	glEnd;
}