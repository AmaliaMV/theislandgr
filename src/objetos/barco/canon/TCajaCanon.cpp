/*
 * TCajaCanon.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "TCajaCanon.h"

TCajaCanon::TCajaCanon( float alturaCaja, float largoCaja): EstrategiaTransformacion()
{
	ALTO = alturaCaja;
	LARGO = largoCaja;
}

TCajaCanon::~TCajaCanon() {}

void TCajaCanon::ejecutar()
{
	glTranslatef( -CteBarco::RADIO_X + LARGO/2.0, 0.0, ALTO/2 + 0.01 ); // el 0.01 para q no titile al dibujar
}
