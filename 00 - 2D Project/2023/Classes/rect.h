/**************************************************************************************
 * rect.h - Define the structure to draw a Rectangule using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

// Define our lib to compiler
#ifndef RECT_H
#define	RECT_H

/*
 * Libraries Needed
 */
#include <stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*
 * Constants and Default Values
 */
#define WIDTH		100
#define HEIGHT		100
#define ORIGIN_X	0
#define ORIGIN_Y	0


/*
 * Class Definition
 */
class Rect
{
	// Determine the point of the object that will be on the origin when created
	enum Anchor
	{
		center,
		center_b,
		center_t,
		left,
		left_b,
		left_t,
		right,
		right_b,
		right_t
	};

	// Class Atributes
    GLfloat width {WIDTH};	// inside {} is the default values. same as width = WIDTH
	GLfloat height {HEIGHT};
	GLfloat PositionX {ORIGIN_X};
	GLfloat PositionY {ORIGIN_Y};
	GLfloat Color[3] {1.0, 1.0, 1.0};	// Colors of the Rectangle - Default is White
	Anchor	anchorPlace {center};

	/*
	 * Private Atributes and Methods of the Class
	 */
	private:
		/* Private Atributes */


		/* Private Methods */
		void DrawCenteredOn(GLfloat height, GLfloat width, Anchor place, GLfloat* Color);

	/*
	 * Public Methods of the Class
	 */
	public:
		// Constructors of the Class
		Rect(){

		}
		Rect(float w, float h) : width(w), height(h){

		}
		Rect(float w, float h, float X, float Y): width(w), height(h), PositionX(X), PositionY(Y){

		}
		Rect(float w, float h, float X, float Y, GLfloat Red, GLfloat Green, GLfloat Blue) :
			 width(w), height(h), PositionX(X), PositionY(Y), Color{Red, Green, Blue}{

		}

		/* Public Methods */
		void Draw(){
			DrawCenteredOn(height, width, anchorPlace, Color);
		}

		// Destructor of the Class
};

#endif	/* RECT_H */

