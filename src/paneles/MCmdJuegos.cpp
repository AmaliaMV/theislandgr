/*
 * MCmdJuegos.cpp
 *
 *  Created on: 10/01/2012
 *      Author: amalia
 */

#include "MCmdJuegos.h"

const float MCmdJuegos::MARGEN_IZQUIERDO = 190.0;
const float MCmdJuegos::MARGEN_SUPERIOR = 145.0;
const float MCmdJuegos::SEPARACION_RENGLONES = 38.0;

MCmdJuegos::MCmdJuegos( const string nomTextMenu ): Panel()
{
	menu = new RectanguloConTextura32 ( nomTextMenu, 2.0, 2.0 );
	anchoImagen = 0.0;
	altoImagen = 0.0;
	mostrar = false;
	this->descripciones = NULL;
}

MCmdJuegos::~MCmdJuegos()
{
	delete menu;

	if (this->descripciones != NULL)
		delete this->descripciones;
}

void MCmdJuegos::setDescripcionComando( list<string> *descripciones )
{
	this->descripciones = descripciones;
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
	list<string>::iterator it = this->descripciones->begin();
	float delta = altoImagen - MARGEN_SUPERIOR;
	unsigned int tam = 0;

	glDisable(GL_LIGHTING);

	//	gluLookAt (0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 0.0);

	if (this->descripciones != NULL)
	{
		for (; tam < this->descripciones->size() / 2 + 1; tam++, it++, delta-= SEPARACION_RENGLONES)
		{
			glRasterPos2f( -anchoImagen + MARGEN_IZQUIERDO, delta );
			this->escribir((*it).c_str());
		}

		delta = altoImagen - MARGEN_SUPERIOR;

		for (; it != this->descripciones->end(); it++, delta-= SEPARACION_RENGLONES)
		{
			glRasterPos2f( 40.0 , delta );
			this->escribir((*it).c_str());
		}

		glRasterPos2f( 40.0 , delta );
		this->escribir("q - Salir");
	}

	glPushMatrix();
		glScalef( anchoImagen, altoImagen, 1.0 );
		menu->dibujar();//fondo
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

const bool MCmdJuegos::seVe() const
{
	return this->mostrar;
}
