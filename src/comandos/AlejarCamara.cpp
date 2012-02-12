/*
 * AlejarCamara.cpp
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#include "AlejarCamara.h"

AlejarCamara::AlejarCamara(AdminCamaras* admin): Comando()
{
	this->admin = admin;
}
void AlejarCamara::ejecutar()
{
	this->admin->getCamaraActual()->alejarCamara();
}
const string AlejarCamara::getDescripcion() const
{
	return "Alejar Camara";
}

AlejarCamara::~AlejarCamara() {}
