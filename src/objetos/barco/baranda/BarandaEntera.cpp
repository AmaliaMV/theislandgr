/*
 * BarandaEntera.cpp
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#include "BarandaEntera.h"

BarandaEntera::BarandaEntera( string nombreTextura, float altura, float longitud,
		EstrategiaTransformacion* estrategia, ComponenteBarco* aDecorar )
	:ObjetoDibujable (),
	 DecoradorBarco( estrategia, aDecorar )
{
	this->ALTURA = altura;
	this->LONGITUD = longitud;

	this->abajo = new ParteAbajo ( nombreTextura, ALTURA / 2, LONGITUD, INICIO, FIN);
	this->arriba = new ParteArriba ( nombreTextura, ALTURA / 2, LONGITUD, INICIO, FIN );

	this->compilarDisplayList();
}

BarandaEntera::~BarandaEntera()
{
	delete this->arriba;
	delete this->abajo;
}

void BarandaEntera::displayList() const
{
	glPushMatrix();
		this->abajo->dibujar();
		glPushMatrix();
			glTranslatef( 0.0, 0.0, ALTURA / 2);
			this->arriba->dibujar();
		glPopMatrix();
	glPopMatrix();
}

void BarandaEntera::dibujar()
{
	ObjetoDibujable::dibujar();
}
