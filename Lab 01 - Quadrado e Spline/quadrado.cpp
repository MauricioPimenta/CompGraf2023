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

// Armazena tamanho da janela atual
int winHeight = TAMANHO_JANELA;
int winWidth = TAMANHO_JANELA;

// Variaveis globais e definicoes para funcoes do teclado
int keyStatus[256];


// Variaveis globais para funcoes do mouse
float mX = 0;	// Armazena posicoes X e Y do mouse
float mY = 0;



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
void dragMouse(int x, int y);




/*
 *	The All Powerfull MAIN
 */

int main(int argc, char** argv)
{
	// Inicializa o glut com argumentos da main
    glutInit(&argc, argv);

	// Inicializa o modo do display
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	printf("\n\nArgumento argc: %d", argc);
	printf("\nArgumentos (argv): %s", argv[0]);

	if(argc == 1){
		winHeight = TAMANHO_JANELA;
		winWidth = TAMANHO_JANELA;
	}
	else if (argc == 2)
	{
		printf("\n\nargv = %s\n", *argv);
		winHeight = atoi(argv[1]); printf("\n\nwinHeight: %d\n", winHeight);
		winWidth = winHeight;
	}
	else if (argc == 3){

		winHeight = atoi(argv[1]);
		winWidth = atoi(argv[2]);
	}
	else
	{
		printf("\n\n Uso Errado do Programa!! BURRROOOOOOOO\n\n");
		return -1;
	}


	// Define o tamanho e a posicao da janela
    glutInitWindowSize (winHeight, winWidth);
    glutInitWindowPosition (WIN_X, WIN_Y);

	// Cria a Janela com um Nome
	int wind = glutCreateWindow ("My Gorgeous Looking Square!");

	// Local function to set OpenGL initial configurations
	init ();

	// Define callback Functions
    glutDisplayFunc(display);		// Display Function

	glutKeyboardFunc(KeyPress);		// Key pressed on keyboard
	glutKeyboardUpFunc(keyUp);		// Key released

	glutIdleFunc(idle);				// Callback Idle

	// Mouse Callback Functions
	glutMouseFunc(mouse);			// Callback quando há clique do mouse
	glutMotionFunc(dragMouse);		// Callback quando há movimento do mouse E tecla está pressionada



	//glut


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
	keyStatus[(int) key] = GLUT_DOWN;

	// Draw again
	glutPostRedisplay();

}

void keyUp(unsigned char key, int x, int y){
	// change key to 'not pressed'
	keyStatus[(int) key] = GLUT_UP;

	// Draw everything again
	glutPostRedisplay();
}

void idle(void){

	// Check key presses and move the square.
	if (keyStatus[(int)('w')] == GLUT_DOWN)
		qY += 0.008;
	if (keyStatus[(int)('s')] == GLUT_DOWN)
		qY -= 0.008;
	if (keyStatus[(int)('a')] == GLUT_DOWN)
		qX -= 0.008;
	if (keyStatus[(int)('d')] == GLUT_DOWN)
		qX += 0.008;

	// if(mouseButtonStatus[GLUT_LEFT_BUTTON] == GLUT_DOWN){
	// 	qX = mouseX;
	// 	qY = mouseY;
	// }

	// Redraw
	glutPostRedisplay();

}

void mouse(int button, int state, int x, int y){

	// Inverte o valor de y, pois por padrao o (0,0) do mouse é no canto superior esquerdo
	y = winHeight - y;

	// Imprime a posicao do mouse no terminal ao clicar
	// button = 0 ou GLUT_LEFT_BUTTON -> botão direito do mouse
	// state = 0 ou GLUT_DOWN-> botão pressionado
	if (button == GLUT_LEFT_BUTTON & state == GLUT_DOWN){
		printf("\n mouse(x,y): (%d,%d)\n", x, y);

		// Armazena coordenadas do mouse em valores de 0 a 1
		float mouseX = (float) x/winWidth;
		float mouseY = (float) y/winHeight;

		// Armazena a posicao inicial do clique
		mX = mouseX;
		mY = mouseY;
	}

	glutPostRedisplay();

}

void dragMouse(int x, int y){

	// Inverte o valor de y, pois por padrao o (0,0) do mouse é no canto superior esquerdo
	y = winHeight - y;
	printf("\n mouse move (x,y): (%d,%d)\n", x, y);

	// Armazena coordenadas do mouse em valores de 0 a 1
	float mouseX = (float) x/winWidth;
	float mouseY = (float) y/winHeight;

	// Se as coordenadas do mouse representarem pontos internos ao quadrado,
	// permite o arraste do quadrado -> Muda qX e qY
	if (mouseX > qX && mouseX < (qX + qL) && mouseY > qY && mouseY < (qY + qL))
	{
		// Atualiza a posicao do objeto e redesenha.
		qX += (mouseX - mX);
		qY += (mouseY - mY);
	}

	mX = mouseX;
	mY = mouseY;


	glutPostRedisplay();
}