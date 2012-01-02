/*
 * TVelaSecundaria.cpp
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#include "TVelaSecundaria.h"

TVelaSecundaria::TVelaSecundaria( float centroVela, float altura, float desplazamientoHorizontal )
	:EstrategiaTransformacion()
{
	this->DESPLAZAMIENTO = desplazamientoHorizontal;
	this->ALTURA = altura;
	this->CENTRO = centroVela;
}

void TVelaSecundaria::ejecutar()
{
	glTranslatef( 0.0, DESPLAZAMIENTO, 0.0);
	glRotatef(-90, 0.0, 0.0, 1.0);
	glTranslatef(0.0, -CENTRO, ALTURA);
}

TVelaSecundaria::~TVelaSecundaria() {}
