/*
 * Pausar.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "Pausar.h"

Pausar::Pausar(Mundo* mundo): Comando()
{
	this->mundo = mundo;
}

void Pausar::ejecutar()
{
	this->mundo->pausar();
}

const string Pausar::getDescripcion() const
{
	return "Pausar";
}

Pausar::~Pausar() {}
