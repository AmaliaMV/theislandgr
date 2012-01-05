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

	this->init( cantPtosX * cantPtosY, (cantPtosY-1)*cantPtosX*2, GL_TRIANGLE_STRIP);
}

Cielo::~Cielo() {}

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
	unsigned int posPto = 0;

	for (unsigned int posIndice = 0; posIndice < this->getCantTamIndice(); posPto += CteObjeto::CANT_COORD_PTO)
	{
		indice[posIndice++] = posPto / 3;
		indice[posIndice++] = posPto/3 + cantPtosX; // el siguiente pto ya q usamos triangle strip
	}
}

void Cielo::generarCoodText()
{
	float pasoX, pasoY;
	unsigned int indice;

	pasoX = 1.0 / cantPtosX;
	pasoY = 1.0 / cantPtosY;

	for (unsigned int col = 0 ; col < cantPtosY; col ++)
	{
		for (unsigned int fil = 0 ; fil < cantPtosX; fil ++)
		{
			indice = fil * CteObjeto::CANT_COORD_TEXTURA + col * cantPtosX * CteObjeto::CANT_COORD_TEXTURA;
			text[indice] = pasoX * fil;
			text[indice + 1] = pasoY * col;
		}
	}
}
