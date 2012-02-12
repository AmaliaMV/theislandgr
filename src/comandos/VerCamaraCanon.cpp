/*
 * VerCamaraCanon.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraCanon.h"

VerCamaraCanon::VerCamaraCanon(AdminCamaras* admin): Comando()
{
	this->admin = admin;
}
void VerCamaraCanon::ejecutar()
{
	this->admin->setCamaraActual(CAMARA_CANON);
}
const string VerCamaraCanon::getDescripcion() const
{
	return "Camara Canon";
}

VerCamaraCanon::~VerCamaraCanon() {}
