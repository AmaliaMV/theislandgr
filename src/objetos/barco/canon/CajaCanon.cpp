/*
 * CajaCanon.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "CajaCanon.h"

CajaCanon::CajaCanon( string nombreTextura, float alto, float ancho, float largo,
		EstrategiaTransformacion *transformacion, ComponenteBarco *aDecorar)
	: ObjetoDibujable(),
	  DecoradorBarco( transformacion, aDecorar )
{
	this->caja = new LadoPrismaConTextura ( nombreTextura, largo, ancho, alto );
	this->eje = new LadoCilindroConTextura ( nombreTextura, ancho/10.0, ancho);

	this->inicializarLuz();
	this->compilarDisplayList();
}

CajaCanon::~CajaCanon()
{
	delete this->eje;
	delete this->caja;
	this->eliminarLuz();
}

void CajaCanon::displayList() const
{
	glColor3f(0.2, 0.2, 0.2);
	this->luz->setPropiedadesMaterial();
	glPushMatrix();
		glRotatef(-90, 1.0, 0.0, 0.0);
		glTranslatef( 0.0, 0.0, -this->eje->getAltura()/2);
		this->eje->dibujar();
	glPopMatrix();
	glPushMatrix();
		glRotatef(-90, 0.0, 1.0, 0.0);
		this->caja->dibujar();
	glPopMatrix();
}

void CajaCanon::dibujar()
{
	ObjetoDibujable::dibujar();
}

void CajaCanon::inicializarLuz()
{
	this->luz = new IluminacionMaterial(0.2, 0.2, 0.2);
}

void CajaCanon::eliminarLuz()
{
	delete this->luz;
}
