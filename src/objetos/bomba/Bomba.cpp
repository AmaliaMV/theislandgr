/*
 * Bomba.cpp
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#include "Bomba.h"

const float Bomba::MASA_BOMBA = 10.0;

Bomba::Bomba( btSphereShape* shape, const float posX, const float posY,
		const float posZ , const float angHCanon, const float angVCanon, const float angBarco,
		const float radioDistancia )
	:FEsferaRigida( shape, posX, posY, posZ, MASA_BOMBA, angHCanon, angVCanon, angBarco, radioDistancia )
{
	RADIO = shape->getMargin();
	this->inicializarLuz();
}

Bomba::~Bomba()
{
	this->eliminarLuz();
}

void Bomba::dibujar() const
{
	glPushMatrix();
		FEsferaRigida::aplicarTransformada();
		this->luz->setPropiedadesMaterial();
		glutSolidSphere(RADIO, 16, 16);
	glPopMatrix();
}

void Bomba::inicializarLuz()
{
	this->luz = new IluminacionMaterial(0.45, 0.45, 0.45);
	this->luz->setBrillo(128);
}

void Bomba::eliminarLuz()
{
	delete this->luz;
}
