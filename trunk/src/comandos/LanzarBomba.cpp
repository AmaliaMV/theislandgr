/*
 * LanzarBomba.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "LanzarBomba.h"

LanzarBomba::LanzarBomba(Mundo* mundo): Comando()
{
	this->mundo = mundo;
}

void LanzarBomba::ejecutar()
{
	this->mundo->lanzarBomba();
}

const string LanzarBomba::getDescripcion() const
{
	return "Lanzar Bomba";
}


LanzarBomba::~LanzarBomba() {}
