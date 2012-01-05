/*
 * BordeIsla.cpp
 *
 *  Created on: 12/08/2011
 *      Author: amalia
 */

/* tod0 lo relacionado con la textura solo va a funcionar bien si
	 * el xmin y el ymin son menores a cero de forma tal que al
	 * multiplicar estos valores por un numero positivo, el resultado
	 * obtenido sea menor a ellos
	 */

#include "BordeIsla.h"

const float BordeIsla::PENDIENTE = 0.09;  // es el escalado q hay entre una curva y la q sigue. No puede ser un numero menor a uno
const float BordeIsla::ESCALADOxy = 20.0;
const float BordeIsla::ESCALADOz =  BordeIsla::ESCALADOxy / 9.00;
const float BordeIsla::ALTURA_ENTRE_NIVELES = 0.4;

BordeIsla::BordeIsla( PuntosControl *ptos, string nombreTextura, const int cantNivelesHorizontales )
	: ODTextura( new Textura24( nombreTextura ) )
{
	this->curva = new BSplineCerrada ( ptos );
	this->ptosHorizontales = this->curva->getCantCurvas() * ( CteIsla::PASO_BARRIDO + 1 );
	this->ptosVerticales = cantNivelesHorizontales;

	this->init( this->getCantPtos(), this->getCantReferencias(), GL_TRIANGLE_STRIP );
}

BordeIsla::~BordeIsla()
{
	delete curva;
}

float BordeIsla::getAlturaMax() const
{
	return ALTURA_ENTRE_NIVELES * (ptosVerticales-1) * ESCALADOz;
}

float BordeIsla::getEscalado() const
{
	return ESCALADOxy;
}

void BordeIsla::generarCoordPtos()
{
	unsigned int curvaNum, ptoNum, pos;
	int nivel;
	float x, y, factor;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];

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

				ptos[ pos++ ] = x * factor * ESCALADOxy;
				ptos[ pos++ ] = y * factor * ESCALADOxy;
				ptos[ pos++ ] = ALTURA_ENTRE_NIVELES * nivel * ESCALADOz;

			}
		}
		factor += PENDIENTE;
	}
}

void BordeIsla::generarIndice()
{
	unsigned int pos, posFila, posColumna;
	pos = 0;

	for ( posFila = 0; posFila < ptosVerticales - 1 ; posFila++ )
	{
		for ( posColumna = 0 ; posColumna < ptosHorizontales; posColumna++ )
		{
			indice [ pos++ ] = posColumna + ptosHorizontales * posFila;
			indice [ pos++ ] = posColumna + ptosHorizontales * ( posFila + 1);
		}

		indice [ pos++ ] = ptosHorizontales * posFila;
		indice [ pos++ ] = ptosHorizontales * ( posFila + 1);
	}
}

void BordeIsla::generarCoodText()
{
	unsigned int curvaNum, ptoNum, pos;
	float incY, valorTextY;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];
	int nivel;

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
				text [ pos++ ] = (float)( curvaNum * ( CteIsla::PASO_BARRIDO + 1 ) + ptoNum ) / (( CteIsla::PASO_BARRIDO + 1) * this->curva->getCantCurvas() );
				text [ pos++ ] =  valorTextY ;
			}
		}
		valorTextY -= incY;
	}
}

unsigned int BordeIsla::getCantPtos() const
{
	return ptosHorizontales * ptosVerticales;
}

unsigned int BordeIsla::getCantReferencias() const
{
	return 2 * ( ptosHorizontales + 1 ) * ( ptosVerticales - 1 );
}
