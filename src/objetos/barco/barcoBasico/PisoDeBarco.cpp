/*
 * PisoDeBarco.cpp
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#include "PisoDeBarco.h"

const unsigned int PisoDeBarco::cantPasosTita = 20;

PisoDeBarco::PisoDeBarco(string nombreTextura)
	:ODTextura( new Textura24( nombreTextura ) )
{
	this->init( cantPasosTita + 2, cantPasosTita + 2, GL_TRIANGLE_FAN);
}

PisoDeBarco::~PisoDeBarco(){}

void PisoDeBarco::generarCoordPtos()
{
	float tita, pasoTita;
	unsigned int pto = 0;

	pasoTita = ( CteBarco::titaMax - CteBarco::titaMin )/ cantPasosTita;

	ptos [pto    ] = 0.0;
	ptos [pto + 1] = 0.0;
	ptos [pto + 2] = 0.0;

	pto += CteObjeto::CANT_COORD_PTO;

	for ( tita = CteBarco::titaMin; tita <= CteBarco::titaMax; tita += pasoTita, pto += CteObjeto::CANT_COORD_PTO )
	{
		ptos [pto    ] = CteBarco::radioX * Matematica::cosHex( tita );
		ptos [pto + 1] = CteBarco::radioY * Matematica::sinHex( tita );
		ptos [pto + 2] = 0.0;
	}
}

void PisoDeBarco::generarIndice()
{
	unsigned int pto;

	indice [0 ] = 0.0;

	for ( pto = 1; pto < this->getCantPtos(); pto ++ )
		indice [pto] = pto;
}

void PisoDeBarco::generarCoodText()
{
	float tita, pasoTita, centro = 0.5;
	unsigned int pto = 0;

	pasoTita = ( CteBarco::titaMax - CteBarco::titaMin )/ cantPasosTita;

	text [pto    ] = centro;
	text [pto + 1] = centro;

	pto += CteObjeto::CANT_COORD_TEXTURA;

	for ( tita = CteBarco::titaMin; tita <= CteBarco::titaMax; tita += pasoTita, pto += CteObjeto::CANT_COORD_TEXTURA )
	{
		text [pto    ] =  CteBarco::radioX / CteBarco::radioY * Matematica::cosHex( tita ) + centro;
		text [pto + 1] =  Matematica::sinHex( tita ) + centro;
	}
}
