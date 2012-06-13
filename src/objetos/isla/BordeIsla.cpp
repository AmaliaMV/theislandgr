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
	this->ptosHorizontales = this->curva->getCantCurvas() * CteIsla::PASO_BARRIDO + 1 /*repito el primer pto*/;
	this->ptosVerticales = cantNivelesHorizontales;
	this->init( this->getCantPtos(), this->getCantReferencias(), GL_TRIANGLE_STRIP, true);
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

void BordeIsla::generarNormales()
{
	unsigned int curvaNum, ptoNum, pos = 0;
	const float pendienteZ = ALTURA_ENTRE_NIVELES * ESCALADOz;
	int nivel;
	float x, y, factor = 1.0;
	float puntos[ORDEN_BSPLINE][CteObjeto::CANT_COORD_PTO];

	for ( nivel = (ptosVerticales - 1) ; 0 <= nivel ; nivel-- ) //-1 porq cuento desde cero
	{
		for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++ ) // todas las curvas
		{
			this->curva->cargarPtosCrtl( puntos, curvaNum );
			for (ptoNum = 0; ptoNum < CteIsla::PASO_BARRIDO; ptoNum++) // ptos de ctrl de un tramo de la curva cerrada
			{
				float u[3], v[3];
				CalculadoraBSpline::f1_bspline( *puntos, (float)ptoNum/(CteIsla::PASO_BARRIDO), x, y );
				u[0] = x * factor * ESCALADOxy;
				u[1] = y * factor * ESCALADOxy;
				u[2] = 0.0;

				CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)ptoNum/(CteIsla::PASO_BARRIDO), x, y );
				v[0] = x * ESCALADOxy * PENDIENTE;
				v[1] = y * ESCALADOxy * PENDIENTE;
				v[2] = pendienteZ;

				Matematica::productoVectorial(v,u,&normales[pos]);
				normales[pos+2] = pendienteZ ;
				Matematica::normalizar3(&normales[pos]);
				pos+=3;
			}

		}
		/*repito el primer pto*/
		this->curva->cargarPtosCrtl( puntos, 0 );
		float u[3], v[3];
		CalculadoraBSpline::f1_bspline( *puntos, (float)ptoNum/(CteIsla::PASO_BARRIDO), x, y );
		u[0] = x * factor * ESCALADOxy;
		u[1] = y * factor * ESCALADOxy;
		u[2] = 0.0;

		v[0] = 0.0;
		v[1] = 0.0;
		v[2] = pendienteZ;

		Matematica::productoVectorial(v,u,&normales[pos]);
		Matematica::normalizar3(&normales[pos]);
		pos+=3;

		factor += PENDIENTE;
	}
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
		for ( curvaNum = 0; curvaNum < this->curva->getCantCurvas(); curvaNum++ ) // todas las curvas
		{
			this->curva->cargarPtosCrtl( puntos, curvaNum );
			for (ptoNum = 0; ptoNum < CteIsla::PASO_BARRIDO; ptoNum++) // ptos de ctrl de un tramo de la curva cerrada
			{
				CalculadoraBSpline::f_bsplineCentrada05( *puntos, (float)ptoNum/(CteIsla::PASO_BARRIDO), x, y );
				ptos[ pos++ ] = x * factor * ESCALADOxy;
				ptos[ pos++ ] = y * factor * ESCALADOxy;
				ptos[ pos++ ] = ALTURA_ENTRE_NIVELES * nivel * ESCALADOz;
			}

		}
		/*repito el primer pto*/
		this->curva->cargarPtosCrtl( puntos, 0 );
		CalculadoraBSpline::f_bsplineCentrada05( *puntos, 0, x, y );
		ptos[ pos++ ] = x * factor * ESCALADOxy;
		ptos[ pos++ ] = y * factor * ESCALADOxy;
		ptos[ pos++ ] = ALTURA_ENTRE_NIVELES * nivel * ESCALADOz;

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
	}
}

void BordeIsla::generarCoodText()
{
	unsigned int ptoNum, pos;
	float incY, valorTextY;
	int nivel;

	incY = 0.70 / ( ptosVerticales * 30/9 );
	valorTextY = 1.0;
	pos = 0;
	for ( nivel = (ptosVerticales - 1);  0 <= nivel; nivel-- )
	{
		for ( ptoNum = 0; ptoNum < ptosHorizontales-1; ptoNum++) //no considero el primer pto q quite
		{
			text [ pos++ ] = valorTextY ;
			text [ pos++ ] = (float)( ptoNum ) / (ptosHorizontales-1);
		}

		text [ pos++ ] = valorTextY ;
		text [ pos++ ] = 1.0;

		valorTextY -= incY;
	}
}

void BordeIsla::displayList() const
{
	glColor3f(1.0, 1.0, 1.0);
	ODTextura::displayList();
}

unsigned int BordeIsla::getCantPtos() const
{
	return ptosHorizontales * ptosVerticales;
}

unsigned int BordeIsla::getCantReferencias() const
{
	return 2 * ptosHorizontales * ( ptosVerticales - 1 );
}
