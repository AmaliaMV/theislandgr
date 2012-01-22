/*
 * RectanguloConTextura.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "RectanguloConTextura.h"

RectanguloConTextura::RectanguloConTextura( string nombreTextura, float base, float altura, Coord_text *coord_text )
	:ODTextura (new Textura24(nombreTextura) )
{
	this->BASE = base;
	this->ALTURA = altura;
	this->coord_text = coord_text;

	this->init(4, 4, GL_TRIANGLE_STRIP);
}

RectanguloConTextura::RectanguloConTextura( Textura* textura, float base, float altura, Coord_text *coord_text )
	:ODTextura ( textura, true )
{
	this->BASE = base;
	this->ALTURA = altura;
	this->coord_text = coord_text;

	this->init(4, 4, GL_TRIANGLE_STRIP);
}
RectanguloConTextura::~RectanguloConTextura()
{
	delete this->coord_text;
}

void RectanguloConTextura::generarCoordPtos()
{
	unsigned int pos = 0;

	for ( float y = -BASE/2; y < BASE; y+=BASE )
		for ( float x = -ALTURA/2; x < ALTURA; x+=ALTURA )
		{
			ptos[pos++] = x;
			ptos[pos++] = y;
			ptos[pos++] = 0.0;
		}
}

void RectanguloConTextura::generarIndice()
{
	for ( unsigned int pos = 0; pos < 4; pos++)
		indice[pos] = pos;
}

void RectanguloConTextura::generarCoodText()
{
	text[0] = this->coord_text->xmin;
	text[1] = this->coord_text->ymax;

	text[2] = this->coord_text->xmin;
	text[3] = this->coord_text->ymin;

	text[4] = this->coord_text->xmax;
	text[5] = this->coord_text->ymax;

	text[6] = this->coord_text->xmax;
	text[7] = this->coord_text->ymin;
}

float RectanguloConTextura::getBase() const
{
	return this->BASE;
}

float RectanguloConTextura::getAltura() const
{
	return this->ALTURA;
}
