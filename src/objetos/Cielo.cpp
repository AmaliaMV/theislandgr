/*
 * Cielo.cpp
 *
 *  Created on: 17/09/2011
 *      Author: amalia
 */

#include "Cielo.h"

const float Cielo::TITA_MAX = 360.0;
const float Cielo::FI_MAX = 90.0;
const float Cielo::DELTA_TITA = 20;
const float Cielo::DELTA_FI = 20;

Cielo::Cielo( string nombreTextura, float radio )
	: ODTextura( new Textura24( nombreTextura ) )
{
	RADIO = radio;
	cantPtosX = floor(DELTA_TITA) + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = floor(DELTA_FI) + 1;

	this->inicializarLuz();
	this->init(cantPtosX * cantPtosY, (cantPtosY-1)*(cantPtosX)*2, GL_TRIANGLE_STRIP);
}

Cielo::~Cielo()
{
 	 this->eliminarLuz();
}

void Cielo::generarCoordPtos()
{
	float titaAvance, fiAvance;
	unsigned int posPto = 0;

	titaAvance = TITA_MAX / DELTA_TITA;
	fiAvance = FI_MAX / DELTA_FI;

	for (float fi = 0 ; fi <= FI_MAX; fi += fiAvance)
	{
		for (float tita = 0 ; tita <= TITA_MAX; tita += titaAvance)
		{
			ptos[ posPto++ ] = RADIO * Matematica::cosHex ( tita ) * Matematica::sinHex ( fi );
			ptos[ posPto++ ] = RADIO * Matematica::sinHex ( tita ) * Matematica::sinHex ( fi );
			ptos[ posPto++ ] = RADIO * Matematica::cosHex ( fi );
		}
	}
}

void Cielo::generarIndice()
{
	unsigned int posIndice = 0;

	for (unsigned int fil = 0 ; fil < cantPtosY - 1; fil ++)
	{
		for (unsigned int col = 0 ; col < cantPtosX; col ++)
		{
			indice[posIndice++] = col + fil * cantPtosY;
			indice[posIndice++] = col + (fil + 1) * cantPtosY;
		}
	}
}

void Cielo::generarCoodText()
{
	float pasoX, pasoY;
	unsigned int indice = 0;

	pasoX = 1.0 / (cantPtosX-1);
	pasoY = 1.0 / (cantPtosY-1);

	for (unsigned int col = 0 ; col < cantPtosX; col ++)
	{
		for (unsigned int fil = 0 ; fil < cantPtosY; fil ++)
		{
			text[indice++] = pasoY * col;
			text[indice++] = pasoX * fil;
		}
	}
}

void Cielo::displayList() const
{
	glColor3f(0.82, 0.96, 0.98);
	glNormal3f(sqrt(2)/2, 0, sqrt(2)/2);
	this->luz->setPropiedadesMaterial();
	ODTextura::displayList();
}


void Cielo::inicializarLuz()
{
	this->luz = new IluminacionMaterial(0.8, 0.8, 0.8);
	this->luz->setBrillo(10);
}

void Cielo::eliminarLuz()
{
	delete luz;
}
