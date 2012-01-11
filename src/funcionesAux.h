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

#include "camaras/AdminCamaras.h"
#include "camaras/CamaraMundo.h"
#include "camaras/CamaraBarco.h"
#include "camaras/CamaraCanon.h"

#include "paneles/MCmdJuegos.h"

#include <iostream>
using namespace std;

Mundo *mundo;
MCmdJuegos *mCmd;
AdminCamaras *adminCamaras;
IMouse *mouse = new Mouse();
unsigned int camActual = 2;

float eyeX=0, eyeY=0, eyeZ=0, atX=0, atY=0, atZ=0;

// Variables que controlan la ubicación de la cámara en la Escena 3D
float eye[3] = {5.0, 10.0, 8.0};
float at[3]  = { 0.0,  0.0, 0.0};
float up[3]  = { 0.0,  0.0, 1.0};

// Tamaño de la ventana
GLfloat window_size[2];
#define W_WIDTH window_size[0]
#define W_HEIGHT window_size[1]

#define TOP_VIEWB_POSX	((int)((float)W_WIDTH*0.60f))
#define TOP_VIEWB_W		((int)((float)W_WIDTH*0.40f))
#define TOP_VIEWB_POSY	((int)((float)W_HEIGHT*0.20f))
#define TOP_VIEWB_H		((int)((float)W_HEIGHT*0.40f))


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

void actualizarVista()
{
	//seteo la camara actual
	((Mouse*)mouse)->setCamara(adminCamaras->getCamaraActual()); // esto no deberia hacerse una vez por cambio de camara?

	adminCamaras->actualizarVista();
//	glPushMatrix();
//		glBegin( GL_LINE );
//		glVertex3f(camaras[camActual]->getEye()[0], camaras[camActual]->getEye()[1], camaras[camActual]->getEye()[2]);
//		glVertex3f(camaras[camActual]->getAt()[0], camaras[camActual]->getAt()[1],camaras[camActual]->getAt()[2]);
//
//
//	glPopMatrix();
}

#endif /* FUNCIONESAUX_H_ */
