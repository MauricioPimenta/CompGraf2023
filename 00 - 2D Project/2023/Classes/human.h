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

		/* Private Methods */
		void DrawHuman();

		void printTransformMatrix(){
			printf("\n\nTransformMatrix = ");
			printf("\n[ ");
			for(int i = 0; i < 16; i++){
				if (i == 4 || i == 8 || i == 12)
					printf("\n[ ");

				printf(" %f, ", this->TransformMatrix[i]);

				if (i == 3 || i == 7 || i == 11)
					printf(" ], ");
			}
			printf(" ]\n\n");
		}

	public:
		// Initialize the Human and its parts
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

		void Draw(){
			// Save the current matrix
			glPushMatrix();

			glLoadIdentity();
			glLoadMatrixf(this->TransformMatrix);	// Load the transform matrix
			// Draw the Human
			DrawHuman();

			// Restore the previous matrix
			glPopMatrix();
		}

		/*
		 * Getters and Setters for the Class
		 */
		// Position
		GLfloat getPositionX(){
			return this->PositionX;
		};
		void setPositioX(GLfloat X){
			this->PositionX = X;
		};

		GLfloat getPositionY(){
			return this->PositionY;
		}
		void setPositionY(GLfloat Y){
			this->PositionY = Y;
		};

		// Head
		GLfloat getheadSize(){
			return this->headSize;
		}
		void setheadSize(GLfloat sz){
			this->headSize = sz;
		}

		// GLfloat* getheadColor(){
		// 	GLfloat R = this->headColor[RED];
		// 	GLfloat G = this->headColor[GREEN];
		// 	GLfloat B = this->headColor[BLUE];

		// 	GLfloat Color[3] = {R, G, B};
		// 	return Color;
		// }
		void setheadColor(GLfloat R, GLfloat G, GLfloat B){
			this->headColor[RED] = R;
			this->headColor[GREEN] = G;
			this->headColor[BLUE] = B;

			// Calls the setter for the circle color
		}

		// Legs
		GLfloat getlegWidth(){
			return this->legWidth;
		}
		void setlegWidth(GLfloat w){
			this->legWidth = w;
		}

		GLfloat getlegSize(){
			return this->legSize;
		}
		void setlegSize(GLfloat sz){
			this->legSize = sz;
		}

		// GLfloat* getlegColor(){
		// 	GLfloat R = this->legColor[RED];
		// 	GLfloat G = this->legColor[GREEN];
		// 	GLfloat B = this->legColor[BLUE];

		// 	GLfloat Color[3] = {R, G, B};
		// 	return Color;
		// }
		void setlegColor(GLfloat R, GLfloat G, GLfloat B){
			this->legColor[RED] = R;
			this->legColor[GREEN] = G;
			this->legColor[BLUE] = B;

			// Calls the setter for the Rect color
		}

		// Gun
		GLfloat getgunWidth(){
			return this->gunWidth;
		}
		GLfloat getgunSize(){
			return this->gunSize;
		}

		void setgunWidth(GLfloat w){
			this->gunWidth = w;
		}
		void setgunSize(GLfloat sz){
			this->gunSize = sz;
		}
		void setgunColor(GLfloat R, GLfloat G, GLfloat B){
			this->legColor[RED] = R;
			this->legColor[GREEN] = G;
			this->legColor[BLUE] = B;

			// Calls the setter for the Rect color
		}

		void setTransformMatrix(GLfloat* Matrix){
			for(int i = 0; i < 16; i++){
				this->TransformMatrix[i] = Matrix[i];
			}
		}

		/**
		 * @brief Retrieves a copy of the transform matrix for the human.
		 *
		 * @return A pointer to the first element of the copy of the transform matrix.
		 */
		GLfloat* getTransformMatrix(){
			GLfloat* MatrixCopy = new GLfloat[16];
			for(int i = 0; i < 16; i++){
				MatrixCopy[i] = this->TransformMatrix[i];
			}
			return MatrixCopy;
		}

		/* Other Functions */

		void moveXYZf(GLfloat moveX, GLfloat moveY, GLfloat moveZ){
			// save the current matrix
			glPushMatrix();
			// Load the transform matrix
			glLoadMatrixf(this->TransformMatrix);

			// Multiply the Matrix on the stack by the Translate Matrix
			glTranslatef(moveX*this->speed, moveY*this->speed, moveZ*this->speed);

			// Get the resulting matrix after the multiplication
			glGetFloatv(GL_MODELVIEW_MATRIX, this->TransformMatrix);

			// Record the change of position for the human
			this->PositionX += moveX*this->speed;
			this->PositionY += moveY*this->speed;

			// Restore the previous matrix
			glPopMatrix();
		}

		~Human(){
			// Deleting objects from the memory
			delete this->TransformMatrix;
		}
};

#endif	/* HUMAN_H */

