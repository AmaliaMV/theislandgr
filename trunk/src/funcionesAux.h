/*
 * funcionesAux.h
 *
 *  Created on: 15/05/2011
 *      Author: Amalia
 */

#ifndef FUNCIONESAUX_H_
#define FUNCIONESAUX_H_

#include "mouse/Mouse.h"
#include "objetos/Mundo.h"

#include "comandos/AdminComandos.h"
#include "comandos/VerCamaraMundo.h"
#include "comandos/VerCamaraCastillo.h"
#include "comandos/VerCamaraCanon.h"
#include "comandos/VerCamaraBarco.h"
#include "comandos/Pausar.h"
#include "comandos/LanzarBomba.h"

#include "camaras/CamaraMundo.h"
#include "camaras/CamaraBarco.h"
#include "camaras/CamaraCanon.h"
#include "camaras/CamaraCastillo.h"


#include "paneles/MCmdJuegos.h"
#include "paneles/Dimensiones.h"

#include <iostream>
using namespace std;

Mundo *mundo;
MCmdJuegos *mCmd;
AdminCamaras *adminCamaras;
AdminComandos *adminComandos;
IMouse *mouse;
static const string archivoDeConfiguracion = "archivosNivel1";

float eyeX=0, eyeY=0, eyeZ=0, atX=0, atY=0, atZ=0;

#define TOP_VIEWB_POSX	((int)((float)W_WIDTH*0.60f))
#define TOP_VIEWB_W		((int)((float)W_WIDTH*0.40f))
#define TOP_VIEWB_POSY	((int)((float)W_HEIGHT*0.20f))
#define TOP_VIEWB_H		((int)((float)W_HEIGHT*0.40f))

void inicializar()
{
	try
	{
		mouse = new Mouse();
		mundo = new Mundo( archivoDeConfiguracion );

		adminCamaras = new AdminCamaras();

		adminCamaras->agregarCamara( CAMARA_MUNDO, new CamaraMundo() );
		adminCamaras->agregarCamara( CAMARA_BARCO, new CamaraBarco(mundo->getTBarco()) );
		adminCamaras->agregarCamara( CAMARA_CANON, new CamaraCanon(mundo->getTBarco(), mundo->getBarco()->getTCanon()) );
		adminCamaras->agregarCamara( CAMARA_CASTILLO, new CamaraCastillo() );
		adminCamaras->setCamaraActual( CAMARA_MUNDO );

		adminComandos = new AdminComandos();
		adminComandos->agregarComando('1', new VerCamaraMundo(adminCamaras));
		adminComandos->agregarComando('2', new VerCamaraBarco(adminCamaras));
		adminComandos->agregarComando('3', new VerCamaraCanon(adminCamaras));
		adminComandos->agregarComando('4', new VerCamaraCastillo(adminCamaras));
		adminComandos->agregarComando('p', new Pausar(mundo));
		adminComandos->agregarComando('j', new LanzarBomba(mundo));


		mCmd = new MCmdJuegos("texturas/menu_comandos.bmp");
	}

	catch ( EArchivoInexistente *e )
	{
		cout<< e->what() <<endl;
		exit(1);
	}
	catch ( ECamara*e )
	{
		cout<< e->what() <<endl;
		exit(1);
	}
	catch ( EComando*e )
	{
		cout<< e->what() <<endl;
		exit(1);
	}
}

void reshape (int w, int h)
{
	TamanoPantalla::setAlto(h);
	TamanoPantalla::setAncho(w);
}

void alMoverPresionandoBoton ( int xMouse, int yMouse )
{
	mouse->alMoverPresionandoBoton( xMouse, yMouse);
}
void alMover ( int xMouse, int yMouse )
{
	mouse->alMover( xMouse, yMouse);
}
void alPresionarBoton ( int button, int state, int xMouse, int yMouse )
{
}

void dibujar3D()
{
	glDisable(GL_LIGHTING);
		glColor3f(1.0, 1.0, 1.0);
		mundo->dibujar();
	glEnable(GL_LIGHTING);
}

void OnIdle (void)
{
	mundo->actualizar();
	glutPostRedisplay();
}

void actualizarVista()
{
	//seteo la camara actual
	((Mouse*)mouse)->setCamara(adminCamaras->getCamaraActual()); // esto no deberia hacerse una vez por cambio de camara?

	adminCamaras->actualizarVista();
}

#endif /* FUNCIONESAUX_H_ */
