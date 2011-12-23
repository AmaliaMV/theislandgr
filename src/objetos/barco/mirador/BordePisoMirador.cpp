/*
 * BordeMirador.cpp
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#include "BordePisoMirador.h"

BordePisoMirador::BordePisoMirador( string nombreArchivo, float radio, float altura )
	: ODTextura ( new Textura24 ( nombreArchivo ) )
{
	this->RADIO = radio;
	this->ALTURA = altura;

	this->init( PASO * 2, PASO * 2 + 2, GL_TRIANGLE_STRIP );
}

BordePisoMirador::~BordePisoMirador() { }

void BordePisoMirador::generarCoordPtos()
{
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->ptos[indice++] = RADIO * Matematica::cosHex( fi );
		this->ptos[indice++] = RADIO * Matematica::sinHex( fi );
		this->ptos[indice++] = 0.0;
		this->ptos[indice++] = RADIO * Matematica::cosHex( fi );
		this->ptos[indice++] = RADIO * Matematica::sinHex( fi );
		this->ptos[indice++] = ALTURA;
	}
}

void BordePisoMirador::generarIndice()
{
	unsigned int indice = 0;

	for ( ; indice < this->getCantTamIndice() - 2; indice++)
	{
		this->indice[indice] = indice;
	}

	this->indice[indice++] = 0;
	this->indice[indice++] = 1;
}


void BordePisoMirador::generarCoodText()
{
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->text[indice++] = fi / GIRO_COMPLETO;
		this->text[indice++] = 0.0;
		this->text[indice++] = fi / GIRO_COMPLETO;
		this->text[indice++] = 1.0;
	}
}
