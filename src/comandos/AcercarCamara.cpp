/*
 * AcercarCamara.cpp
 *
 *  Created on: 12/02/2012
 *      Author: amalia
 */

#include "AcercarCamara.h"

AcercarCamara::AcercarCamara(AdminCamaras* admin): Comando()
{
	this->admin = admin;
}

void AcercarCamara::ejecutar()
{
	this->admin->getCamaraActual()->acercarCamara();
}

const string AcercarCamara::getDescripcion() const
{
	return "Acercar Camara";
}

AcercarCamara::~AcercarCamara() {}
