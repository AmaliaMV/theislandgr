/*
 * Palo.cpp
 *
 *  Created on: 28/11/2011
 *      Author: amalia
 */

#include "Palo.h"

Palo::Palo( string nombreTextura, float altura, float radioSuperior, float radioInferior,
		EstrategiaTransformacion* transformacion, ComponenteBarco* aDecorar )
	: ODTextura( new Textura24( nombreTextura ) ),
	  DecoradorBarco ( transformacion, aDecorar)
{
	this->ALTURA = altura;
	this->RADIO_SUPERIOR = radioSuperior;
	this->RADIO_INFERIOR = radioInferior;

	this->init( PASO * 2, PASO * 2 + 2, GL_TRIANGLE_STRIP );
}

Palo::~Palo() { }

void Palo::generarCoordPtos()
{
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->ptos[indice++] = RADIO_SUPERIOR * Matematica::cosHex( fi );
		this->ptos[indice++] = RADIO_SUPERIOR * Matematica::sinHex( fi );
		this->ptos[indice++] = 0.0;
		this->ptos[indice++] = RADIO_INFERIOR * Matematica::cosHex( fi );
		this->ptos[indice++] = RADIO_INFERIOR * Matematica::sinHex( fi );
		this->ptos[indice++] = this->ALTURA;
	}
}

void Palo::generarIndice()
{
	unsigned int indice = 0;

	for ( ; indice < this->getCantTamIndice() - 2 ; indice ++ )
	{
		this->indice[indice] = indice ;
	}

	this->indice[indice++] = 0 ;
	this->indice[indice] = 1 ;
}
void Palo::generarCoodText()
{
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->text[indice++] = fi / GIRO_COMPLETO ;
		this->text[indice++] = 0.0 ;
		this->text[indice++] = fi / GIRO_COMPLETO;
		this->text[indice++] = 1.0 ;
	}
}
void Palo::dibujar()
{
	ODTextura::dibujar();
}
