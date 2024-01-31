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
#include "human.h"

class barrel
{
	/* Private Atributes and Methods*/
private:
	/* Private Atributes */

	// Drawing attributes for the barrel
	Rect Shape;		// Shape of the Barrel

	GLfloat Color[3] {1.0, 1.0, 1.0};	// Colors of the Barrel - Default is White

	// behaviour attributes
	int speed {5};
	int life {5};
	bool enemy {false};

	// Enemy
	Human Enemy;

public:
	barrel(GLfloat PosX, GLfloat PosY){
		Shape = Rect(100, 50, 0, 0, Rect::center, 1, 0.2, 0.2);
		Enemy = Human(PosX, PosY, 50, 0.8, 0.2, 0.6);
	}


	// Draw the Barrel
	void draw();

};


