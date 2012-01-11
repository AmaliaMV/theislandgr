/*
 * RectanguloConTextura.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "RectanguloConTextura.h"

RectanguloConTextura::RectanguloConTextura( string nombreTextura, float base, float altura )
	:ODTextura (new Textura24(nombreTextura) )
{
	this->BASE = base;
	this->ALTURA = altura;

	this->init(4, 4, GL_TRIANGLE_STRIP);
}

RectanguloConTextura::~RectanguloConTextura() {}

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
	text[0] = 0.0;
	text[1] = 1.0;

	text[2] = 0.0;
	text[3] = 0.0;

	text[4] = 1.0;
	text[5] = 1.0;

	text[6] = 1.0;
	text[7] = 0.0;
}

float RectanguloConTextura::getBase() const
{
	return this->BASE;
}

float RectanguloConTextura::getAltura() const
{
	return this->ALTURA;
}
