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
#define SCREEN_WIDTH	1920
#define	SCREEN_HEIGHT	1080

#define TAMANHO_JANELA 500		// Tamanho inicial da janela
#define WIN_X	SCREEN_WIDTH/2 - TAMANHO_JANELA/2			// Posicao inicial da janela (x,y) em relacao
#define WIN_Y	SCREEN_HEIGHT/2 - TAMANHO_JANELA/2			// ao canto superior esquerdo


/*
 * Variaveis Globais Necessárias
 */

// Armazenar posicao e tamanho do quadrado
float qX = 0.25, qY = 0.25;
float qL = 0.5;

// Variaveis globais e definicoes para funcoes do teclado
int keyStatus[256];
#define PRESSED		1
#define	NOT_PRESSED		0

#define	MOUS

/*
 * Cabecalhos de Funcoes do Programa
 */
void display(void);
void init (void);
void Redisplay(void);
void KeyPress(unsigned char key, int x, int y);
void keyUp(unsigned char key, int x, int y);
void idle(void);
void mouse(int button, int state, int x, int y);



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
	glutKeyboardFunc(KeyPress);		// Key pressed on keyboard
	glutKeyboardUpFunc(keyUp);		// Key released
	glutIdleFunc(idle);
	glutMouseFunc(mouse);		// Mouse Function


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

void KeyPress(unsigned char key, int x, int y)
{
	// Set the key pressed
	keyStatus[(int) key] = PRESSED;

	// Draw again
	glutPostRedisplay();

}

void keyUp(unsigned char key, int x, int y){
	// change key to 'not pressed'
	keyStatus[(int) key] = NOT_PRESSED;

	// Draw everything again
	glutPostRedisplay();
}

void idle(void){

	// Check key presses and move the square.
	if (keyStatus[(int)('w')] == PRESSED)
		qY += 0.001;
	if (keyStatus[(int)('s')] == PRESSED)
		qY -= 0.001;
	if (keyStatus[(int)('a')] == PRESSED)
		qX -= 0.001;
	if (keyStatus[(int)('d')] == PRESSED)
		qX += 0.001;

	// Redraw
	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y){

	// Inverte o valor de y, pois por padrao o (0,0) do mouse é no canto superior direito
	y = TAMANHO_JANELA - y;

	// Imprime a posicao do mouse no terminal ao clicar
	// button = 0 -> botão direito do mous
	// state = 0 -> botão pressionado
	if (button == 0 & state == 0){
		printf("\n mouse(x,y): (%d,%d)\n", x, y);

		// Atualiza posicao do quadrado pra onde clicou
		// x e y = valores de 0 a 500
		// qX e qY = Valores de 0 a 1
		qX = (float) x/TAMANHO_JANELA;
		qY = (float) y/TAMANHO_JANELA;
	}

}