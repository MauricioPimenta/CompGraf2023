/***********************************************************************
 * Arquivo: quadrado.cpp
 *
 * Autor: Maurício Bittencourt Pimenta
 *
 * Descrição:
 *
 * Aprendendo a usar OpenGL, GLU e Glut
 * Desenha um quadrado e realiza algumas operações
 ***********************************************************************/


/*
 * Bibliotecas usadas no codigo
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>


/*
 * Macros e Constantes
 */
#define TAMANHO_JANELA 500		// Tamanho inicial da janela
#define WIN_X	10			// Posicao inicial da janela (x,y) em relacao
#define WIN_Y	10			// ao canto superior esquerdo


/*
 * Variaveis Globais Necessárias
 */

// Armazenar posicao e tamanho do quadrado
float qX = 0.25, qY = 0.25;
float qL = 0.5;

/*
 * Cabecalhos de Funcoes do Programa
 */
void display(void);
void init (void);
void Redisplay(void);
void KeyPress(unsigned char key, int x, int y);


/*
 *	The All Powerfull MAIN
 */

int main(int argc, char** argv)
{
	// Inicializa o glut com argumentos da main
    glutInit(&argc, argv);

	// Inicializa o modo do display
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Define o tamanho e a posicao da janela
    glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA);
    glutInitWindowPosition (WIN_X, WIN_Y);

	// Cria a Janela com um Nome
	int windows = glutCreateWindow ("My Gorgeous Looking Square!");

	// Local function to set OpenGL initial configurations
	init ();

	// Define callback Functions
    glutDisplayFunc(display);		// Display Function
	glutKeyboardFunc(KeyPress);		// Keyboard function


	// Inicia o Loop Principal do Programa
    glutMainLoop();

    return 0;
}


/*-------------------------------------------------------------------------
 *
 *						Funções Usadas no Programa
 *
 *-------------------------------------------------------------------------*/

void display(void)
{
	/* Limpar todos os pixels  */
	glClear (GL_COLOR_BUFFER_BIT);

	/* Define cor dos vértices com os valores R, G e B variando de 0.0 a 1.0 */
	glColor3f (1.0, 0.6, 0.2);
	/* Desenhar um polígono branco (retângulo) */
	glBegin(GL_POLYGON);
		glVertex3f (qX, qY, 0.0);
		glVertex3f (qX + qL, qY, 0.0);
		glVertex3f (qX + qL, qY + qL, 0.0);
		glVertex3f (qX, qY + qL, 0.0);
	glEnd();

	/* Desenhar no frame buffer! */
	glutSwapBuffers(); // Funcao apropriada para janela double buffer
}

void init (void)
{
	/* selecionar cor de fundo (preto) */
	glClearColor (0.0, 0.0, 0.0, 0.0);

	/* inicializar sistema de visualizacao */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void Redisplay(void){

}

void KeyPress(unsigned char key, int x, int y)
{
	// Check key presses and move the square.
	if (key == 'w')
	{
		qY += 0.01;
	}
	else if (key == 's')
	{
		qY -= 0.01;
	}
	else if (key == 'a')
	{
		qX -= 0.01;
	}
	else if (key == 'd')
	{
		qX += 0.01;
	}
	else
	{
		return;
	}

	// Draw again
	glutPostRedisplay();

}