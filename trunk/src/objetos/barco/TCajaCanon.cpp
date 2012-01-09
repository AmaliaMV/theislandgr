/*
 * TCajaCanon.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "TCajaCanon.h"

#define TRASLACIONX  -CteBarco::RADIO_X + LARGO/2.0
#define TRASLACIONZ  ALTO/2 + 0.02

TCajaCanon::TCajaCanon( float alturaCaja, float largoCaja): EstrategiaTransformacion()
{
	ALTO = alturaCaja;
	LARGO = largoCaja;
}

TCajaCanon::~TCajaCanon() {}

void TCajaCanon::ejecutar()
{
	glTranslatef( TRASLACIONX, 0.0, TRASLACIONZ ); // el 0.01 para q no titile al dibujar
}

void TCajaCanon::getTPto( const float x, const float y, const float z, float &fx, float &fy, float &fz ) const
{
	fx = TRASLACIONX + x;
	fy = y;
	fz = TRASLACIONZ + z;
}

#undef TRASLACIONZ
#undef TRASLACIONX
