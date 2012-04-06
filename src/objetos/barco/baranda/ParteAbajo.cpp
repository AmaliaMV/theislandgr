/*
 * ParteAbajo.cpp
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#include "ParteAbajo.h"

ParteAbajo::ParteAbajo( Textura *textura, float altura, float longitud, float titaMin, float titaMax, float distancia, int afuera )
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

ParteAbajo::~ParteAbajo() { }

void ParteAbajo::generarCoordPtos()
{
	double tita;
	const double pasoTita = ( TITA_MAX - TITA_MIN ) / CANT_PTOS_LONG;
	unsigned int pos = 0;

	tita = TITA_MIN;

	for ( unsigned int i = 0; i <= CANT_PTOS_LONG; i++, tita+=pasoTita )
	{
		ptos[pos++] = (CteBarco::RADIO_X - DISTANCIA) * Matematica::cosHex( tita );
		ptos[pos++] = (CteBarco::RADIO_Y - DISTANCIA) * Matematica::sinHex( tita );
		ptos[pos++] = -0.01;

		ptos[pos++] = (CteBarco::RADIO_X - DISTANCIA) * Matematica::cosHex( tita );
		ptos[pos++] = (CteBarco::RADIO_Y - DISTANCIA) * Matematica::sinHex( tita );
		ptos[pos++] = ALTURA;
	}
}

void ParteAbajo::generarIndice()
{
	unsigned int i = 0;

	for ( ; i < 2 * (CANT_PTOS_LONG+1); i++ )
	{
		indice[i] = i;
	}
}

void ParteAbajo::generarCoodText()
{
	float inc;
	const float paso = LONGITUD / CANT_PTOS_LONG;
	unsigned int pos = 0;

	inc = 0;

	for ( unsigned int i = 0; i <= CANT_PTOS_LONG; i++, inc+=paso )
	{
		text[pos++] = inc / LONGITUD;
		text[pos++] = 0;

		text[pos++] = inc / LONGITUD;
		text[pos++] = 0.5;
	}
}

void ParteAbajo::generarNormales()
{
	double tita;
	const double pasoTita = ( TITA_MAX - TITA_MIN ) / CANT_PTOS_LONG;
	unsigned int pos = 0;

	tita = TITA_MIN;

	for ( unsigned int i = 0; i <= CANT_PTOS_LONG; i++, tita+=pasoTita )
	{
		normales[pos++] = AFUERA * Matematica::cosHex( tita );
		normales[pos++] = AFUERA * Matematica::sinHex( tita );
		normales[pos++] = 0.0;

		normales[pos++] = AFUERA * Matematica::cosHex( tita );
		normales[pos++] = AFUERA * Matematica::sinHex( tita );
		normales[pos++] = 0.0;
	}
}
