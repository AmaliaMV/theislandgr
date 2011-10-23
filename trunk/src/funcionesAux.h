/*
 * funcionesAux.h
 *
 *  Created on: 15/05/2011
 *      Author: Amalia
 */

#ifndef FUNCIONESAUX_H_
#define FUNCIONESAUX_H_

#include "mouse/Mouse.h"
#include "camaras/CamaraMundo.h"
#include <iostream>
using namespace std;

Camara *camaras[] = {new CamaraMundo()};
IMouse *mouse = new Mouse();
unsigned int camActual = 0;



// Variables que controlan la ubicación de la cámara en la Escena 3D
float eye[3] = {5.0, 10.0, 8.0};
float at[3]  = { 0.0,  0.0, 0.0};
float up[3]  = { 0.0,  0.0, 1.0};

// Tamaño de la ventana
GLfloat window_size[2];
#define W_WIDTH window_size[0]
#define W_HEIGHT window_size[1]

#define TOP_VIEWA_POSX	((int)((float)W_WIDTH*0.60f))
#define TOP_VIEWA_W		((int)((float)W_WIDTH*0.40f))
#define TOP_VIEWA_POSY	((int)((float)W_HEIGHT*0.60f))
#define TOP_VIEWA_H		((int)((float)W_HEIGHT*0.40f))

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
	((Mouse*)mouse)->setCamara(camaras [camActual]);
	camaras[camActual]->setEye();
	camaras[camActual]->setAt();

	gluLookAt (camaras[camActual]->getEye()[0],
				camaras[camActual]->getEye()[1],
				camaras[camActual]->getEye()[2],
				camaras[camActual]->getAt()[0],
				camaras[camActual]->getAt()[1],
				camaras[camActual]->getAt()[2],
				camaras[camActual]->getUp()[0],
				camaras[camActual]->getUp()[1],
				camaras[camActual]->getUp()[2]);
}

#endif /* FUNCIONESAUX_H_ */
