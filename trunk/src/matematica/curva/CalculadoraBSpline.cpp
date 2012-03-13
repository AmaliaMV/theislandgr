/*
 * CalculadoraBSpline.cpp
 *
 *  Created on: 09/08/2011
 *      Author: amalia
 */

#include "CalculadoraBSpline.h"

const float CalculadoraBSpline::CENTRO = 0.5;
CalculadoraBSpline::CalculadoraBSpline() { }

CalculadoraBSpline::~CalculadoraBSpline() { }

void CalculadoraBSpline::f_bspline( float *ptos, float u, float &x, float &y)
{
	/* es una spline uniforme*/

	float b[4];
	b[0] = (-    pow( u, 3.0) + 3 * pow ( u, 2.0) - 3 * u + 1 ) / 6.0 ;
	b[1] = ( 3 * pow( u, 3.0) - 6 * pow ( u, 2.0)         + 4 ) / 6.0 ;
	b[2] = (-3 * pow( u, 3.0) + 3 * pow ( u, 2.0) + 3 * u + 1 ) / 6.0 ;
	b[3] = (     pow( u, 3.0)                                 ) / 6.0 ;

	float valorX = 0, valorY = 0;

	for ( int i = 0; i < 4; i++ )
	{
		valorX += b[i] * ptos [i*3];
		valorY += b[i] * ptos [i*3 + 1];
	}

	x = valorX;
	y = valorY;
}

void CalculadoraBSpline::f_bsplineCentrada05( float *ctrlPtos, float u, float &x, float &y)
{
	f_bspline( ctrlPtos, u, x, y);
	x -= CENTRO;
	y -= CENTRO;
}
void CalculadoraBSpline::f1_bspline( float *ptos, float u, float &x, float &y)
{
	/* es una spline uniforme*/

	float b[4];
	b[0] = (-3 * pow( u, 2.0) +  6 * u - 3 ) / 6.0 ;
	b[1] = ( 9 * pow( u, 2.0) - 12 * u     ) / 6.0 ;
	b[2] = (-9 * pow( u, 2.0) +  6 * u + 3 ) / 6.0 ;
	b[3] = ( 3 * pow( u, 2.0)              ) / 6.0 ;

	float valorX = 0, valorY = 0;

	for ( int i = 0; i < 4; i++ )
	{
		valorX += b[i] * ptos [i*3];
		valorY += b[i] * ptos [i*3 + 1];
	}

	x = valorX;
	y = valorY;
}

void CalculadoraBSpline::calcularCentro (PuntosControl *ctrlPtos, float &xc, float &yc, float &zc, int paso)
{
	int cantCurvas;
	float x,y;
	float puntos[4][3];

	cantCurvas = ctrlPtos->getCantPtos() - ORDEN_BSPLINE + 1;

	for (int i = 0; i < cantCurvas; i++)
	{
		for (int j = 0; j < 4; j++)
			for (int k = 0; k < 3; k++)
				puntos[j][k] = ctrlPtos->getPtos()[j*3+i*3 + k];

		for (int k = 0; k <= paso; k++)
		{
			CalculadoraBSpline::f_bspline( *puntos, (float)k/paso, x, y);
			xc = xc + (x - CENTRO); //CENTRO porq la curva esta graficada con centro en 0.5, en teoria :P
			yc = yc + (y - CENTRO); // en la practica, no necesariamnt
		}
	}

	xc = xc / (cantCurvas*paso);
	yc = yc / (cantCurvas*paso);

	zc = 0.0; //la curva esta definida en un plano
}

void CalculadoraBSpline::calcularExtremos (PuntosControl *ctrlPtos, float &xmin, float &xmax, float &ymin, float &ymax, const int paso)
{
	int cantCurvas, i, j, k;
	float x,y;
	float puntos[4][3];

	xmax = ymax = -99.0; //se supone q el valor min q puede tomar la curva es 0
	xmin = ymin =  99.0; //se supone q el valor max q puede tomar la curva es 1

	cantCurvas = ctrlPtos->getCantPtos() - ORDEN_BSPLINE + 1;

	for (i = 0; i < cantCurvas; i++)
	{
		for (j = 0; j < 4; j++)
			for (k = 0; k < 3; k++)
				puntos[j][k] = ctrlPtos->getPtos()[j*3+i*3 + k];

		for (int k = 0; k <= paso; k++)
		{
			CalculadoraBSpline::f_bspline(*puntos, (float)k/paso, x, y);
			if ( x > xmax )
				xmax = x;
			else if ( x < xmin )
				xmin = x;

			if ( y > ymax )
				ymax = y;
			else if ( y < ymin )
				ymin = y;
		}
	}
}

void CalculadoraBSpline::calcularExtremosCentrada05 (PuntosControl *ctrlPtos, float &xmin, float &xmax, float &ymin, float &ymax, const int paso)
{
	calcularExtremos ( ctrlPtos, xmin, xmax, ymin, ymax, paso );

	xmin -= CENTRO; //para trasladar el origen al 0.0
	ymin -= CENTRO;
	xmax -= CENTRO;
	ymax -= CENTRO;
}
