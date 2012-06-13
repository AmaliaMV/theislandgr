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
	this->textura = new Textura24(nombreTextura);

	this->ALTURA = altura;
	this->LONGITUD = longitud;

	this->abajo = new ParteAbajo ( textura, ALTURA / 2, LONGITUD, INICIO, FIN );
	this->arriba = new ParteArriba ( textura, ALTURA / 2, LONGITUD, INICIO, FIN );
	this->abajoAdentro = new ParteAbajo ( textura, ALTURA / 2, LONGITUD, INICIO, FIN, 0.05, -1 );
	this->arribaAdentro = new ParteArriba ( textura, ALTURA / 2, LONGITUD, INICIO, FIN, 0.05, -1 );

	this->inicializarLuz();
	this->compilarDisplayList();
}

BarandaEntera::~BarandaEntera()
{
	delete this->arriba;
	delete this->abajo;
	delete this->arribaAdentro;
	delete this->abajoAdentro;
	delete this->textura;
	this->eliminarLuz();
}

void BarandaEntera::displayList() const
{
	this->luz->setPropiedadesMaterial();
	glPushMatrix();
		this->abajo->dibujar();
		this->abajoAdentro->dibujar();
		glPushMatrix();
			glTranslatef( 0.0, 0.0, ALTURA / 2);
			this->arriba->dibujar();
			this->arribaAdentro->dibujar();
		glPopMatrix();
	glPopMatrix();
}

void BarandaEntera::dibujar()
{
	ObjetoDibujable::dibujar();
}

void BarandaEntera::inicializarLuz()
{
	this->luz = new IluminacionMaterial(1.0, 1.0, 1.0);
}

void BarandaEntera::eliminarLuz()
{
	delete luz;
}
