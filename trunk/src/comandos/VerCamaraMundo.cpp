/*
 * VerCamaraMundo.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraMundo.h"

VerCamaraMundo::VerCamaraMundo(AdminCamaras* admin): Comando()
{
	this->admin = admin;
}

void VerCamaraMundo::ejecutar()
{
	this->admin->setCamaraActual( CAMARA_MUNDO );
}

const string VerCamaraMundo::getDescripcion() const
{
	return "Camara Mundo";
}

VerCamaraMundo::~VerCamaraMundo() {}
