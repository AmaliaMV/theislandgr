/*
 * PisoDeMirador.cpp
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#include "PisoDeMirador.h"

PisoDeMirador::PisoDeMirador( const string nombreTexturaBorde, const string nombreTexturaPiso, const float radio )
	: ObjetoDibujable()
{
	this->inicializarLuces();
	this->inicializarObjetos(nombreTexturaBorde, nombreTexturaPiso, radio);
	this->compilarDisplayList();
}

void PisoDeMirador::inicializarObjetos(string nombreTexturaBorde, string nombreTexturaPiso, float radio)
{
	this->RADIO = radio;
	this->ESPESOR = 0.2;

	this->piso = new CirculoConTextura ( nombreTexturaPiso, this->RADIO );
	this->borde = new BordePisoMirador ( nombreTexturaBorde, this->RADIO, this->ESPESOR );
}

void PisoDeMirador::eliminarObjetos()
{
	delete this->piso;
	delete this->borde;
}

PisoDeMirador::~PisoDeMirador()
{
	this->eliminarObjetos();
	this->eliminarLuces();
}

void PisoDeMirador::displayList() const
{
	this->borde->dibujar();

	this->luz->setPropiedadesMaterial();
	this->piso->dibujar();

	glPushMatrix();
		glTranslatef(0.0, 0.0, ESPESOR);
		this->piso->dibujar();
	glPopMatrix();
}

void PisoDeMirador::inicializarLuces()
{
	this->luz = new IluminacionMaterial(0.85, 0.56, 0.0);
}

void PisoDeMirador::eliminarLuces()
{
	delete this->luz;
}
