/*
 * Arena.cpp
 *
 *  Created on: 19/08/2011
 *      Author: amalia
 */

#include "SuperficieBSpline.h"

SuperficieBSpline::SuperficieBSpline( PuntosControl *ptos, string nombreTextura, const int paso )
	: ODTextura ( new Textura24(nombreTextura) )
{
	this->curva = new BSplineCerrada ( ptos );

	unsigned int cantPtos = CteObjeto::CANT_COORD_PTO * this->getCantPtos();
	this->PASO = paso;

	this->init( cantPtos, this->getCantPtos(), GL_TRIANGLE_FAN );

}

SuperficieBSpline::~SuperficieBSpline()
{
	delete this->curva;
}

void SuperficieBSpline::generarCoordPtos()
{
	unsigned int pos, curvaNum, k;
	float x, y, centroX, centroY, centroZ;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];

	pos = 0;

	/* el primer pto es el del centro*/
	centroX = centroY = centroZ = 0.0;
	CalculadoraBSpline::calcularCentro( this->curva->getPuntosControl(), centroX, centroY, centroZ, PASO);

	ptos [ pos++ ] = centroX;
	ptos [ pos++ ] = centroY;
	ptos [ pos++ ] = 0.0;

	for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++)
	{
		this->curva->cargarPtosCrtl( puntos, curvaNum );

		for (k = 0; k <= CteIsla::PASO_BARRIDO; k++) /*dibujado los tramos de la curva*/
		{
			CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)k/CteIsla::PASO_BARRIDO, x, y );

			ptos [ pos++ ] = x;
			ptos [ pos++ ] = y;
			ptos [ pos++ ] = 0.0;

		}
	}
}

/*el orden del indice es como se ponen los ptos ya q uso un triangle fan*/
void SuperficieBSpline::generarIndice()
{
	unsigned int pos;

	for ( pos = 0; pos < this->getCantPtos(); pos++)
		indice[ pos ] = pos;
}

/*
 * necesito saber cual es el Ymax para asignarle la coord de text 1.0
 * Ymin, 0.0, Xmax 1.0 e X min 0.0
 */
void SuperficieBSpline::generarCoodText()
{
	unsigned int pos, curvaNum, ptoNum;
	float centroX, centroY, centroZ, xmin, xmax, ymin, ymax, x, y;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];

	pos = 0;
	xmin = xmax = ymin = ymax = 0.0;
	CalculadoraBSpline::calcularExtremosCentrada05( this->curva->getPuntosControl(), xmin, xmax, ymin, ymax, PASO );
	centroX = centroY = centroZ = 0.0;
	CalculadoraBSpline::calcularCentro( this->curva->getPuntosControl(), centroX, centroY, centroZ, PASO );

	x = centroX ;
	y = centroY ;

	/* el primer pto es el del centro */
	text [ pos++ ] = ( x - xmin ) / ( xmax - xmin );
	text [ pos++ ] = ( y - ymin ) / ( ymax - ymin );

	for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++)
	{
		this->curva->cargarPtosCrtl( puntos, curvaNum );

		for (ptoNum = 0; ptoNum <= CteIsla::PASO_BARRIDO; ptoNum++) /*dibujado los tramos de la curva en pantalla*/
		{
			CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)ptoNum/CteIsla::PASO_BARRIDO, x, y );

			text [ pos++ ] = ( x - xmin ) / ( xmax - xmin );
			text [ pos++ ] = ( y - ymin ) / ( ymax - ymin );

		}
	}
}

unsigned int SuperficieBSpline::getCantPtos() const
{
	return this->curva->getCantCurvas() * (CteIsla::PASO_BARRIDO + 1) + 1 ; // el +1 es por el 0.0
}
