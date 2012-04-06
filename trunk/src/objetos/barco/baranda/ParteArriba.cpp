/*
 * ParteArriba.cpp
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#include "ParteArriba.h"

ParteArriba::ParteArriba( Textura* textura, float altura, float longitud, float titaMin, float titaMax, float distancia, int afuera )
	:ODTextura ( textura, true )
{
	this->ALTURA = altura;
	this->LONGITUD = longitud;
	this->DISTANCIA = distancia;
	this->AFUERA = afuera;

	this->TITA_MIN = titaMin;
	this->TITA_MAX = titaMax;

	unsigned int cantPtoH, cantPtoV;
	cantPtoH = CANT_PTOS_LONG + 1;
	cantPtoV = 2;

	this->init( cantPtoH*cantPtoV, cantPtoH*cantPtoV, GL_TRIANGLE_STRIP, true);
}

ParteArriba::~ParteArriba() {}

void ParteArriba::generarCoordPtos()
{
	float incAng;
	const float pasoAng = ( TITA_MAX - TITA_MIN ) / CANT_PTOS_LONG;
	unsigned int pos = 0;

	incAng = this->TITA_MIN;

	for ( unsigned int i = 0; i <= CANT_PTOS_LONG; i++, incAng+=pasoAng )
	{
		ptos[pos++] = (CteBarco::RADIO_X - DISTANCIA) * Matematica::cosHex( incAng );
		ptos[pos++] = (CteBarco::RADIO_Y - DISTANCIA) * Matematica::sinHex( incAng );
		ptos[pos++] = 0;

		ptos[pos++] = (CteBarco::RADIO_X - DISTANCIA) * Matematica::cosHex( incAng );
		ptos[pos++] = (CteBarco::RADIO_Y - DISTANCIA) * Matematica::sinHex( incAng );
		ptos[pos++] = ALTURA * Matematica::modulo( Matematica::sinHex( incAng ) );
	}
}

void ParteArriba::generarIndice()
{
	unsigned int i = 0;

	for ( ; i < 2 * ( CANT_PTOS_LONG + 1 ); i++ )
	{
		indice[i] = i;
	}
}

void ParteArriba::generarCoodText()
{
	const float paso = LONGITUD / CANT_PTOS_LONG, pasoAng = 180 / CANT_PTOS_LONG;
	float inc, incAng;
	unsigned int pos = 0;

	inc = 0;
	incAng = -90;

	for ( unsigned int i = 0; i <= CANT_PTOS_LONG; i++, inc+=paso, incAng+=pasoAng )
	{
		text[pos++] = inc / LONGITUD;
		text[pos++] = 0.5;

		text[pos++] = inc / LONGITUD;
		text[pos++] = Matematica::modulo( Matematica::sinHex( incAng ) );
	}
}

void ParteArriba::generarNormales()
{
	float incAng;
	const float pasoAng = ( TITA_MAX - TITA_MIN ) / CANT_PTOS_LONG;
	unsigned int pos = 0;

	incAng = this->TITA_MIN;

	for ( unsigned int i = 0; i <= CANT_PTOS_LONG; i++, incAng+=pasoAng )
	{
		normales[pos++] = AFUERA * Matematica::cosHex( incAng );
		normales[pos++] = AFUERA * Matematica::sinHex( incAng );
		normales[pos++] = 0.0;

		normales[pos++] = AFUERA * Matematica::cosHex( incAng );
		normales[pos++] = AFUERA * Matematica::sinHex( incAng );
		normales[pos++] = 0.0;
	}
}
