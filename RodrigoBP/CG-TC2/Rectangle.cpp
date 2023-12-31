/*
 * Arena.cpp
 *
 *  Created on: 14/09/2015
 *      Author: rodrigo
 */

#include "Rectangle.h"
#include "tinyxml2.h"

#include <iostream>

using namespace std;
using namespace tinyxml2;

Rectangle::Rectangle() {
	// TODO Auto-generated constructor stub
	this->fill = "";
	this->height = 0.0;
	this->id = "";
	this->stroke = "";
	this->stroke_width = 0;
	this->width = 0.0;
	this->x = 0.0;
	this->y = 0.0;
}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

void Rectangle::showValues() {
	cout << "Dados Rectangle:\n";
	cout << "Id = " << this->getId() << "\n";
	cout << "X = " << this->getX() << "\n";
	cout << "Y = " << this->getY() << "\n";
	cout << "Width = " << this->getWidth() << "\n";
	cout << "Hight = " << this->getHeight() << "\n";
	cout << "Fill = " << this->getFill() << "\n";
	cout << "Stroke-Widht = " << this->getStrokeWidth() << "\n";
	cout << "Stroke = " << this->getStroke() << "\n\n";
}

void Rectangle::setValues(XMLElement* elem) {
	// atributos do tipo rect
	float x = 0.0; // posição em X
	float y = 0.0; // posição em Y
	float width = 0.0; // comprimento
	float height = 0.0; // altura
	string fill = "";
	int stroke_width = 0; // Comprimento da linha
	string stroke = "";
	string id = ""; // Identificador

	// set Id
	const char* aux = "";
	aux = (elem->Attribute("id"));
	id = aux;
	this->id = id;

	// set X
	elem->QueryFloatAttribute("x", &x);
	this->setX(x);

	// set Y
	elem->QueryFloatAttribute("y", &y);
	this->setY(y);

	// set Widht
	elem->QueryFloatAttribute("width", &width);
	this->setWidth(width);

	// set Height
	elem->QueryFloatAttribute("height", &height);
	this->setHeight(height);

	// set Fill
	aux = elem->Attribute("fill");
	fill = aux;
	this->setFill(fill);

	// set stroke_width
	elem->QueryIntAttribute("stroke-width", &stroke_width);
	this->setStrokeWidth(stroke_width);

	// set stroke
	aux = elem->Attribute("stroke");
	stroke = aux;
	this->setStroke(stroke);
}

// Getters and Setters
float Rectangle::getX () {
	return this->x;
}

void Rectangle::setX (float x) {
	this->x = x;
}

float Rectangle::getY () {
	return this->y;
}

void Rectangle::setY (float y) {
	this->y = y;
}

float Rectangle::getWidth () {
	return this->width;
}

void Rectangle::setWidth (float width) {
	this->width = width;
}

float Rectangle::getHeight () {
	return this->height;
}

void Rectangle::setHeight (float height) {
	this->height = height;
}

string Rectangle::getFill () {
	return this->fill;
}

void Rectangle::setFill (string fill) {
	this->fill = fill;
}

int Rectangle::getStrokeWidth () {
	return this->stroke_width;
}

void Rectangle::setStrokeWidth (int stroke_width) {
	this->stroke_width = stroke_width;
}

string Rectangle::getStroke () {
	return this->stroke;
}

void Rectangle::setStroke (string stroke) {
	this->stroke = stroke;
}

string Rectangle::getId () {
	return this->id;
}

void Rectangle::setId (string id) {
	this->id = id;
}
