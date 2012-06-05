/*
 * VerCamaraMundo.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraMundo.h"

VerCamaraMundo::VerCamaraMundo(AdminCamaras* admin, Mouse* mouse): Comando()
{
	this->admin = admin;
	this->mouse = mouse;
}

void VerCamaraMundo::ejecutar()
{
	this->admin->setCamaraActual( CAMARA_MUNDO );
	this->mouse->setCamara(this->admin->getCamaraActual());
}

const string VerCamaraMundo::getDescripcion() const
{
	return "Camara Mundo";
}

VerCamaraMundo::~VerCamaraMundo() {}
