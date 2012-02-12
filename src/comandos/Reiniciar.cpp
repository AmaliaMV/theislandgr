/*
 * Reiniciar.cpp
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#include "Reiniciar.h"

Reiniciar::Reiniciar(Mundo* mundo): Comando()
{
	this->mundo = mundo;
}

void Reiniciar::ejecutar()
{
	this->mundo->reiniciarFisica();
}

const string Reiniciar::getDescripcion() const
{
	return "Reiniciar";
}

Reiniciar::~Reiniciar() {}
