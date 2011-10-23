/*
 * Superfice.cpp
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#include "SuperficeBSlpineChata.h"

SuperficeBSlpineChata::SuperficeBSlpineChata(  PuntosControl *ptos )
{
	curva 	= new BSplineCerrada ( ptos );
}

float* SuperficeBSlpineChata::generarPtos ( const unsigned int paso )
{
	unsigned int pos, curvaNum, k;
	float x, y, centroX, centroY, centroZ;
	float puntos[4][CteObjeto::CANT_COORD_PTO];

	float* ptos = new float [ CteObjeto::CANT_COORD_PTO * this->getCantPtos() ];

	pos = 0;

	/* el primer pto es el del centro*/
	centroX = centroY = centroZ = 0.0;
	CalculadoraBSpline::calcularCentro( this->curva->getPuntosControl(), centroX, centroY, centroZ, paso);

	ptos [ pos     ] = centroX;
	ptos [ pos + 1 ] = centroY;
	ptos [ pos + 2 ] = 0.0;
	pos += CteObjeto::CANT_COORD_PTO;

	for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++)
	{
		this->curva->cargarPtosCrtl( puntos, curvaNum );

		for (k = 0; k <= CteIsla::PASO_BARRIDO; k++) /*dibujado los tramos de la curva en pantalla*/
		{
			CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)k/CteIsla::PASO_BARRIDO, x, y );

			ptos [ pos     ] = x;
			ptos [ pos + 1 ] = y;
			ptos [ pos + 2 ] = 0.0;

			pos += CteObjeto::CANT_COORD_PTO;
		}
	}

	return ptos;
}

/*el orden del indice es como se ponen los ptos ya q uso un triangle fan*/
unsigned int*  SuperficeBSlpineChata::generarIndice ()
{
	unsigned int pos;
	unsigned int * vertIndice = new unsigned int [ this->getCantPtos() ];

	for ( pos = 0; pos < this->getCantPtos(); pos++)
		vertIndice[ pos ] = pos;

	return vertIndice;
}

/*
 * necesito saber cual es el Ymax para asignarle la coord de text 1.0
 * Ymin, 0.0, Xmax 1.0 e X min 0.0
 */
float*  SuperficeBSlpineChata::generarCoordText (const unsigned int paso )
{
	unsigned int pos, curvaNum, ptoNum;
	float centroX, centroY, centroZ, xmin, xmax, ymin, ymax, x, y;
	float puntos[4][CteObjeto::CANT_COORD_PTO];

	float* coordText = new float [ CteObjeto::CANT_COORD_TEXTURA * this->getCantPtos() ];

	pos = 0;
	xmin = xmax = ymin = ymax = 0.0;
	CalculadoraBSpline::calcularExtremosCentrada05( this->curva->getPuntosControl(), xmin, xmax, ymin, ymax, paso );
	centroX = centroY = centroZ = 0.0;
	CalculadoraBSpline::calcularCentro( this->curva->getPuntosControl(), centroX, centroY, centroZ, paso);

	x = centroX ;
	y = centroY ;

	/* el primer pto es el del centro */
	coordText [ pos     ] = ( x - xmin ) / ( xmax - xmin );
	coordText [ pos + 1 ] = ( y - ymin ) / ( ymax - ymin );
	pos += CteObjeto::CANT_COORD_TEXTURA;

	for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++)
	{
		this->curva->cargarPtosCrtl( puntos, curvaNum );

		for (ptoNum = 0; ptoNum <= CteIsla::PASO_BARRIDO; ptoNum++) /*dibujado los tramos de la curva en pantalla*/
		{
			CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)ptoNum/CteIsla::PASO_BARRIDO, x, y );

			coordText [ pos     ] = ( x - xmin ) / ( xmax - xmin );
			coordText [ pos + 1 ] = ( y - ymin ) / ( ymax - ymin );

			pos += CteObjeto::CANT_COORD_TEXTURA;
		}
	}

	return coordText;
}
SuperficeBSlpineChata::~SuperficeBSlpineChata()
{
	delete curva;
}

unsigned int SuperficeBSlpineChata::getCantPtos()
{
	return this->curva->getCantCurvas() * (CteIsla::PASO_BARRIDO + 1) + 1 ; // el +1 es por el 0.0
}


