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
#include "objloader.h"

#include <stdio.h>
#include <array>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>		// Include freeglut_std.h
#include <GL/freeglut.h>	// Include freeglut_std.h and freeglut_ext.h

/*
 * Constants and Default Values
 */
#define ORIGIN_X	0
#define ORIGIN_Y	0
#define ORIGIN_Z	0
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
		GLfloat PositionX {ORIGIN_X};
		GLfloat PositionY {ORIGIN_Y};
		GLfloat PositionZ {ORIGIN_Z};

		// Head
		Circle Head;
		GLfloat headSize {HEAD_SIZE};	// Diameter of the Head
		GLfloat headColor[3] {0.0, 1.0, 0.0};	// Color of the Head - Default green
		GLfloat headCenter[3] {PositionX, PositionY, PositionZ};

		// Left Leg
		Rect leftLeg;
		GLfloat leftLegPositionX {PositionX - headSize/4};
		GLfloat leftLegPositionY {PositionY};
		GLfloat leftlegPositionZ {PositionZ};

		// Right Leg
		Rect rightLeg;
		GLfloat rightLegPositionX {PositionX + headSize/4};
		GLfloat rightLegPositionY {PositionY};
		GLfloat rightlegPositionZ {PositionZ};

		// Atributes for all legs
		GLfloat legWidth {headSize/4};
		GLfloat legSize {headSize*(float)0.8};
		GLfloat legColor[3] {0.0, 0.0, 0.0};	// Color of the Legs - Default black

		// Gun atributes
		Rect Gun;
		GLfloat gunWidth {headSize/3};
		GLfloat gunSize {headSize*(float)1.5};
		GLfloat gunColor[3] {1.0, 0.0, 0.0};		// Color of the Gun - Defautl red
		GLfloat gunPositionX {PositionX + headSize/2};
		GLfloat gunPositionY {PositionY - headSize/4};
		GLfloat gunPositionZ {PositionZ};

		GLfloat* TransformMatrix;

		mesh* HumanMesh; // Mesh for 3D rendering

		// Human atributes for the game - speed, etc..
		GLfloat speed {20};

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
			// Define the Head
			this->headCenter[0] = PosX;
			this->headCenter[1] = PosY;
			this->headCenter[2] = 0;
			this->Head = Circle(headSize/2, headCenter[0], headCenter[1], headColor[RED], headColor[GREEN], headColor[BLUE]);

			// Left Leg initialization
			this->leftLegPositionX = PosX - Head_Size/4;
			this->leftLegPositionY = PosY;
			this->leftlegPositionZ = 0;
			this->leftLeg = Rect(legWidth, legSize, leftLegPositionX, leftLegPositionY, leftlegPositionZ, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);

			// Right Leg initialization
			this->rightLegPositionX = PosX + Head_Size/4;
			this->rightLegPositionY = PosY;
			this->rightlegPositionZ = 0;
			this->rightLeg = Rect(legWidth, -legSize, rightLegPositionX, rightLegPositionY, rightlegPositionZ, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);

			// Gun initialization
			this->gunPositionX = PosX + Head_Size/2;
			this->gunPositionY = PosY - Head_Size/4;
			this->gunPositionZ = 0;
			this->Gun = Rect(gunWidth, gunSize, gunPositionX, gunPositionY, gunPositionZ, Rect::left_b, gunColor[RED], gunColor[GREEN], gunColor[BLUE]);

			// Allocate memory for the Transform Matrix
			this->TransformMatrix = new GLfloat[16];

			//...
		}
		Human(GLfloat PosX, GLfloat PosY, GLfloat PosZ, GLfloat Head_Size, GLfloat Red, GLfloat Green, GLfloat Blue) :
				PositionX{PosX}, PositionY{PosY}, PositionZ{PosZ}, headSize{Head_Size}, headColor{Red, Green, Blue}
		{
			// Define the Head
			this->headCenter[0] = PositionX;
			this->headCenter[1] = PositionY;
			this->headCenter[2] = PosZ;
			this->Head = Circle(headSize/2, headCenter[0], headCenter[1], headColor[RED], headColor[GREEN], headColor[BLUE]);

			// Left Leg initialization
			this->leftLegPositionX = PositionX - headSize/4;
			this->leftLegPositionY = PositionY;
			this->leftlegPositionZ = PosZ;
			this->leftLeg = Rect(legWidth, legSize, leftLegPositionX, leftLegPositionY, leftlegPositionZ, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);

			// Right Leg initialization
			this->rightLegPositionX = PositionX + headSize/4;
			this->rightLegPositionY = PositionY;
			this->rightlegPositionZ = PosZ;
			this->rightLeg = Rect(legWidth, -legSize, rightLegPositionX, rightLegPositionY, rightlegPositionZ, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);

			// Gun initialization
			this->gunPositionX = PositionX + headSize/2;
			this->gunPositionY = PositionY - headSize/4;
			this->gunPositionZ = PosZ;
			this->Gun = Rect(gunWidth, gunSize, gunPositionX, gunPositionY, gunPositionZ, Rect::left_b, gunColor[RED], gunColor[GREEN], gunColor[BLUE]);

			// Allocate memory for the Transform Matrix
			this->TransformMatrix = new GLfloat[16];

			//...
		}

		Human(std::string meshPath, GLfloat PosX, GLfloat PosY, GLfloat Head_Size, GLfloat Red, GLfloat Green, GLfloat Blue) :
				PositionX{PosX}, PositionY{PosY}, headSize{Head_Size}, headColor{Red, Green, Blue}
		{
			this->HumanMesh = new mesh();
			this->HumanMesh->loadMesh(meshPath);

			// Define the Head
			this->headCenter[0] = PositionX;
			this->headCenter[1] = PositionY;
			//this->headCenter[2] = PosZ;
			this->Head = Circle(headSize/2, headCenter[0], headCenter[1], headColor[RED], headColor[GREEN], headColor[BLUE]);

			// Left Leg initialization
			this->leftLegPositionX = PositionX - headSize/4;
			this->leftLegPositionY = PositionY;
			//this->leftlegPositionZ = PosZ;
			this->leftLeg = Rect(legWidth, legSize, leftLegPositionX, leftLegPositionY, leftlegPositionZ, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);

			// Right Leg initialization
			this->rightLegPositionX = PositionX + headSize/4;
			this->rightLegPositionY = PositionY;
			//this->rightlegPositionZ = PosZ;
			this->rightLeg = Rect(legWidth, -legSize, rightLegPositionX, rightLegPositionY, rightlegPositionZ, Rect::center_b, legColor[RED], legColor[GREEN], legColor[BLUE]);

			// Gun initialization
			this->gunPositionX = PositionX + headSize/2;
			this->gunPositionY = PositionY - headSize/4;
			//this->gunPositionZ = PosZ;
			this->Gun = Rect(gunWidth, gunSize, gunPositionX, gunPositionY, gunPositionZ, Rect::left_b, gunColor[RED], gunColor[GREEN], gunColor[BLUE]);

			// Allocate memory for the Transform Matrix
			this->TransformMatrix = new GLfloat[16];

			//...
		}

		/*
		 * Getters and Setters for the Class
		 */

		GLfloat getSpeed(){
			return this->speed;
		}
		void setSpeed(GLfloat speed){
			this->speed = speed;
		}
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
			this->PositionZ += moveZ*this->speed;

			// TODO: Record position change on the human parts?

			// Restore the previous matrix
			glPopMatrix();
		}

				// Load the Transformation Matrix to draw the human after movement
		void Draw(){
			// Save the current matrix
			glPushMatrix();

			//glLoadIdentity();
			glMultMatrixf(this->TransformMatrix);	// Load the transform matrix
			// Draw the Human
			DrawHuman();

			if (this->HumanMesh != NULL)
				this->HumanMesh->draw();

			// Restore the previous matrix
			glPopMatrix();
		}

		void Draw3D(){
			// Push Matrix
			glPushMatrix();
			
			printf("\n\nDrawing Human 3D Parts using OpenGL transforms!!! \n\n");
			
				//glLoadIdentity();
				glMultMatrixf(this->TransformMatrix);	// Load the transform matrix

				glPushMatrix();
					// Draw Left Leg
					glTranslatef(this->leftLegPositionX, this->leftLegPositionY, this->leftlegPositionZ);
					glutSolidCylinder(this->legWidth/2, this->legSize, 10, 10);

				glPopMatrix();

				// Draw Right Leg
				glPushMatrix();
					glTranslatef(this->rightLegPositionX, this->rightLegPositionY, this->rightlegPositionZ);
					glutSolidCylinder(this->legWidth/2, this->legSize, 10, 10);
				glPopMatrix();

				// Draw Body
				glTranslatef(0, 0,this->legSize);	// Go to bottom of the body
				glutSolidCylinder(this->headSize*1.5, this->headSize*2, 10, 10);
				glTranslatef(0, 0,this->headSize*2);	// Go to top of the body

				glPushMatrix();

					// Draw Neck
					glutSolidCone(this->headSize*0.8, this->headSize*1, 10, 8);

					glTranslatef(0, 0,this->headSize*0.3);

					// Draw Head
					glutSolidSphere(this->headSize, this->headSize, this->headSize);

				glPopMatrix(); // go back to the top of the body

				// Draw Arms
				glPushMatrix();
					// Left Arm
					glTranslatef(- this->headSize*1.5/2, 0, -this->headSize*0.1);
					glRotatef(180, 1, 0, 0);
					glutSolidCylinder(this->legWidth, this->legSize, 4, 4);
				glPopMatrix();
				glPushMatrix();
					// Right Arm
					glTranslatef(+ this->headSize*1.5/2, 0, -this->headSize*0.1);
					glRotatef(180, 1, 0, 0);
					glutSolidCylinder(this->legWidth, this->legSize, 4, 4);
				glPopMatrix();

			glPopMatrix(); // Pop Matrix

				// glBegin(GL_POLYGON);
				// 	glVertex3f (PositionX-width/2, PositionY-height/2, PositionZ);
				// 	glVertex3f (PositionX+width/2, PositionY-height/2, PositionZ);
				// 	glVertex3f (PositionX+width/2, PositionY+height/2, PositionZ);
				// 	glVertex3f (PositionX-width/2, PositionY+height/2, PositionZ);
				// glEnd();



		}

		~Human(){
			// Deleting objects from the memory
			delete this->TransformMatrix;
		}
};

#endif	/* HUMAN_H */

