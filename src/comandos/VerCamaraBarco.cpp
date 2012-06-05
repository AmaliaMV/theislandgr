/*
 * VerCamaraBarco.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraBarco.h"

VerCamaraBarco::VerCamaraBarco(AdminCamaras* admin, Mouse* mouse): Comando()
{
	this->admin = admin;
	this->mouse = mouse;
}

void VerCamaraBarco::ejecutar()
{
	this->admin->setCamaraActual( CAMARA_BARCO );
	this->mouse->setCamara(this->admin->getCamaraActual());
}

const string VerCamaraBarco::getDescripcion() const
{
	return "Camara Barco";
}

VerCamaraBarco::~VerCamaraBarco() {}
