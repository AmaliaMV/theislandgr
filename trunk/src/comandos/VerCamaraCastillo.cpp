/*
 * VerCamaraCastillo.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraCastillo.h"

VerCamaraCastillo::VerCamaraCastillo(AdminCamaras* admin): Comando()
{
	this->admin = admin;
}

void VerCamaraCastillo::ejecutar()
{
	this->admin->setCamaraActual( CAMARA_CASTILLO);
}

const string VerCamaraCastillo::getDescripcion() const
{
	return "Camara Castillo";
}

VerCamaraCastillo::~VerCamaraCastillo() {}
