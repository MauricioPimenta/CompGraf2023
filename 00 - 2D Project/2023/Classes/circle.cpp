/**************************************************************************************
 * circle.cpp
 *
 * Implementation of the functions of Class Circle.h used to define and draw
 * a Circle using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta	-- October 2023 --
 *************************************************************************************/

/*
 * Libraries
 */
#include "circle.h"

#include <cmath>
#include <stdio.h>

/*
 * Constants
 */
#define RED		0
#define GREEN	1
#define BLUE	2

/*
 * Implementation of Functions
 */


void Circle::Draw(){

	if (this->Vertices2f == NULL)
	{
		printf("\nVertices not defined\n");
		return;
	}

	//static int n_draw = 0;
	//printf("\tDrawing circle: %d\n", ++n_draw);

	// Define vertices Color with RGB values between 0.0 and 1.0
	glColor3f (this->Color[RED], this->Color[GREEN], this->Color[BLUE]);
	//glColor3f(1,1,1);

	glBegin(GL_POLYGON);

		for (int i = 0; i <= 2*NUM_VERTICES-1; i+=2)
			glVertex2f(this->Vertices2f[i], this->Vertices2f[i+1]);

	glEnd();
}

void Circle::defineVertices(){

	// ang_inc = (ang_end - ang_begin)/NUM_VERTICES;
	// angulo de intervalo entre os vertices do circulo
	float ang_inc = 2*M_PI/NUM_VERTICES;
	printf("\n\nang_inc = %.2f\n", ang_inc);

	float ang = 0;
	int i = 0;
	for (i = 0; i <= (2*NUM_VERTICES-1); i+=2){

		this->Vertices2f[i] = this->PositionX + this->radius*cos(ang);
		this->Vertices2f[i+1] = this->PositionY + this->radius*sin(ang);

		printf("\n (X,Y): ( %.2f , %.2f )", this->Vertices2f[i], this->Vertices2f[i+1]);

		printf("\t\tang = %f", ang += ang_inc);
	}
	printf("\n\nangulo final = %.2f\n\n i = %d\n\n", ang, i);
}