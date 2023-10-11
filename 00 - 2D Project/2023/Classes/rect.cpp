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
	// com a origem no ponto (Ox, Oy) da base do retangulo
	//
	//	 h	-------------------------
	// 		|						|
	//		|		x				|
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
		case center_t:
		case left:
		case left_b:
		case left_t:
		case right:
		case right_b:
		case right_t:

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


