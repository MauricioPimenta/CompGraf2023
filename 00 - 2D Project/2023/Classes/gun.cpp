/**************************************************************************************
 * gun.h - Class for the Gun object
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

/*
 * Libraries Needed
 */
#include "gun.h"
#include <GL/gl.h>	// OpenGL library
#include <GL/glu.h>	// OpenGL Utility library

#include <array>	// Array library

	/*
	* Constructors and Destructors
	*/

	/*
		* Public Methods
		*/
	void Gun::Draw() {
		// Implementation for Draw function
		this->gun.Draw();
	}

	// Implementation for setWidth function
	void Gun::setWidth(GLfloat gunWidth) {
		this->gun.setWidth(gunWidth);
	}

	// Implementation for setSize function
	void Gun::setSize(GLfloat gunSize) {
		this->gun.setHeight(gunSize);
	}

	// Implementation for setColor function
	void Gun::setColor(GLfloat gunColor[3]) {
		this->gun.setColor(gunColor[0], gunColor[1], gunColor[2]);
	}

	// Implementation for setPosition function
	void Gun::setPosition(GLfloat PositionX, GLfloat PositionY) {
		this->gun.setPosition(PositionX, PositionY);
	}

	// Implementation for setPositionX function
	void Gun::setPositionX(GLfloat PositionX) {
		this->gun.setPositionX(PositionX);
	}

	// Implementation for setPositionY function
	void Gun::setPositionY(GLfloat PositionY) {
		this->gun.setPositionY(PositionY);
	}

	// Implementation for getWidth function
	GLfloat Gun::getWidth() {
		return this->gunWidth;
	}

	// Implementation for getSize function
	GLfloat* Gun::getColor() {
		// dynamically allocate memory for the color array
		GLfloat* color = new GLfloat[3];
		color[0] = this->gunColor[0];
		color[1] = this->gunColor[1];
		color[2] = this->gunColor[2];

		return color;
	}

	GLfloat Gun::getX() {
		// Implementation for getX function
		return this->PositionX; // Placeholder return value
	}

	GLfloat Gun::getY() {
		// Implementation for getY function
		return this->PositionY; // Placeholder return value
	}
