/*
 * LadoPrismaConTextura.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "LadoPrismaConTextura.h"

LadoPrismaConTextura::LadoPrismaConTextura(string nombreTextura, float altura, float ancho, float largo)
	: ODTextura ( new Textura24(nombreTextura) )
{
	this->ALTURA = altura;
	this->ANCHO = ancho;
	this->LARGO = largo;

	this->init( 10, 10, GL_TRIANGLE_STRIP );
}

LadoPrismaConTextura::~LadoPrismaConTextura() {}

void LadoPrismaConTextura::generarCoordPtos()
{
	unsigned int pos = 0;

	for ( float ancho = -ANCHO/2; ancho <= ANCHO/2; ancho+=ANCHO )
		for ( float largo = -LARGO/2; largo <= LARGO/2; largo+=LARGO)
			for ( float altura = -ALTURA/2; altura <= ALTURA/2; altura+=ALTURA )
			{
				ptos[pos++] = largo;
				ptos[pos++] = ancho;
				ptos[pos++] = altura;
			}

	// pto 1
	ptos[pos++] = -LARGO/2;
	ptos[pos++] = -ANCHO/2;
	ptos[pos++] = -ALTURA/2;

	// pto 5
	ptos[pos++] = -LARGO/2;
	ptos[pos++] = -ANCHO/2;
	ptos[pos++] = ALTURA/2;
}

void LadoPrismaConTextura::generarIndice()
{
	unsigned int pos = 0;

	for (; pos < 4; pos++)
	{
		indice[pos  ] = pos;
	}

	indice[pos++] = 6;
	indice[pos++] = 7;

	indice[pos++] = 4;
	indice[pos++] = 5;

	indice[pos++] = 8;
	indice[pos] = 9;
}

void LadoPrismaConTextura::generarCoodText()
{
	unsigned int pos = 0;
	float largoTotal = 2* ALTURA + 2*ANCHO, deltaAncho = ANCHO/largoTotal,
			deltaLargo = ALTURA/largoTotal;

	//para el pto 0 y 4
	text[pos++] = 0.0;
	text[pos++] = 0.0;
	text[pos++] = 0.0;
	text[pos++] = 1.0;

	//para el pto 1 y 5
	text[pos++] = deltaLargo;
	text[pos++] = 0.0;
	text[pos++] = deltaLargo;
	text[pos++] = 1.0;

	//para el pto 3 y 7
	text[pos++] = 2*deltaLargo + deltaAncho;
	text[pos++] = 0.0;
	text[pos++] = 2*deltaLargo + deltaAncho;
	text[pos++] = 1.0;

	//para el pto 2 y 6
	text[pos++] = deltaLargo + deltaAncho;
	text[pos++] = 0.0;
	text[pos++] = deltaLargo + deltaAncho;
	text[pos++] = 1.0;

	//para el pto 0 y 4 de nuevo
	text[pos++] = 1.0;
	text[pos++] = 0.0;
	text[pos++] = 1.0;
	text[pos++] = 1.0;
}

float LadoPrismaConTextura::getAltura() const
{
	return this->ALTURA;
}

float LadoPrismaConTextura::getAncho() const
{
	return this->ANCHO;
}
float LadoPrismaConTextura::getLargo() const
{
	return this->LARGO;
}
