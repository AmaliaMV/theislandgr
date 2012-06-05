/*
 * VerCamaraCastillo.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraCastillo.h"

VerCamaraCastillo::VerCamaraCastillo(AdminCamaras* admin, Mouse* mouse): Comando()
{
	this->admin = admin;
	this->mouse = mouse;
}

void VerCamaraCastillo::ejecutar()
{
	this->admin->setCamaraActual( CAMARA_CASTILLO );
	this->mouse->setCamara(this->admin->getCamaraActual());
}

const string VerCamaraCastillo::getDescripcion() const
{
	return "Camara Castillo";
}

VerCamaraCastillo::~VerCamaraCastillo() {}
