/**************************************************************************************
 * human.h - Define the structure to define and draw a basic human using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

// Define our lib to compiler
#ifndef HUMAN_H
#define	HUMAN_H

/*
 * Libraries Needed
 */
#include "circle.h"
#include "rect.h"

#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*
 * Constants and Default Values
 */
#define ORIGIN_X	0
#define ORIGIN_Y	0
#define HEAD_SIZE	100		// Standard Diameter for the head

class Human
{
private:
	/* Constants and Default Values */
	enum Colors{
		RED,
		GREEN,
		BLUE
	};

	/* data */
	Circle Head;
	GLfloat headSize {HEAD_SIZE};
	GLfloat headColor[3] {1.0, 1.0, 1.0};

	Rect leftLeg;
	Rect rightLeg;
	GLfloat legWidth {headSize/4};
	GLfloat legSize {headSize/2};

	Rect Gun;

	GLfloat PositionX {0};
	GLfloat PositionY {0};

	GLfloat* TransformMatrix;

public:
	Human(){
		// Inicialize the Human and its parts
		Head = Circle(headSize/2, PositionX, PositionY, headColor[RED], headColor[GREEN], headColor[BLUE]);
		leftLeg = Rect(legWidth, legSize); // TODO : Define Position of Leg and its color

	}
	~Human();
};

#endif	/* HUMAN_H */

