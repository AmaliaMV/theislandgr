//============================================================================
// Name        : tp.cpp
// Author      : Amalia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include <bullet/btBulletDynamicsCommon.h>

#include <iostream>
#include "funcionesAux.h"

static const string archivoDeConfiguracion = "archivosNivel1";


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

void dibujarCentral()
{
//	cout<<"eye: x: "<< eyeX << " y: "<< eyeY<<" z: "<<eyeZ<<endl;
//	cout<<"at: x: "<< atX << " y: "<< atY<<" z: "<<atZ<<endl;

	glDisable(GL_LIGHTING);
		glBegin(GL_LINES);

			glLineWidth(10);
			glColor3f(1.0, 0.0,1.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(eyeX/4, eyeY/4, eyeZ/4);
			glColor3f(1.0, 1.0,0.0);
			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(atX, atY, atZ);

//			glVertex3f(0.0, 0.0, 7.0);
//			glVertex3f(9, 10, 7);
		glEnd();
		glLineWidth(1);


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
	dl_handle = glGenLists(2);

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

	glColor3f(0.0,0.0,0.0);

	try
	{
		mundo = new Mundo( archivoDeConfiguracion );

		adminCamaras = new AdminCamaras();

		adminCamaras->agregarCamara( CAMARA_MUNDO, new CamaraMundo() );
		adminCamaras->agregarCamara( CAMARA_BARCO, new CamaraBarco(mundo->getTBarco()) );
		adminCamaras->agregarCamara( CAMARA_CANON, new CamaraCanon(mundo->getTBarco(), mundo->getBarco()->getTCanon()) );
		adminCamaras->setCamaraActual( CAMARA_MUNDO );

		mCmd = new MCmdJuegos("texturas/menu_comandos.bmp");

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
		mCmd->dibujarPanel( W_WIDTH, W_HEIGHT );
//		SetPanelTopEnvA();
//		glMatrixMode(GL_MODELVIEW);
//		glLoadIdentity();
//		gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);
//
//		glCallList(DL_AXIS2D_TOP);
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

//		glCallList(DL_AXIS2D_TOP);
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
	cout<<"key: "<<(unsigned int)key<<endl;

   switch (key) {

   case 'm':
	   edit_panelA = !edit_panelA;
	   break;

      case 'q':
    	  delete mundo;
    	  delete mCmd;
    	  delete adminCamaras;

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
	  case '0':
		  adminCamaras->setCamaraActual( CAMARA_MUNDO );
		  break;
	  case '1':
		  adminCamaras->setCamaraActual( CAMARA_BARCO );
		  break;
	  case '2':
		  adminCamaras->setCamaraActual( CAMARA_CANON );
//		  edit_panelB = !edit_panelB;
//		  glutPostRedisplay();
		  break;

	  case 'k':

		  glutPostRedisplay();
		  break;
	  case 'l':

		  glutPostRedisplay();
		  break;
	  case 'z':
		  adminCamaras->getCamaraActual()->alejarCamara();
		  break;
	  case 'x':
		  adminCamaras->getCamaraActual()->acercarCamara();
		  break;
	  case 'c':
		  mundo->getBarco()->getCanon()->decAngV();
		  break;
	  case 'v':
		  mundo->getBarco()->getCanon()->incAngV();
		  break;
	  case 'b':
		  mundo->getBarco()->getCanon()->izquierda();
		  break;
	  case 'n':
		  mundo->getBarco()->getCanon()->derecha();
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
