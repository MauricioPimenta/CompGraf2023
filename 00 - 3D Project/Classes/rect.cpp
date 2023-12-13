/**************************************************************************************
 * rect.cpp
 *
 * Implementation of the functions of Class Rect.h used to define and draw
 * a Rectangle using OpenGL 1.0
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
 * Implementation of Functions
 */

// DrawCentered
void Rect::DrawCenteredOn(){

	// Define vertices Color with RGB values between 0.0 and 1.0
	glColor3f (this->Color[RED], this->Color[GREEN], this->Color[BLUE]);

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
	switch (this->anchorPlace)
	{
		case center:
			// (0,0) centered on the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX-width/2, PositionY-height/2, PositionZ);
				glVertex3f (PositionX+width/2, PositionY-height/2, PositionZ);
				glVertex3f (PositionX+width/2, PositionY+height/2, PositionZ);
				glVertex3f (PositionX-width/2, PositionY+height/2, PositionZ);
			glEnd();
			break;

		case center_b:
			// (0,0) on the center point on the bottom on the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX - width/2, PositionY, PositionZ);
				glVertex3f (PositionX + width/2, PositionY, PositionZ);
				glVertex3f (PositionX + width/2, PositionY + height, PositionZ);
				glVertex3f (PositionX - width/2, PositionY + height, PositionZ);
			glEnd();
			break;
		case center_t:
			// (0,0) on the center point on the top on the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX - width/2, PositionY, PositionZ);
				glVertex3f (PositionX + width/2, PositionY, PositionZ);
				glVertex3f (PositionX + width/2, PositionY - height, PositionZ);
				glVertex3f (PositionX - width/2, PositionY - height, PositionZ);
			glEnd();
			break;
		case left:
			// (0,0) left-center of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX, PositionY - height/2, PositionZ);
				glVertex3f (PositionX + width, PositionY - height/2, PositionZ);
				glVertex3f (PositionX + width, PositionY + height/2, PositionZ);
				glVertex3f (PositionX, PositionY + height/2, PositionZ);
			glEnd();
			break;
		case left_b:
			// (0,0) - left and bottom of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX, PositionY, PositionZ);
				glVertex3f (PositionX + width, PositionY, PositionZ);
				glVertex3f (PositionX + width, PositionY + height, PositionZ);
				glVertex3f (PositionX, PositionY + height, PositionZ);
			glEnd();
			break;
		case left_t:
			// (0,0) left-top of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX, PositionY - height, PositionZ);
				glVertex3f (PositionX + width, PositionY - height, PositionZ);
				glVertex3f (PositionX + width, PositionY, PositionZ);
				glVertex3f (PositionX, PositionY, PositionZ);
			glEnd();
			break;
		case right:
			// (0,0) right-center of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX - width, PositionY - height/2, PositionZ);
				glVertex3f (PositionX + 0, PositionY - height/2, PositionZ);
				glVertex3f (PositionX + 0, PositionY + height/2, PositionZ);
				glVertex3f (PositionX - width, PositionY + height/2, PositionZ);
			glEnd();
			break;
		case right_b:
			// (0,0) - right and bottom of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX + 0, PositionY, PositionZ);
				glVertex3f (PositionX - width, PositionY, PositionZ);
				glVertex3f (PositionX - width, PositionY + height, PositionZ);
				glVertex3f (PositionX, PositionY + height, PositionZ);
			glEnd();
			break;
		case right_t:
			// (0,0) on right-top of the Rect
			glBegin(GL_POLYGON);
				glVertex3f (PositionX - width/2, PositionY, PositionZ);
				glVertex3f (PositionX + width/2, PositionY, PositionZ);
				glVertex3f (PositionX + width/2, PositionY - height, PositionZ);
				glVertex3f (PositionX - width/2, PositionY - height, PositionZ);
			glEnd();
			break;

		default:
			break;
	}


}


