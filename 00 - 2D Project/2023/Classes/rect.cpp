/**************************************************************************************
 * rect.cpp
 *
 * Implementation of the functions of Class Rect.h used to define and draw
 * a Rectangule using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta	-- October 2023 --
 *************************************************************************************/

/*
 * Libraries
 */

#include "rect.h"


/*
 * Constants
 */
#define RED		0
#define GREEN	1
#define BLUE	2

/*
 * Implementation of Functions
 */

// DrawCentered
void Rect::DrawCenteredOn(GLfloat height, GLfloat width, Anchor place, GLfloat* Color){

	// Define vertice Color with RGB values between 0.0 and 1.0
	glColor3f (Color[RED], Color[GREEN], Color[BLUE]);

	// Desenha um quadrado com altura = height e largura = width
	// com a origem no ponto definido como ancora do retangulo
	//
	//	 h	-------------------------
	// 		|						|
	//		|						|
	//		|						|
	//	 0	-------------------------
	// 	   -w						+w
	// x -> Origem do retangulo
	//
	switch (place)
	{
		case center:
			// (0,0) centered on the Rect
			glBegin(GL_POLYGON);
				glVertex3f (-width/2, -height/2, 0.0);
				glVertex3f (width/2, -height/2, 0.0);
				glVertex3f (width/2, height/2, 0.0);
				glVertex3f (-width/2, height/2, 0.0);
			glEnd();
			break;

		case center_b:
			// (0,0) on the center point on the bottom on the Rect
			glBegin(GL_POLYGON);
				glVertex3f (-width/2, 0, 0.0);
				glVertex3f (width/2, 0, 0.0);
				glVertex3f (width/2, height, 0.0);
				glVertex3f (-width/2, height, 0.0);
			glEnd();
			break;
		case center_t:
			// (0,0) on the center point on the top on the Rect
			glBegin(GL_POLYGON);
				glVertex3f (-width/2, 0, 0.0);
				glVertex3f (width/2, 0, 0.0);
				glVertex3f (width/2, -height, 0.0);
				glVertex3f (-width/2, -height, 0.0);
			glEnd();
			break;
		case left:
			// (0,0) left-center of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (0, -height/2, 0.0);
				glVertex3f (width, -height/2, 0.0);
				glVertex3f (width, height/2, 0.0);
				glVertex3f (0, height/2, 0.0);
			glEnd();
			break;
		case left_b:
			// (0,0) - left and bottom of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (0, 0, 0.0);
				glVertex3f (width, 0, 0.0);
				glVertex3f (width, height, 0.0);
				glVertex3f (0, height, 0.0);
			glEnd();
			break;
		case left_t:
			// (0,0) left-top of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (0, -height, 0.0);
				glVertex3f (width, -height, 0.0);
				glVertex3f (width, 0, 0.0);
				glVertex3f (0, 0, 0.0);
			glEnd();
			break;
		case right:
			// (0,0) right-center of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (-width, -height/2, 0.0);
				glVertex3f (0, -height/2, 0.0);
				glVertex3f (0, height/2, 0.0);
				glVertex3f (-width, height/2, 0.0);
			glEnd();
			break;
		case right_b:
			// (0,0) - right and bottom of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (0, 0, 0.0);
				glVertex3f (-width, 0, 0.0);
				glVertex3f (-width, height, 0.0);
				glVertex3f (0, height, 0.0);
			glEnd();
			break;
		case right_t:
			// (0,0) on right-top of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (-width/2, 0, 0.0);
				glVertex3f (width/2, 0, 0.0);
				glVertex3f (width/2, -height, 0.0);
				glVertex3f (-width/2, -height, 0.0);
			glEnd();
			break;

		default:
			break;
	}

	glBegin(GL_POLYGON);
		glVertex3f (-width, -height, 0.0);
		glVertex3f (width, -height, 0.0);
		glVertex3f (width, height, 0.0);
		glVertex3f (-width, height, 0.0);
	glEnd();

	// (0,0) on the bottom-center of the Rect
	glBegin(GL_POLYGON);
		glVertex3f (-width/2, 0, 0.0);
		glVertex3f (width/2, 0, 0.0);
		glVertex3f (width/2, 2*height/2, 0.0);
		glVertex3f (-width/2, 2*height/2, 0.0);
	glEnd();


}


