/*
 * BordeBSpline.cpp
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#include "BordeBSpline.h"

BordeBSpline::BordeBSpline( PuntosControl *ptos, const unsigned int cantNivelesHorizontal, const float escaladoXY, const float escaladoZ , const float pendiente, const float alturaEntreNiveles )
{
	this->curva = new BSplineCerrada ( ptos );
	this->ptosHorizontales = this->curva->getCantCurvas() * ( CteIsla::PASO_BARRIDO + 1 );
	this->ptosVerticales = cantNivelesHorizontal;
	this->PENDIENTE = pendiente;
	this->ESCALADOxy = escaladoXY;
	this->ESCALADOz = escaladoZ;
	this->ALTURA_ENTRE_NIVELES = alturaEntreNiveles;
}

unsigned int* BordeBSpline::generarIndice() const
{
	unsigned int pos, posFila, posColumna;
	unsigned int* vectIndice = new unsigned int [ this->getCantReferencias() ];

	pos = 0;

	for ( posFila = 0; posFila < ptosVerticales - 1 ; posFila++ )
	{
		for ( posColumna = 0 ; posColumna < ptosHorizontales; posColumna++, pos+= 2 )
		{
			vectIndice[pos    ] = posColumna + ptosHorizontales * posFila;
			vectIndice[pos + 1] = posColumna + ptosHorizontales * ( posFila + 1);
		}

		vectIndice[pos    ] = ptosHorizontales * posFila;
		vectIndice[pos + 1] = ptosHorizontales * ( posFila + 1);
		pos += 2;
	}

	return vectIndice;
}

float* BordeBSpline::generarCoorText() const
{
	unsigned int curvaNum, ptoNum, pos;
	float incY, valorTextY;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];
	int nivel;
	float *	coordText = new float [ this->getCantPtos() * CteObjeto::CANT_COORD_TEXTURA ];

	incY = 0.70 / ( ptosVerticales * 20/9 ); //todo
	valorTextY = 1.0;
	pos = 0;

	for ( nivel = (ptosVerticales - 1);  0 <= nivel; nivel-- )
	{
		for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++)
		{
			this->curva->cargarPtosCrtl( puntos, curvaNum );

			for (ptoNum = 0; ptoNum <= CteIsla::PASO_BARRIDO; ptoNum++)
			{
				coordText [ pos     ] = (float)( curvaNum * ( CteIsla::PASO_BARRIDO + 1 ) + ptoNum ) / (( CteIsla::PASO_BARRIDO + 1) * this->curva->getCantCurvas() );
				coordText [ pos + 1 ] =  valorTextY ;

				pos += CteObjeto::CANT_COORD_TEXTURA;
			}
		}
		valorTextY -= incY;
	}

	return coordText;
}

float* BordeBSpline::generarPtos()const
{
	unsigned int curvaNum, ptoNum, pos;
	int nivel;
	float x, y, factor;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];
	float* ptos = new float [ this->getCantPtos() * CteObjeto::CANT_COORD_PTO ];

	factor = 1.0;
	pos = 0;

	for ( nivel = (ptosVerticales - 1) ; 0 <= nivel ; nivel-- ) //-1 porq cuento desde cero
	{
		for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++ ) // todas la curva
		{
			this->curva->cargarPtosCrtl( puntos, curvaNum );

			for (ptoNum = 0; ptoNum <= CteIsla::PASO_BARRIDO; ptoNum++) // ptos de ctrl de un tramo de la curva cerrada
			{
				CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)ptoNum/CteIsla::PASO_BARRIDO, x, y );

				ptos[ pos     ] = x * factor * ESCALADOxy;
				ptos[ pos + 1 ] = y * factor * ESCALADOxy;

				ptos[ pos + 2 ] = ALTURA_ENTRE_NIVELES * nivel * ESCALADOz;

				pos += CteObjeto::CANT_COORD_PTO;
			}
		}
		factor += PENDIENTE;
	}

	return ptos;
}

unsigned int BordeBSpline::getCantPtos() const
{
	return ptosHorizontales * ptosVerticales;
}

unsigned int BordeBSpline::getCantReferencias() const
{
	return 2 * ( ptosHorizontales + 1 ) * ( ptosVerticales - 1 );
}
float BordeBSpline::getAltura() const
{
	return ALTURA_ENTRE_NIVELES * (ptosVerticales-1) * ESCALADOz;
}
BordeBSpline::~BordeBSpline()
{
	delete curva;
}
