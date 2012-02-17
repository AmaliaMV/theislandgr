#include <iostream>
#include "funcionesAux.h"

// Variables asociadas a única fuente de luz de la escena
float light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
//float light_position[3] = {10.0f, 10.0f, 8.0f};
float light_position[4] = {-150.0f, -150.0, 50.0f};
//float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f};
float light_ambient[4] = {0.5f, 0.5f, 0.5f, 1.0f};

void Set3DEnv()
{
	glViewport (0, 0, (GLsizei) W_WIDTH, (GLsizei) W_HEIGHT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(60.0, (GLfloat) W_WIDTH/(GLfloat) W_HEIGHT, 0.10, 150.0);
}

void init(void)
{
	//GLuint dl_handle = glGenLists(1);

	glClearColor (0.02, 0.02, 0.04, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);

    glEnable(GL_LIGHTING);

//	glEnable(GL_FOG);
//	float FogCol[3]={0.8f,0.8f,0.8f};
//	glFogfv(GL_FOG_COLOR,FogCol);
//	 glFogf(GL_FOG_DENSITY, 0.015);
//	glFogi(GL_FOG_MODE, GL_EXP);

	// Generación de las Display Lists
//	glNewList(dl_handle, GL_COMPILE);
////		DrawXYGrid();
//	glEndList();
	inicializar();
}

void actualizarVista()
{
	//seteo la camara actual
	((Mouse*)mouse)->setCamara(adminCamaras->getCamaraActual()); // esto no deberia hacerse una vez por cambio de camara?

	adminCamaras->actualizarVista();
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	Set3DEnv();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	actualizarVista(); //seteo el eye y at de la camara actual

	// Panel 3D
	dibujar3D();

	// Paneles 2D
	mCmd->dibujar();

	glutSwapBuffers();
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
