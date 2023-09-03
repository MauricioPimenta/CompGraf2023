/***********************************************************************
 * Arquivo: spline.cpp
 *
 * Autor: Maurício Bittencourt Pimenta
 *
 * Descrição:
 *
 * Aprendendo a usar OpenGL, GLU e Glut
 *
 * Objetivo: Trabalhar os conceitos básicos de Spline incluindo a
 * construção de uma aplicação gráfica sobre o tema.
 *
 * - Implementar interações de mouse e teclado com a spline
 * 		- Modificar a Spline ao arrastar os vertices
 ***********************************************************************/


/*
 * Bibliotecas usadas no codigo
 */
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>

/*
 * Macros e Constantes
 */
#define TAMANHO_JANELA 500

#define	TITLE	"Lab 01 - Spline"	// Define o titulo da janela


/*
 * ---------------------------------------------
 *
 * -----    Necessary Global Variables    ------
 *
 * ---------------------------------------------
 */
	float size = 5.0;	// Tamanho do "mundo" das coordenadas da janela

	// Pontos de controle da Spline
	GLfloat ctrlpoints[4][3] = {
			{ -4.0, -4.0, 0.0}, { -2.0, 4.0, 0.0},
			{2.0, -4.0, 0.0}, {4.0, 4.0, 0.0}};


	/*
	 * CONTROLE DAS OPERAÇÕES COM O MOUSE
	 */

	int mousePos[2] = {0, 0};		// Armazena a ultima posicao do mouse lida
	bool mouseDrag = false;		// Possibilita arraste dos objetos com o mouse


/*
 * ---- Function Headers ----
 */

void init(void);




/*
 * ---- GLUT CALLBACK FUNCTIONS IMPLEMENTED ----
 */

void display(void)
{
   int i;

   glClear(GL_COLOR_BUFFER_BIT);

   /* Desenha a curva aproximada por n+1 pontos. */
   int n = 30;

   glColor3f(1.0, 1.0, 1.0);

   glBegin(GL_LINE_STRIP);
      for (i = 0; i <= n; i++){
        // Avaliacao do polinomio, retorna um vertice (equivalente a um glVertex3fv)
        glEvalCoord1f((GLfloat) i/(GLfloat)n);
      }
   glEnd();

   /* Desenha os pontos de controle. */
   glPointSize(5.0);
   glColor3f(1.0, 1.0, 0.0);
   glBegin(GL_POINTS);
      for (i = 0; i < 4; i++)
         glVertex3fv(&ctrlpoints[i][0]);
   glEnd();

   glutSwapBuffers();
}

/*
 * Callback de glutReshapeFunc(int w, int h)
 *   --> receives the new width and height of the window after resizing and exiting the mainLoop
 *
 * A funcao recebe:
 * int w -> new width of the window, in pixels.
 * int h -> new height of the window, in pixels.
 */
void reshape(int w, int h)
{
   // Define a porcao visivel da janela
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);

   // Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Controla o redimensionamento da janela mantendo o aspect-ratio do objeto
   if (w <= h)
      glOrtho(-size, size, -size*(GLfloat)h/(GLfloat)w,
               size*(GLfloat)h/(GLfloat)w, -size, size);
   else
      glOrtho(-size*(GLfloat)w/(GLfloat)h,
               size*(GLfloat)w/(GLfloat)h, -size, size, -size, size);

   // Muda para a matriz de trasformacoes (aulas futuras)
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

/*
 * Callback de glutMouseFunc(int button, int state, int x, int y)
 * Executa ao clicar com o mouse
 *
 * A funcao recebe:
 * int button -> Botao Pressionado pelo mouse.
 * state -> estado do botao - GLUT_UP = 1 ou GLUT_DOWN = 0
 * int x -> Posicao 'x' do mouse, em pixels.
 * int y -> Posicao 'y' do mouse, em pixels.
 *
 * Obs: A origem (0,0) é o canto superior esquerdo da janela da aplicação.
 */
void mouseClick (int button, int state, int x, int y){

	// Coloca a origem no canto inferior esquerdo da janela
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;

	mousePos[0] = x;
	mousePos[1] = y;
}

/*
 * Callback de glutMotionFunc(int x, int y)
 * Executa ao mover o mouse com o botão pressionado
 *
 * A funcao recebe:
 * int x -> Posicao 'x' do mouse, em pixels.
 * int y -> Posicao 'y' do mouse, em pixels.
 *
 * Obs: A origem (0,0) é o canto superior esquerdo da janela da aplicação.
 */
void mouseClickMov(int x, int y){

	// Coloca a origem no canto inferior esquerdo da janela
	y = glutGet(GLUT_WINDOW_HEIGHT) - y;

	// Atualiza posicao do mouse
	mousePos[0] = x;
	mousePos[1] = y;
}



/*
   -------------------------------------------

   --------- THE ALL POWERFULL MAIN ----------

   -------------------------------------------
 */
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (TAMANHO_JANELA, TAMANHO_JANELA);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (TITLE);

   init();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);

   glutMouseFunc(mouseClick);
   glutMotionFunc(mouseClickMov);


   glutMainLoop();
   return 0;
}

/*
 * Outras Funcoes do Programa
 */

/*
 * void init(void) - Funcao para inicializar o ambiente OpenGL
 */
void init(void)
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   glShadeModel(GL_FLAT);
   glEnable(GL_MAP1_VERTEX_3);

   // Definicao do polinomio com os pontos de controle
   glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);

   // Muda para a matriz de projecao (aulas futuras)
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   // Define a area/volume de visualizacao. Os objetos desenhados devem estar dentro desta area
   glOrtho(-size, size, -size, size, -size, size);
}