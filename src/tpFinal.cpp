//============================================================================
// Name        : tp.cpp
// Author      : Amalia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//#include "bullet/btBulletDynamicsCommon.h"
#include "objetos/Mundo.h"
#include "funcionesAux.h"

static const string archivoDeConfiguracion = "archivosNivel1";

Mundo *mundo;

// Variables asociadas a única fuente de luz de la escena
float light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
float light_position[3] = {10.0f, 10.0f, 8.0f};
float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f};

// Variables de control
bool view_grid = true;
bool view_axis = true;
bool edit_panelA = false;
bool edit_panelB = false;


// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_AXIS (dl_handle+0)
#define DL_GRID (dl_handle+1)
#define DL_AXIS2D_TOP (dl_handle+2)


void dibujarCentral()
{

	glDisable(GL_LIGHTING);
		mundo->dibujar();
	glEnable(GL_LIGHTING);
}

void OnIdle (void)
{
	mundo->actualizar();

	glutPostRedisplay();
}

void DrawAxis()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		// X
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(15.0, 0.0, 0.0);
		// Y
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 15.0, 0.0);
		// Z
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 15.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void DrawAxis2DTopView()
{
	glDisable(GL_LIGHTING);
	glLineWidth (5.0);
	glBegin(GL_LINE_LOOP);
		// X
		glColor3f(0.0, 0.4, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();
	glLineWidth (1.0);

	glColor3f(0.5f, 0.5f, 1.0f);
	glBegin(GL_LINES);
		for (float i = 0.1; i < 1.0; i+=0.1)
		{
			glVertex3f(0.0f, i, 0.0f);
			glVertex3f(1.0f, i, 0.0f);
			glVertex3f(i, 0.0f, 0.0f);
			glVertex3f(i, 1.0f, 0.0f);
		}
	glEnd();
	glBegin(GL_QUADS);
		glColor3f (1.0, 0.95, 0.95);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();

	glEnable(GL_LIGHTING);
}


void DrawXYGrid()
{
	int i;
	glDisable(GL_LIGHTING);
	glColor3f(0.15, 0.1, 0.1);
	glBegin(GL_LINES);
	for(i=-20; i<21; i++)
	{
		glVertex3f(i, -20.0, 0.0);
		glVertex3f(i,  20.0, 0.0);
		glVertex3f(-20.0, i, 0.0);
		glVertex3f( 20.0, i, 0.0);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}
void Set3DEnv()
{
	glViewport (0, 0, (GLsizei) W_WIDTH, (GLsizei) W_HEIGHT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) W_WIDTH/(GLfloat) W_HEIGHT, 0.10, 100.0);
}

void SetPanelTopEnvA()
{
	glViewport (TOP_VIEWA_POSX, TOP_VIEWA_POSY, (GLsizei) TOP_VIEWA_W, (GLsizei) TOP_VIEWA_H);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D(-0.10, 1.05, -0.10, 1.05);
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
	dl_handle = glGenLists(3);

	glClearColor (0.02, 0.02, 0.04, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

	// Generación de las Display Lists
	glNewList(DL_AXIS, GL_COMPILE);
		DrawAxis();
	glEndList();
	glNewList(DL_GRID, GL_COMPILE);
		DrawXYGrid();
	glEndList();
	glNewList(DL_AXIS2D_TOP, GL_COMPILE);
		DrawAxis2DTopView();
	glEndList();
	glColor3f(0.0,0.0,0.0);

	try
	{
		mundo = new Mundo( archivoDeConfiguracion );

	}
	catch ( EArchivoInexistente *e )
	{
		cout<< e->what() <<endl;
		exit(1);
	}

}



void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///////////////////////////////////////////////////
	// Escena 3D
	Set3DEnv();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//seteo el eye y at de la camara actual

	actualizarVista();




	if (view_axis)
		 glCallList(DL_AXIS);

	if (view_grid)
		 glCallList(DL_GRID);
	//
	///////////////////////////////////////////////////

		dibujarCentral();

	///////////////////////////////////////////////////
	// Panel 2D para la vista superior
	if (edit_panelA)
	{
		SetPanelTopEnvA();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);

		glCallList(DL_AXIS2D_TOP);
	}

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

		glCallList(DL_AXIS2D_TOP);
	}
	//
	///////////////////////////////////////////////////


	glutSwapBuffers();
}

void reshape (int w, int h)
{
   	W_WIDTH  = w;
	W_HEIGHT = h;
}

void keyboard (unsigned char key, int x, int y)
{
   switch (key) {
      case 'q':
    	  delete mundo;

         exit(0);
         break;
	  case 'g':
		  view_grid = !view_grid;
		  glutPostRedisplay();
		  break;

	  case 'a':
		  view_axis = !view_axis;
		  glutPostRedisplay();
		  break;

	  case '1':
		  edit_panelA = !edit_panelA;
		  glutPostRedisplay();
		  break;
	  case '2':
		  edit_panelB = !edit_panelB;
		  glutPostRedisplay();
		  break;

	  case 'k':

		  glutPostRedisplay();
		  break;
	  case 'l':

		  glutPostRedisplay();
		  break;

	  case 'n':
//		  barco->decAngulo();
		  break;

	  case 'm':
//		  barco->incAngulo();
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
