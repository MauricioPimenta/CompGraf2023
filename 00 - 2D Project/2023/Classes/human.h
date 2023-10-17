/**************************************************************************************
 * circle.h - Define the structure to define and draw a Circle using OpenGL 1.0
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

class Human : public Circle, Rect
{
private:
	/* data */
public:
	Human();
	~Human();
};

Human::Human(/* args */)
{
}

Human::~Human()
{
}


#endif	/* HUMAN_H */

