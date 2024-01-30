/**************************************************************************************
 * Barril.h
 *
 * Header file for Barril Class used to define and draw
 * the Barrels for the game, using OpenGL 1.0
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

class barrel
{
	/* Private Atributes and Methods*/
private:
	/* Private Atributes */

	// Drawing attributes for the barrel
	Rect Shape;		// Shape of the Barrel
	GLfloat height;
	GLfloat width;
	GLfloat Color[3] {1.0, 1.0, 1.0};	// Colors of the Barrel - Default is White

	// Movement attributes
	int speed;
	GLfloat PositionX;
	GLfloat PositionY;


public:
	barrel(/* args */);
	~barrel();
};


