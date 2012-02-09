/*
 * EsferaConTextura.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "EsferaConTextura.h"

const float EsferaConTextura::TITA_MAX = 360.0;
const float EsferaConTextura::FI_MAX = 180.0;
const float EsferaConTextura::DELTA_TITA = 20;
const float EsferaConTextura::DELTA_FI = 20;

EsferaConTextura::EsferaConTextura( string nombreTextura, float radio )
	:ODTextura( new Textura24(nombreTextura) )
{
	this->init( radio );
}

EsferaConTextura::EsferaConTextura( Textura* textura, float radio )
	:ODTextura( textura, true )
{
	this->init( radio );
}

void EsferaConTextura::init( float radio )
{
	RADIO = radio;
	cantPtosX = floor(DELTA_TITA) + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = floor(DELTA_FI) + 1;

	ODTextura::init( cantPtosX * cantPtosY, (cantPtosY-1)*cantPtosX*2, GL_TRIANGLE_STRIP);
}

EsferaConTextura::~EsferaConTextura() {}


void EsferaConTextura::generarCoordPtos()
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

void EsferaConTextura::generarIndice()
{
	unsigned int posPto = 0;

	for (unsigned int posIndice = 0; posIndice < this->getCantTamIndice(); posPto += CteObjeto::CANT_COORD_PTO)
	{
		indice[posIndice++] = posPto / 3;
		indice[posIndice++] = posPto/3 + cantPtosX; // el siguiente pto ya q usamos triangle strip
	}
}

void EsferaConTextura::generarCoodText()
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



