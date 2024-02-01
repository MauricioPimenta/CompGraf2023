/**************************************************************************************
 * gun.h - Class for the Gun object
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/


// Define our lib to compiler
#ifndef GUN_H
#define	GUN_H

/*
 * Libraries Needed
 */

#include "rect.h"
#include <GL/gl.h>
#include <GL/glu.h>

class Gun{
	private:
		/*
		 * Class Atributes and Data
		 */

		// Define all the atributes for drawing the Gun Object
		GLfloat PositionX {0};
		GLfloat PositionY {0};

		GLfloat gunWidth {0};
		GLfloat gunSize {0};
		GLfloat gunColor[3] {0.0, 0.0, 0.0};		// Color of the Gun - Defautl black

		// Define the gun object
		Rect gun;

	public:
		/*
		 * Constructors and Destructors
		 */
		Gun(GLfloat PositionX, GLfloat PositionY, GLfloat gunWidth, GLfloat gunSize, GLfloat gunColor[3]);
		Gun(GLfloat PositionX, GLfloat PositionY, GLfloat gunWidth, GLfloat gunSize);
		Gun(GLfloat PositionX, GLfloat PositionY, GLfloat gunWidth);
		Gun(GLfloat PositionX, GLfloat PositionY);
		Gun();

		/*
		 * Public Methods
		 */
		void Draw();
		void setWidth(GLfloat gunWidth);
		void setSize(GLfloat gunSize);
		void setColor(GLfloat gunColor[3]);
		void setPosition(GLfloat PositionX, GLfloat PositionY);
		void setPositionX(GLfloat PositionX);
		void setPositionY(GLfloat PositionY);
		GLfloat getWidth();
		GLfloat getSize();
		GLfloat* getColor();
		GLfloat getX();
		GLfloat getY();
};

#endif	/* GUN_H */