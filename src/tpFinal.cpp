//============================================================================
// Name        : tp.cpp
// Author      : Amalia
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "funcionesAux.h"
#include "objetos/castillo/Castillo.h"

#include "fisica/Fisica.h"

Fisica *fisica;


static const string archivoDeConfiguracion = "archivosNivel1";
Castillo* castillo;

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


//		mundo->dibujar();
		castillo->dibujar();
//		glutSolidCube(1);
	glEnable(GL_LIGHTING);
}

void OnIdle (void)
{
	mundo->actualizar();
//    dynamicsWorld->stepSimulation(1/300.f,10);
	fisica->getMundoFisico()->stepSimulation(1./60.);//ms / 1000000.f);

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



void initPhysics()
{
	fisica = new Fisica();
	castillo = new Castillo( fisica );

//	btTransform startTransform;
//	startTransform.setIdentity();
//
//	int cantRows=4;
//	int cantCols=4;
//	float separacion=0.05f;
//
//	int col=0;	int row=0;	int altura=0;
//
//	for (int k=0;k<totalCajas;k++){
//
//
//
//		// defino la posicion inicial de la caja
//		float posX=((col-cantCols/2)*(tamanioCaja+separacion));
//		float posY=(row-cantRows/2)*(tamanioCaja+separacion);
//		float posZ=altura*(tamanioCaja+separacion);
//
//		// aplico transformacion inicial
//		startTransform.setOrigin(btVector3(btScalar(posX),btScalar(posY),btScalar(posZ)));
//
//		btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
//		btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,fallMotionState,cajaShape,fallInertia);
//
//		cajasRB[k] = new btRigidBody(fallRigidBodyCI);// creo el cuerpo rigido
//
//		cajasRB[k]->setFriction(btScalar(0.1)); // defino factor de friccion
//		dynamicsWorld->addRigidBody(cajasRB[k]); // agrego la caja a la simulacion
//
//		col++;
//		if (col>cantCols-1)	{col=0;row++;}
//		if (row>cantRows-1)   {row=0;col=0;altura++;}
//	}
//	// Defino Esfera
//
//	btCollisionShape* esferaShape = new  btSphereShape(radioEsfera);
//	mass = 10;
//	esferaShape->calculateLocalInertia(mass,fallInertia);
//
//	startTransform.setIdentity();
//	startTransform.setOrigin(btVector3(btScalar(posicionEsferaRB[0]),btScalar(posicionEsferaRB[1]),btScalar(posicionEsferaRB[2])));
//	btDefaultMotionState* esferaMotionState = new btDefaultMotionState(startTransform);
//
//	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI2(mass,esferaMotionState,esferaShape,fallInertia);
//    esferaRB = new btRigidBody(fallRigidBodyCI2);
//	// lo defino  como Kinetic Rigid Body
//
//	esferaRB->setCollisionFlags( esferaRB->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
//	esferaRB->setActivationState(DISABLE_DEACTIVATION);
//
//	dynamicsWorld->addRigidBody(esferaRB);
//
//
//	// Defino Cubo
//
//	btCollisionShape* cuboShape = new  btBoxShape(btVector3(1.0,1.0,1.0));
//	mass = 10;
//	cuboShape->calculateLocalInertia(mass,fallInertia);
//
//	startTransform.setIdentity();
//	startTransform.setOrigin(btVector3(btScalar(posicionCuboRB[0]),btScalar(posicionCuboRB[1]),btScalar(posicionCuboRB[2])));
//	startTransform.setRotation(btQuaternion(btScalar(0),btScalar(0),btScalar(45)));
//	btDefaultMotionState* cuboMotionState = new btDefaultMotionState(startTransform);
//
//	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI3(mass,cuboMotionState,cuboShape,fallInertia);
//    cuboRB = new btRigidBody(fallRigidBodyCI3);
//	cuboRB->setFriction(0.00);
//	dynamicsWorld->addRigidBody(cuboRB);


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
    	  delete castillo;
    	  delete fisica;
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
		  adminCamaras->setCamaraActual( CAMARA_MUNDO );
		  break;
	  case '2':
		  adminCamaras->setCamaraActual( CAMARA_BARCO );
		  break;
	  case '3':
		  adminCamaras->setCamaraActual( CAMARA_CANON );
//		  edit_panelB = !edit_panelB;
//		  glutPostRedisplay();
		  break;
	  case 'r':
		  delete castillo;
//		  castillo = new Castillo(dynamicsWorld);
//		  glutPostRedisplay();

		  fisica->reiniciar();
		  glutPostRedisplay();

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
   initPhysics();

   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glutPassiveMotionFunc(alMover);
   glutMotionFunc(alMoverPresionandoBoton);

   glutIdleFunc(OnIdle);
   glutMainLoop();
   return 0;
}
