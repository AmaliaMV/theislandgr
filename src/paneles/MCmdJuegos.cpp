/*
 * MCmdJuegos.cpp
 *
 *  Created on: 10/01/2012
 *      Author: amalia
 */

#include "MCmdJuegos.h"

MCmdJuegos::MCmdJuegos( string nomTextMenu  ): Panel()
{
	menu = new RectanguloConTextura ( nomTextMenu, 2.0, 2.0 );
	anchoImagen = 0.0;
	altoImagen = 0.0;
	mostrar = false;
}

MCmdJuegos::~MCmdJuegos()
{
	delete menu;
}

void MCmdJuegos::setPanel()
{
	float TOP_VIEW_POSX = TamanoPantalla::getAncho() * 0.10,
				TOP_VIEW_W = TamanoPantalla::getAncho() * 0.80,
				TOP_VIEW_POSY = TamanoPantalla::getAlto() * 0.10,
				TOP_VIEW_H = TamanoPantalla::getAlto() * 0.80;

	this->setDimensiones( TOP_VIEW_POSX, TOP_VIEW_POSY, TOP_VIEW_W , TOP_VIEW_H );
	this->setEscalaReferencia( -TOP_VIEW_W / 2, TOP_VIEW_W / 2, -TOP_VIEW_H / 2, TOP_VIEW_H / 2 );

	Panel::setPanel();

	anchoImagen = TOP_VIEW_W / 2;
	altoImagen = TOP_VIEW_H / 2;
}

void MCmdJuegos::dibujarFondo()
{
//	gluLookAt (0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glDisable(GL_LIGHTING);
	glPushMatrix();
		glScalef( anchoImagen, altoImagen, 1.0 );
		menu->dibujar();
	glPopMatrix();


	glEnable(GL_LIGHTING);
}

void MCmdJuegos::dibujar()
{
	if ( mostrar == true )
		Panel::dibujar();
}

void MCmdJuegos::modificarMostrar()
{
	this->mostrar = !this->mostrar;
}
