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

void Human::DrawHuman(){
	this->leftLeg.Draw();
	this->rightLeg.Draw();
	this->Head.Draw();
	this->Gun.Draw();
}