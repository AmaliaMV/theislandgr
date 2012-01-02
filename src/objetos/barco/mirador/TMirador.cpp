/*
 * TMirador.cpp
 *
 *  Created on: 24/12/2011
 *      Author: amalia
 */

#include "TMirador.h"

TMirador::TMirador( float altura ):EstrategiaTransformacion()
{
	this->ALTURA = altura;
}

TMirador::~TMirador() {}

void TMirador::ejecutar()
{
	glTranslatef(0.0, 0.0, CteBarco::ALTURA_MIRADOR);
}
