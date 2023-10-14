/**************************************************************************************
 * circle.h - Define the structure to define and draw a Circle using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

// Define our lib to compiler
#ifndef CIRCLE_H
#define	CIRCLE_H

/*
 * Libraries Needed
 */
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*
 * Constants and Default Values
 */
#define RADIUS	50

#define ORIGIN_X	0
#define ORIGIN_Y	0


/*
 * Class Definition
 */
class Circle
{

	// Class Atributes
    GLfloat radius {RADIUS};
	GLfloat PositionX {ORIGIN_X};
	GLfloat PositionY {ORIGIN_Y};
	GLfloat Color[3] {1.0, 1.0, 1.0};	// Colors of the Circle - Default is White

	/*
	 * Private Atributes and Methods of the Class
	 */
	private:
		/* Private Atributes */


		/* Private Methods */
		void DrawCircle(GLfloat radius, GLfloat* Color);

	/*
	 * Public Methods of the Class
	 */
	public:
		// Constructors of the Class
		Circle(){

		}
		Circle(GLfloat r) : radius(r){

		}
		Circle(GLfloat r, GLfloat PosX, GLfloat PosY) : radius{r}, PositionX{PosX}, PositionY{PosY}{ }
		Circle(float r, GLfloat Red, GLfloat Green, GLfloat Blue) : radius(r), Color{Red, Green, Blue}{	}
		Circle(GLfloat r, GLfloat PosX, GLfloat PosY, GLfloat Red, GLfloat Green, GLfloat Blue) :
				radius{r}, PositionX{PosX}, PositionY{PosY}, Color{Red, Green, Blue}{ }

		/* Public Methods */
		void Draw(){
			DrawCircle(radius, Color);
		}

		void setFillColor3f(GLfloat Red, GLfloat Green, GLfloat Blue){

			Color[0] = Red;
			Color[1] = Green;
			Color[2] = Blue;

		}


		// Destructor of the Class
};

#endif	/* CIRCLE_H */

