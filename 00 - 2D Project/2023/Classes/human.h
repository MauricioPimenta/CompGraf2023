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
		GLfloat speed {1};

		/* Private Methods */
		void DrawHuman();

	public:
		// Inicialize the Human and its parts
		Human(GLfloat PosX, GLfloat PosY, GLfloat Head_Size, GLfloat Red, GLfloat Green, GLfloat Blue) :
				PositionX{PosX}, PositionY{PosY}, headSize{Head_Size}, headColor{Red, Green, Blue}
		{
			this->Head = Circle(headSize/2, PositionX, PositionY, headColor[RED], headColor[GREEN], headColor[BLUE]);

			this->leftLeg = Rect(legWidth, legSize, (PositionX-headSize/4), PositionY, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);
			this->rightLeg = Rect(legWidth, -legSize, (PositionX+headSize/4), PositionY, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);
			this->Gun = Rect(gunWidth, gunSize, (PositionX + headSize/2), (PositionY - headSize/4), Rect::left_b, gunColor[RED], gunColor[GREEN], gunColor[BLUE]);
		}

		void Draw(){
			DrawHuman();
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


		/* Other Functions */
		void moveY(GLfloat move){

			glPushMatrix();
			glLoadIdentity();

			glTranslatef(0,move*this->speed,0);
			this->Draw();

			glPopMatrix();

			//this->PositionY += move*this->speed;
			printf("\n\nYPos = %f\n\n\n", this->PositionY);

		}






		~Human(){
			// Deleting objects from the memory
		}
};

#endif	/* HUMAN_H */

