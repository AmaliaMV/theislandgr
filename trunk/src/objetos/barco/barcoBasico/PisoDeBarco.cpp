/*
 * PisoDeBarco.cpp
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#include "PisoDeBarco.h"

const unsigned int PisoDeBarco::cantPasosTita = 20;

PisoDeBarco::PisoDeBarco(const string nombreTextura)
	:ODTextura( new Textura24( nombreTextura ) )
{
	this->inicializarLuces();
	this->init( cantPasosTita + 2, cantPasosTita + 2, GL_TRIANGLE_FAN);
}

PisoDeBarco::~PisoDeBarco()
{
	this->eliminarLuces();
}

void PisoDeBarco::displayList() const
{
	glNormal3f(0.0, 0.0, 1.0);
	glColor3f(1.0, 1.0, 1.0);
	this->luz->setPropiedadesMaterial();
	ODTextura::displayList();
}

void PisoDeBarco::generarCoordPtos()
{
	float tita, pasoTita;
	unsigned int pto = 0;

	pasoTita = ( CteBarco::TITA_MAX - CteBarco::TITA_MIN )/ cantPasosTita;

	ptos [pto    ] = 0.0;
	ptos [pto + 1] = 0.0;
	ptos [pto + 2] = 0.0;

	pto += CteObjeto::CANT_COORD_PTO;

	for ( tita = CteBarco::TITA_MIN; tita <= CteBarco::TITA_MAX; tita += pasoTita, pto += CteObjeto::CANT_COORD_PTO )
	{
		ptos [pto    ] = CteBarco::RADIO_X * Matematica::cosHex( tita );
		ptos [pto + 1] = CteBarco::RADIO_Y * Matematica::sinHex( tita );
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

	pasoTita = ( CteBarco::TITA_MAX - CteBarco::TITA_MIN )/ cantPasosTita;

	text [pto    ] = centro;
	text [pto + 1] = centro;

	pto += CteObjeto::CANT_COORD_TEXTURA;

	for ( tita = CteBarco::TITA_MIN; tita <= CteBarco::TITA_MAX; tita += pasoTita, pto += CteObjeto::CANT_COORD_TEXTURA )
	{
		text [pto    ] =  CteBarco::RADIO_X / CteBarco::RADIO_Y * Matematica::cosHex( tita ) + centro;
		text [pto + 1] =  Matematica::sinHex( tita ) + centro;
	}
}

void PisoDeBarco::inicializarLuces()
{
	this->luz = new IluminacionMaterial(0.85, 0.56, 0.0);
	this->luz->setBrillo(18);
}

void PisoDeBarco::eliminarLuces()
{
	delete this->luz;
}
