/**************************************************************************************
 * human.h - Define the structure to define and draw a basic human using OpenGL 1.0
 *
 * Developed for UFES's Computer Graphics class - INF16014
 * Prof: Thiago Oliveira dos Santos
 *
 * Dev.: Maurício Bittencourt Pimenta
 *************************************************************************************/

// Define our lib to compiler
#ifndef CAMERA_H
#define	CAMERA_H

/*
 * Libraries Needed
 */

#include <stdio.h>
#include <array>
#include <vector>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>		// Include freeglut_std.h
#include <GL/freeglut.h>	// Include freeglut_std.h and freeglut_ext.h



class camera{

	GLdouble camFOV {60};
	GLdouble PosX {0};
	GLdouble PosY {0};
	GLdouble PosZ {-5};
	GLdouble zNear {1};
	GLdouble zFar {1000};

	std::array<GLdouble, 3> camPosition {PosX, PosY, PosZ};
	std::array<GLdouble, 3> upVector {0, 1, 0};	// y-axis
	std::array<GLdouble, 3> lookAtVector {0, 0, 0};	// origin

	public:
		
		// Constructors
		camera(){}
		camera(GLdouble camFOV, GLdouble PosX, GLdouble PosY, GLdouble PosZ){
			this->camFOV = camFOV;
			this->PosX = PosX;
			this->PosY = PosY;
			this->PosZ = PosZ;
		}
		camera(GLdouble fov, std::array<GLdouble, 3> PositionXYZ, std::array<GLdouble, 3> lookAtV, std::array<GLdouble, 3> upV){
			this->camFOV = fov;
			this->camPosition = PositionXYZ;
			this->upVector = upV;
			this->lookAtVector = lookAtV;

			this->PosX = PositionXYZ[0];
			this->PosY = PositionXYZ[1];
			this->PosZ = PositionXYZ[2];
		}
		camera(GLdouble fov, std::array<GLdouble, 3> PositionXYZ, std::array<GLdouble, 3> lookAtV, std::array<GLdouble, 3> upV, GLdouble zNear, GLdouble zFar){
			this->camFOV = fov;
			this->camPosition = PositionXYZ;
			this->upVector = upV;
			this->lookAtVector = lookAtV;
			this->zNear = zNear;
			this->zFar = zFar;

			this->PosX = PositionXYZ[0];
			this->PosY = PositionXYZ[1];
			this->PosZ = PositionXYZ[2];
		}

		// Getters and Setters

		GLdouble getCamFOV(){
			return this->camFOV;
		}
		GLdouble getPosX(){
			return this->PosX;
		}
		GLdouble getPosY(){
			return this->PosY;
		}
		GLdouble getPosZ(){
			return this->PosZ;
		}
		std::array<GLdouble, 3> getLookAtVector(){
			return this->lookAtVector;
		}
		std::array<GLdouble, 3> getUpVector(){
			return this->upVector;
		}
		std::array<GLdouble, 3> getCamPosition(){
			return this->camPosition;
		}
		GLdouble getZNear(){
			return this->zNear;
		}
		GLdouble getZFar(){
			return this->zFar;
		}



		void setCamFOV(GLdouble angle){
			this->camFOV = angle;
		}
		void setPosX(GLdouble PosX){
			this->PosX = PosX;
			this->camPosition[0] = PosX;
		}
		void setPosY(GLdouble PosY){
			this->PosY = PosY;
			this->camPosition[1] = PosY;
		}
		void setPosZ(GLdouble PosZ){
			this->PosZ = PosZ;
			this->camPosition[2] = PosZ;
		}
		void setCamPosition(GLdouble PosX, GLdouble PosY, GLdouble PosZ){
			this->PosX = PosX;
			this->PosY = PosY;
			this->PosZ = PosZ;
			this->camPosition[0] = PosX;
			this->camPosition[1] = PosY;
			this->camPosition[2] = PosZ;
		}
		void setCamPosition(std::array<GLdouble, 3> camPosition){
			this->camPosition = camPosition;
			this->PosX = camPosition[0];
			this->PosY = camPosition[1];
			this->PosZ = camPosition[2];
		}
		void setUpVector(GLdouble vecX, GLdouble vecY, GLdouble vecZ){
			this->upVector[0] = vecX;
			this->upVector[1] = vecY;
			this->upVector[2] = vecZ;
		}
		void setUpVector(std::array<GLdouble, 3> upVector){
			this->upVector = upVector;
		}
		void setLookAtVector(GLdouble vecX, GLdouble vecY, GLdouble vecZ){
			this->lookAtVector[0] = vecX;
			this->lookAtVector[1] = vecY;
			this->lookAtVector[2] = vecZ;
		}
		void setLookAtVector(std::array<GLdouble, 3> lookAtVector){
			this->lookAtVector = lookAtVector;
		}
		void setZNear(GLdouble zNear){
			this->zNear = zNear;
		}
		void setZFar(GLdouble zFar){
			this->zFar = zFar;
		}

		// Other Functions - Drawings, etc

		// Define the perspective by the camera FOV
		// Field-of-View = 50, Aspect Ratio = 1, zNear = 1, zFar = 15
		// r = zFar/zNear -> Because r approaches infinity as zNear approaches 0, zNear must never be set to 0.
		void setPerspective(GLdouble aspect){
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(this->camFOV, aspect, this->zNear, this->zFar);
			glMatrixMode(GL_MODELVIEW);
		}

		// Change the place the Camera is looking at
		void lookAt(){
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			gluLookAt(this->camPosition[0], this->camPosition[1], this->camPosition[2],
					this->lookAtVector[0], this->lookAtVector[1], this->lookAtVector[2],
					this->upVector[0], this->upVector[1], this->upVector[2]);
		}

};

#endif	/* CAMERA_H */