/*
 * Vela.cpp
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#include "Vela.h"

Vela::Vela( string nombreTextVela, float largo, float alto, float factCurvatura,
		string nombreTextPalo, float radio,
		EstrategiaTransformacion* transformacion, ComponenteBarco* aDecorar)
	: ObjetoDibujable (),
	  DecoradorBarco ( transformacion, aDecorar )
{
	this->tela = new TelaVela ( nombreTextVela, largo, alto, factCurvatura );
	this->palito = new CilindroConTextura (nombreTextPalo, radio, largo);
	this->ALTO = alto;
	this->LARGO = largo;

	this->compilarDisplayList();
}

Vela::~Vela()
{
	delete this->palito;
	delete this->tela;
}

void Vela::dibujar()
{
	ObjetoDibujable::dibujar();
}

void Vela::displayList() const
{
	glPushMatrix();
		glTranslatef( 0.02, 0.0, 0.0 );
		this->tela->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, LARGO, -ALTO/2.0);
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		this->palito->dibujar();
	glPopMatrix();

	glPushMatrix();
		glTranslatef( 0.0, LARGO, ALTO/2.0);
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		this->palito->dibujar();
	glPopMatrix();
}
