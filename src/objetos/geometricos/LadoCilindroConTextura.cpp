/*
 * CilindroConTextura.cpp
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#include "LadoCilindroConTextura.h"

LadoCilindroConTextura::LadoCilindroConTextura( string nombreTextura, float radio, float altura )
	: ODTextura ( new Textura24 ( nombreTextura ) )
{
	this->RADIO = radio;
	this->ALTURA = altura;

	this->init( PASO * 2,  PASO * 2 + 2, GL_TRIANGLE_STRIP, true );
}

LadoCilindroConTextura::~LadoCilindroConTextura() {}

void LadoCilindroConTextura::generarNormales()
{
	unsigned int indice = 0;
	float fi, pasoFi;

	pasoFi = GIRO_COMPLETO / PASO;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		this->normales[indice++] = Matematica::cosHex( fi );
		this->normales[indice++] = Matematica::sinHex( fi );
		this->normales[indice++] = 0.0;
		this->normales[indice++] = Matematica::cosHex( fi );
		this->normales[indice++] = Matematica::sinHex( fi );
		this->normales[indice++] = 0.0;
	}
}

void LadoCilindroConTextura::generarCoordPtos()
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
void LadoCilindroConTextura::generarIndice()
{
	unsigned int indice = 0;

	for ( ; indice < this->getCantTamIndice() - 2; indice++)
	{
		this->indice[indice] = indice;
	}

	this->indice[indice++] = 0;
	this->indice[indice++] = 1;
}
void LadoCilindroConTextura::generarCoodText()
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

void LadoCilindroConTextura::displayList() const
{
	glColor3f(1.0, 1.0, 1.0);
	ODTextura::displayList();
}

float LadoCilindroConTextura::getAltura() const
{
	return this->ALTURA;
}

float LadoCilindroConTextura::getRadio() const
{
	return this->RADIO;
}
