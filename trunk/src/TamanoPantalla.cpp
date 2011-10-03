/*
 * TamanoPantalla.cpp
 *
 *  Created on: 07/08/2011
 *      Author: amalia
 */

#include "TamanoPantalla.h"

float TamanoPantalla::ancho = 0.0;
float TamanoPantalla::alto = 0.0;

void TamanoPantalla::setAncho( float ancho )
{
	TamanoPantalla::ancho = ancho;
}

void TamanoPantalla::setAlto( float alto )
{
	TamanoPantalla::alto = alto;
}

void TamanoPantalla::setDimensiones( float ancho, float alto )
{
	TamanoPantalla::ancho = ancho;
	TamanoPantalla::alto = alto;
}

float TamanoPantalla::getAncho()
{
	return TamanoPantalla::ancho;
}

float TamanoPantalla::getAlto()
{
	return TamanoPantalla::alto;
}

TamanoPantalla::TamanoPantalla() { }

TamanoPantalla::~TamanoPantalla() {}
