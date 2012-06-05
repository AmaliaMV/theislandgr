/*
 * VerCamaraCanon.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "VerCamaraCanon.h"

VerCamaraCanon::VerCamaraCanon(AdminCamaras* admin, Mouse* mouse): Comando()
{
	this->admin = admin;
	this->mouse = mouse;
}
void VerCamaraCanon::ejecutar()
{
	this->admin->setCamaraActual(CAMARA_CANON);
	this->mouse->setCamara(this->admin->getCamaraActual());
}
const string VerCamaraCanon::getDescripcion() const
{
	return "Camara Canon";
}

VerCamaraCanon::~VerCamaraCanon() {}
