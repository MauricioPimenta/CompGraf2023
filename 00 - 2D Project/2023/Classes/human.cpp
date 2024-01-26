/**************************************************************************************
 * human.cpp - Define the structure to define and draw a basic human using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

#include "human.h"
#include <stdio.h>


/*
 * Private Methods
 */
void Human::printTransformMatrix(){
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

void Human::DrawHuman(){
	this->Head.Draw();
	this->Gun.Draw();
	
	// If runAnimation is set, it should change the height of the legs using glscalef
	// to simulate the movement of walking
	if (this->runAnimation == true)
	{
		// Save the current matrix then scale the legs height from 1 to -1, changing the scale by 0.1 each tim it draws
		glPushMatrix();
			glScalef(1, legScale, 1);
			this->leftLeg.Draw();
		glPopMatrix();

		glPushMatrix();
			glScalef(1, legScale, 1);
			this->rightLeg.Draw();
		glPopMatrix();

		// Change the scale of the legs for the next time it draws
		this->legScale += this->legScaleInc;
		// If the scale is greater than 1 or less than -1, change the sign of the increment
		if (this->legScale <= -1 || this->legScale >= 1)
			this->legScaleInc *= -1;
	}
	else{
		this->leftLeg.Draw();
		this->rightLeg.Draw();
	}
}

/*
 * ------------------------------------------------
 */


/*
 * Public Methods
 */

	/*
	 * Getters and Setters for the Class
	*/
		// Position
		GLfloat Human::getPositionX(){
			return this->PositionX;
		};
		void Human::setPositionX(GLfloat X){
			this->PositionX = X;
		};

		GLfloat Human::getPositionY(){
			return this->PositionY;
		}
		void Human::setPositionY(GLfloat Y){
			this->PositionY = Y;
		};

		// Head
		GLfloat Human::getheadSize(){
			return this->headSize;
		}
		void Human::setheadSize(GLfloat sz){
			this->headSize = sz;
		}

		// GLfloat* getheadColor(){
		// 	GLfloat R = this->headColor[RED];
		// 	GLfloat G = this->headColor[GREEN];
		// 	GLfloat B = this->headColor[BLUE];

		// 	GLfloat Color[3] = {R, G, B};
		// 	return Color;
		// }
		void Human::setheadColor(GLfloat R, GLfloat G, GLfloat B){
			this->headColor[RED] = R;
			this->headColor[GREEN] = G;
			this->headColor[BLUE] = B;

			// Calls the setter for the circle color
		}

		// Legs
		GLfloat Human::getlegWidth(){
			return this->legWidth;
		}
		void Human::setlegWidth(GLfloat w){
			this->legWidth = w;
		}

		GLfloat Human::getlegSize(){
			return this->legSize;
		}
		void Human::setlegSize(GLfloat sz){
			this->legSize = sz;
		}

		// GLfloat* getlegColor(){
		// 	GLfloat R = this->legColor[RED];
		// 	GLfloat G = this->legColor[GREEN];
		// 	GLfloat B = this->legColor[BLUE];

		// 	GLfloat Color[3] = {R, G, B};
		// 	return Color;
		// }
		void Human::setlegColor(GLfloat R, GLfloat G, GLfloat B){
			this->legColor[RED] = R;
			this->legColor[GREEN] = G;
			this->legColor[BLUE] = B;

			// Calls the setter for the Rect color
		}

		// Gun
		GLfloat Human::getgunWidth(){
			return this->gunWidth;
		}
		GLfloat Human::getgunSize(){
			return this->gunSize;
		}

		void Human::setgunWidth(GLfloat w){
			this->gunWidth = w;
		}
		void Human::setgunSize(GLfloat sz){
			this->gunSize = sz;
		}
		void Human::setgunColor(GLfloat R, GLfloat G, GLfloat B){
			this->legColor[RED] = R;
			this->legColor[GREEN] = G;
			this->legColor[BLUE] = B;

			// Calls the setter for the Rect color
		}

		void Human::setTransformMatrix(GLfloat* Matrix){
			for(int i = 0; i < 16; i++){
				this->TransformMatrix[i] = Matrix[i];
			}
		}

		/**
		 * @brief Retrieves a copy of the transform matrix for the human.
		 *
		 * @return A pointer to the first element of the copy of the transform matrix.
		 */
		GLfloat* Human::getTransformMatrix(){
			GLfloat* MatrixCopy = new GLfloat[16];
			for(int i = 0; i < 16; i++){
				MatrixCopy[i] = this->TransformMatrix[i];
			}
			return MatrixCopy;
		}

	/* Other Functions */

	void Human::moveXYZf(GLfloat moveX, GLfloat moveY, GLfloat moveZ){
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

	void Human::Draw(){
		// Save the current matrix
		glPushMatrix();

		glLoadIdentity();
		glLoadMatrixf(this->TransformMatrix);	// Load the transform matrix
		// Draw the Human
		DrawHuman();

		// Restore the previous matrix
		glPopMatrix();
	}

	// Modify legs position and size to simulate walking movement
	void Human::animateRun(){
		if (this->runAnimation)
			this->runAnimation = false;
		else
			this->runAnimation = true;
	}
