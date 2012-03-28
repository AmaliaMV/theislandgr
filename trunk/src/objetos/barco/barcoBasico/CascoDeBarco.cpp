/*
 * CascoDeBarco.cpp
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#include "CascoDeBarco.h"

const int CascoDeBarco::cantPasosFi 	= 20.0;
const int CascoDeBarco::cantPasosTita 	= 20.0;

CascoDeBarco::CascoDeBarco( string nombreTextura ):ODTextura( new Textura24( nombreTextura ) )
{
	unsigned int cantPtosX, cantPtosY;

	cantPtosX = cantPasosTita + 1; // el +1 es porq cuento los extremos dos veces, por el <=
	cantPtosY = cantPasosFi + 1;

	this->init( cantPtosX * cantPtosY,
			(cantPtosY-1) * cantPtosX * 2,
			GL_TRIANGLE_STRIP, true );
}

/* es un elipsoide */
void CascoDeBarco::generarCoordPtos()
{
	float tita, fi, pasoFi, pasoTita;
	unsigned int pto = 0;

	pasoFi = ( CteBarco::FI_MAX - CteBarco::FI_MIN ) / cantPasosFi;
	pasoTita = ( CteBarco::TITA_MAX - CteBarco::TITA_MIN )/ cantPasosTita;

	for ( fi = CteBarco::FI_MIN; fi <= CteBarco::FI_MAX; fi+= pasoFi )
	{
		for ( tita = CteBarco::TITA_MIN; tita <= CteBarco::TITA_MAX; tita += pasoTita, pto += CteObjeto::CANT_COORD_PTO )
		{
			ptos [pto    ] = CteBarco::RADIO_X * Matematica::cosHex( fi ) * Matematica::cosHex( tita );
			ptos [pto + 1] = CteBarco::RADIO_Y * Matematica::cosHex( fi ) * Matematica::sinHex( tita );
			ptos [pto + 2] = CteBarco::RADIO_Z * Matematica::sinHex( fi );
		}
	}
}

void CascoDeBarco::generarIndice()
{
	unsigned int posPto = 0;
	unsigned int ptosPorFila = cantPasosTita + 1;

	for (unsigned int posIndice = 0; posIndice < this->getCantTamIndice(); posIndice += 2, posPto += CteObjeto::CANT_COORD_PTO)
	{
		indice[posIndice] = posPto / 3;
		indice[posIndice+1] = posPto / 3 + ptosPorFila; // el siguiente pto ya q usamos triangle strip
	}
}

void CascoDeBarco::generarCoodText()
{
	unsigned int indice = 0, repetir = 3, cantFila = cantPasosTita + 1, cantColum = cantPasosFi + 1;

	for (unsigned int fil = 0 ; fil < cantFila; fil ++)
	{
		for (unsigned int col = 0 ; col < cantColum; col ++)
		{
			text[indice    ] = (float) fil / cantFila ;
			text[indice + 1] = repetir * (float) col / cantColum ;
			indice += 2;
		}
	}
}

void CascoDeBarco::generarNormales()
{
	float tita, fi, pasoFi, pasoTita;
	unsigned int pto = 0;

	pasoFi = ( CteBarco::FI_MAX - CteBarco::FI_MIN ) / cantPasosFi;
	pasoTita = ( CteBarco::TITA_MAX - CteBarco::TITA_MIN )/ cantPasosTita;

	for ( fi = CteBarco::FI_MIN; fi <= CteBarco::FI_MAX; fi+= pasoFi )
	{
		for ( tita = CteBarco::TITA_MIN; tita <= CteBarco::TITA_MAX; tita += pasoTita, pto += CteObjeto::CANT_COORD_PTO )
		{
			normales[pto    ] = Matematica::cosHex( fi ) * Matematica::cosHex( tita );
			normales[pto + 1] = Matematica::cosHex( fi ) * Matematica::sinHex( tita );
			normales[pto + 2] = Matematica::sinHex( fi );
		}
	}
}
CascoDeBarco::~CascoDeBarco() { }
