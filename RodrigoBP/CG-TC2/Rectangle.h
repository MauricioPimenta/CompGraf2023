/*
 * Arena.h
 *
 *  Created on: 14/09/2015
 *      Author: rodrigo
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class Rectangle {
protected:
	float x; // posição em X
	float y; // posição em Y

	float width; // comprimento
	float height; // altura

	string fill;
	int stroke_width; // Comprimento da linha
	string stroke;

	string id; // Identificador

public:
	Rectangle();
	virtual ~Rectangle();
	void showValues();
	void setValues(XMLElement* elem);

	// Getters and Setters
	float getX ();
	void setX (float x);
	float getY ();
	void setY (float y);

	float getWidth ();
	void setWidth (float width);
	float getHeight ();
	void setHeight (float height);

	string getFill ();
	void setFill (string fill);
	int getStrokeWidth ();
	void setStrokeWidth (int stroke_width);
	string getStroke ();
	void setStroke (string stroke);
	string getId ();
	void setId (string id);

};

#endif /* RECTANGLE_H_ */
