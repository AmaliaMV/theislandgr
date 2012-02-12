#include <iostream>
#include "funcionesAux.h"

// Variables asociadas a única fuente de luz de la escena
float light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
float light_position[3] = {10.0f, 10.0f, 8.0f};
float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f};

// Variables de control
bool edit_panelB = false;

// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_GRID (dl_handle+0)

void Set3DEnv()
{
	glViewport (0, 0, (GLsizei) W_WIDTH, (GLsizei) W_HEIGHT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) W_WIDTH/(GLfloat) W_HEIGHT, 0.10, 150.0);
}

void SetPanelTopEnvB()
{
	glViewport (TOP_VIEWB_POSX, TOP_VIEWB_POSY, (GLsizei) TOP_VIEWB_W, (GLsizei) TOP_VIEWB_H);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D(-0.10, 1.05, -0.10, 1.05);
}
void init(void)
{
	dl_handle = glGenLists(1);

	glClearColor (0.02, 0.02, 0.04, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

	// Generación de las Display Lists
	glNewList(DL_GRID, GL_COMPILE);
//		DrawXYGrid();
	glEndList();
	inicializar();
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///////////////////////////////////////////////////
	// Escena 3D
	Set3DEnv();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	actualizarVista(); //seteo el eye y at de la camara actual
	dibujar3D();

	///////////////////////////////////////////////////
	// Paneles 2D

	mCmd->dibujar();


	if (edit_panelB)
	{
		SetPanelTopEnvB();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);

		/*dibuja la línea que representa al eje Z*/
		glBegin(GL_LINES);
			glLineWidth (5.0);
			glVertex3f (0.5, 0.0, 0.0);
			glVertex3f (0.5, 1.0, 0.0);
			glLineWidth (1.0);
		glEnd();
	}

	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	cout<<"key: "<<(unsigned int)key<<endl;

	if ( key == 'q' )
	{
  	  delete mCmd;
  	  delete adminCamaras;
  	  delete mouse;
  	  delete adminComandos;
  	  delete mundo;
      exit(0);
	}

	adminComandos->ejecutarComando( key );

   switch (key) {
   case 'm':
	   mCmd->modificarMostrar();
	   if ( mundo->estaPausado() == false)
		   mundo->pausar();
	   break;
     default:
         break;
   }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (0, 0);

   glutCreateWindow (argv[0]);
  // glutFullScreen();
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutPassiveMotionFunc(alMover);
   glutMotionFunc(alMoverPresionandoBoton);

   glutIdleFunc(OnIdle);
   glutMainLoop();
   return 0;
}
