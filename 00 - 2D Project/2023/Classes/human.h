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
#include <array>
#include <GL/gl.h>
#include <GL/glu.h>

/*
 * Constants and Default Values
 */
#define ORIGIN_X	0
#define ORIGIN_Y	0
#define HEAD_SIZE	100		// Default diameter for the head

class Human{
	private:
		/* Constants and Default Values */
		enum Colors{
			RED,
			GREEN,
			BLUE
		};

		/*
		 * Class Atributes and Data
		 */

		// Define all the atributes for drawing the Human Object
		GLfloat PositionX {0};
		GLfloat PositionY {0};

		GLfloat headSize {HEAD_SIZE};	// Diameter of the Head
		GLfloat headColor[3] {0.0, 1.0, 0.0};	// Color of the Head - Default green


		GLfloat legWidth {headSize/4};
		GLfloat legSize {headSize*(float)0.8};
		GLfloat legColor[3] {0.0, 0.0, 0.0};	// Color of the Legs - Default black


		GLfloat gunWidth {headSize/3};
		GLfloat gunSize {headSize*(float)1.5};
		GLfloat gunColor[3] {1.0, 0.0, 0.0};		// Color of the Gun - Defautl red


		GLfloat* TransformMatrix;

		Circle Head;
		Rect leftLeg;
		Rect rightLeg;
		Rect Gun;

		// Human atributes for the game - speed, etc..
		GLfloat speed {5};
		bool runAnimation {false};
		GLfloat legAnimationSpeed {5};

		/*
		 * Private Methods
		 */
		void DrawHuman();

		void printTransformMatrix();

	public:
		// Initialize the Human and its parts
		Human(){
		};
		Human(GLfloat PosX, GLfloat PosY, GLfloat Head_Size, GLfloat Red, GLfloat Green, GLfloat Blue) :
				PositionX{PosX}, PositionY{PosY}, headSize{Head_Size}, headColor{Red, Green, Blue}
		{
			this->Head = Circle(headSize/2, PositionX, PositionY, headColor[RED], headColor[GREEN], headColor[BLUE]);

			this->leftLeg = Rect(legWidth, legSize, (PositionX-headSize/4), PositionY, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);
			this->rightLeg = Rect(legWidth, -legSize, (PositionX+headSize/4), PositionY, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);
			this->Gun = Rect(gunWidth, gunSize, (PositionX + headSize/2), (PositionY - headSize/4), Rect::left_b, gunColor[RED], gunColor[GREEN], gunColor[BLUE]);

			// Allocate memory for the Transform Matrix and set it to the Identity Matrix
			this->TransformMatrix = new GLfloat[16];

			//...
		}

	/*
	* Getters and Setters for the Class
	*/

	// Position
		GLfloat getPositionX();
		GLfloat getPositionY();
		void setPositionX(GLfloat X);
		void setPositionY(GLfloat Y);


	// Head
		GLfloat getheadSize();
//		GLfloat* getheadColor();
		void setheadSize(GLfloat sz);
		void setheadColor(GLfloat R, GLfloat G, GLfloat B);


	// Legs - Getters and Setters
		GLfloat getlegWidth();
		GLfloat getlegSize();
//		GLfloat* getlegColor();
		void setlegWidth(GLfloat w);
		void setlegSize(GLfloat sz);
		void setlegColor(GLfloat R, GLfloat G, GLfloat B);


	// Gun getters and setters
		GLfloat getgunWidth();
		GLfloat getgunSize();
		void setgunWidth(GLfloat w);
		void setgunSize(GLfloat sz);
		void setgunColor(GLfloat R, GLfloat G, GLfloat B);

	// Transform Matrix
		/**
		 * @brief Sets the transform matrix for the human.
		 *
		 * @param Matrix A pointer to the first element of the transform matrix.
		 */
		void setTransformMatrix(GLfloat* Matrix);

		/**
		 * @brief Retrieves a copy of the transform matrix for the human.
		 *
		 * @return A pointer to the first element of the copy of the transform matrix.
		 */
		GLfloat* getTransformMatrix();



		/*
		 * Other Functions - Define behaviours of human objects
		 */

		// Draw all the human parts
		void Draw();

		void moveXYZf(GLfloat moveX, GLfloat moveY, GLfloat moveZ);
		void animateRun();

		~Human(){
			// Deleting objects from the memory
			delete this->TransformMatrix;
		}
};

#endif	/* HUMAN_H */

