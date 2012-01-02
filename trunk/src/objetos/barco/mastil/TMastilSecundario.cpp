/*
 * TMastilSecundario.cpp
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#include "TMastilSecundario.h"

TMastilSecundario::TMastilSecundario(  float desplazamiento )
	:EstrategiaTransformacion()
{
	this->DESPLAZAMIENTO = desplazamiento;
}

TMastilSecundario::~TMastilSecundario() {}

void TMastilSecundario::ejecutar()
{
	glTranslatef( 0.0, DESPLAZAMIENTO, 0.0 );
}
