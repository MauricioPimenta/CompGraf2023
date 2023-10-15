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

#include <iostream>


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
	//glColor3f (Color[RED], Color[GREEN], Color[BLUE]);
	glColor3f(1,1,1);

	float ang = 20*M_PI/180; // 20 degrees = 20 * pi / 180 radians
	GLfloat X1 = PositionX;
	GLfloat Y1 = PositionY + radius;

	glBegin(GL_POLYGON);
		glVertex2f(X1, Y1);

		for (float i = ang; i <= 2*M_PI; i += ang)
		{
			GLfloat Vx = PositionX + radius*cos(0.5*M_PI - i);
			GLfloat Vy = PositionY + radius*sin(0.5*M_PI - i);
			// std::cout << "\nVx = " << Vx;
			// std::cout << "\nVy = " << Vy;
			// std::cout << "\n.......\n";
			glVertex2f(Vx,Vy);
		}
	glEnd();
}