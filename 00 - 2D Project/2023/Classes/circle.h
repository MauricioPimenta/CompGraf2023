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
#define NUM_VERTICES	360		// Number of vertices that will define the circle

#define RADIUS	50

#define ORIGIN_X	0
#define ORIGIN_Y	0


/*
 * Class Definition
 */
class Circle
{
	// Class Atributes -- Private by default
    GLfloat radius {RADIUS};
	GLfloat PositionX {ORIGIN_X};
	GLfloat PositionY {ORIGIN_Y};
	GLfloat Color[3] {1.0, 1.0, 1.0};	// Colors of the Circle - Default is White
	GLfloat Vertices2f[2*NUM_VERTICES];	// Vector to store the 2D coordinates of the vertices (X,Y)

	/*
	 * Private Atributes and Methods of the Class
	 */
	private:
		/* Private Methods */
		void defineVertices();

	/*
	 * Public Atributes and Methods of the Class
	 */
	public:
		// Constructors of the Class
		Circle()
		{
			this->defineVertices();
		}

		Circle(GLfloat r) : radius(r)
		{
			Circle();
		}
		Circle(GLfloat r, GLfloat PosX, GLfloat PosY) : radius{r}, PositionX{PosX}, PositionY{PosY}
		{
			Circle();
		 }
		Circle(float r, GLfloat Red, GLfloat Green, GLfloat Blue) : radius(r), Color{Red, Green, Blue}
		{
			Circle();
		}
		Circle(GLfloat r, GLfloat PosX, GLfloat PosY, GLfloat Red, GLfloat Green, GLfloat Blue) :
				radius{r}, PositionX{PosX}, PositionY{PosY}, Color{Red, Green, Blue}
		{
			Circle();
		}


		/* Public Methods */
		void Draw();

		void setFillColor3f(GLfloat Red, GLfloat Green, GLfloat Blue){
			if (Red >= 0.0 && Red <= 1.0 && Green >= 0.0 && Green <= 1.0 && Blue >= 0.0 && Blue <= 1.0)
			{
				printf("\n\nchanging circle color....");
				this->Color[0] = Red;
				this->Color[1] = Green;
				this->Color[2] = Blue;
			}
			else
				printf("\n\nWrong color parameter on function 'Circle::setFillColor3f'. Keeping old value\n\n");
		}


		// Destructor of the Class
};

#endif	/* CIRCLE_H */

