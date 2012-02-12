/*
 * VerCamaraBarco.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraBarco.h"

VerCamaraBarco::VerCamaraBarco(AdminCamaras* admin): Comando()
{
	this->admin = admin;
}

void VerCamaraBarco::ejecutar()
{
	this->admin->setCamaraActual( CAMARA_BARCO );
}

const string VerCamaraBarco::getDescripcion() const
{
	return "Camara Barco";
}

VerCamaraBarco::~VerCamaraBarco() {}
