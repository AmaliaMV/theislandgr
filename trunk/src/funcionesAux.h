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
#include "comandos/Reiniciar.h"
#include "comandos/LanzarBomba.h"
#include "comandos/MoverCanonAbajo.h"
#include "comandos/MoverCanonArriba.h"
#include "comandos/MoverCanonDerecha.h"
#include "comandos/MoverCanonIzquierda.h"
#include "comandos/AcercarCamara.h"
#include "comandos/AlejarCamara.h"
#include "comandos/VerMenuComandos.h"

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

void inicializar()
{
	try
	{
		mouse = new Mouse();
		mundo = new Mundo( archivoDeConfiguracion );
		mCmd = new MCmdJuegos("texturas/pergamino.bmp");

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
		adminComandos->agregarComando('a', new AlejarCamara(adminCamaras));
		adminComandos->agregarComando('s', new AcercarCamara(adminCamaras));
		adminComandos->agregarComando('p', new Pausar(mundo));
		adminComandos->agregarComando('r', new Reiniciar(mundo));
		adminComandos->agregarComando('y', new MoverCanonArriba(mundo->getBarco()->getCanon()));
		adminComandos->agregarComando('b', new MoverCanonAbajo(mundo->getBarco()->getCanon()));
		adminComandos->agregarComando('h', new MoverCanonDerecha(mundo->getBarco()->getCanon()));
		adminComandos->agregarComando('g', new MoverCanonIzquierda(mundo->getBarco()->getCanon()));
		adminComandos->agregarComando('j', new LanzarBomba(mundo));
		adminComandos->agregarComando('m', new VerMenuComandos(mCmd, mundo));

		mCmd->setDescripcionComando( adminComandos->getDescripcion());
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

void keyboard (unsigned char key, int x, int y)
{
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
}

void dibujar3D()
{
	mundo->dibujar();
}

void OnIdle (void)
{
	mundo->actualizar();
	glutPostRedisplay();
}

#endif /* FUNCIONESAUX_H_ */
