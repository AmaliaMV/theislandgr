/*
 * CirculoConTextura.cpp
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#include "CirculoConTextura.h"

CirculoConTextura::CirculoConTextura(string nombreTextura, float radio )
: ODTextura ( new Textura24 ( nombreTextura ) )
{
	this->RADIO = radio;
	this->init( PASO + 1, // +1 por el centro
		PASO + 2, // +1 porq referencio el ppio del circulo dos veces
		GL_TRIANGLE_FAN );
}

CirculoConTextura::~CirculoConTextura() {}

void CirculoConTextura::generarCoordPtos()
{
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	//centro del mirador
	this->ptos[indice++] = 0.0;
	this->ptos[indice++] = 0.0;
	this->ptos[indice++] = 0.0;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->ptos[indice++] = RADIO * Matematica::cosHex( fi );
		this->ptos[indice++] = RADIO * Matematica::sinHex( fi );
		this->ptos[indice++] = 0.0;
	}
}
void CirculoConTextura::generarIndice()
{
	unsigned int indice = 0;

	for ( ; indice < this->getCantTamIndice() - 1; indice++)
	{
		this->indice[indice] = indice;
	}

	this->indice[indice] = 1; // el pto 1 es el primer pto del circulo
}
void CirculoConTextura::generarCoodText()
{
	const float CENTRO = 0.5; // el centro de la textura
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	//centro del mirador
	this->text[indice++] = CENTRO;
	this->text[indice++] = CENTRO;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->text[indice++] = CENTRO + CENTRO * Matematica::cosHex( fi );
		this->text[indice++] = CENTRO + CENTRO * Matematica::sinHex( fi );
	}
}
