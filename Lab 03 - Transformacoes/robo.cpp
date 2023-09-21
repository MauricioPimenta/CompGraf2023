#include "robo.h"
#include <math.h>

void Robo::DesenhaRect(GLint height, GLint width, GLfloat R, GLfloat G, GLfloat B)
{
	/* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
	glColor3f (R, G, B);
	
	// Desenha um quadrado com altura = height e largura = width
	// com a origem no ponto central da base do retangulo
	//
	//	 h	-------------------------
	// 		|						|
	//		|						|
	//		|						|
	//	 0	------------x------------
	// 	   -w						+w
	// x -> Origem do retangulo
	//
	glBegin(GL_POLYGON);
		glVertex3f (-width, 0, 0.0);
		glVertex3f (width, 0, 0.0);
		glVertex3f (width, height, 0.0);
		glVertex3f (-width, height, 0.0);
	glEnd();

}

void Robo::DesenhaCirc(GLint radius, GLfloat R, GLfloat G, GLfloat B)
{

}

void Robo::DesenhaRoda(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat R, GLfloat G, GLfloat B)
{


}

void Robo::DesenhaBraco(GLfloat x, GLfloat y, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
	glPushMatrix();

	// Muda o sistema de coordenadas para a base da primeira haste
	// A primeira haste é desenhada no x do robô e na altura da base do robô
	glTranslatef(x, y, 0);

	// Rotaciona a haste de acordo com o angulo dado (angulo em Graus)
	glRotatef(theta1, 0,0,1);

	// Desenha a primeira haste do braço do robô - desenha o retângulo
	// no novo sistema de coordenadas definido pelas transformacoes realizadas acima
	DesenhaRect(paddleHeight, paddleWidth, 0,0,1);

	// Fazemos o mesmo para as outras hastes do braco
	glTranslatef(0, paddleHeight, 0);
	glRotatef(theta2, 0, 0, 1);
	DesenhaRect(paddleHeight, paddleWidth, 1,1,0);

	glTranslatef(0, paddleHeight, 0);
	glRotatef(theta3, 0,0,1);
	DesenhaRect(paddleHeight, paddleWidth, 0,1,0);


	glPopMatrix();

}

void Robo::DesenhaRobo(GLfloat x, GLfloat y, GLfloat thetaWheel, GLfloat theta1, GLfloat theta2, GLfloat theta3)
{
	glPushMatrix();		// Salva a matriz de transformacoes atual
	glTranslatef(x,y,0);

	// Desenha o Retangulo da Base do Robo
	DesenhaRect(baseHeight, baseWidth, 1.0, 0, 0);

	// Desenha o Braco do Robo
	DesenhaBraco(0, baseHeight, theta1, theta2, theta3);


	glPopMatrix();		// Descarta as trasnformacoes realizadas acima

	return;
}

void Robo::RodaBraco1(GLfloat inc)
{

}

void Robo::RodaBraco2(GLfloat inc)
{

}

void Robo::RodaBraco3(GLfloat inc)
{

}

void Robo::MoveEmX(GLfloat dx)
{
	gX += dx*speed;
}

void Robo::setSpeed(GLfloat s){
	speed = s;
}

// Funcao auxiliar de rotacao
void RotatePoint(GLfloat x, GLfloat y, GLfloat angle, GLfloat &xOut, GLfloat &yOut){

}

Tiro* Robo::Atira()
{
	return NULL;
}
