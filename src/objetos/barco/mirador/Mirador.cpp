/*
 * Mirador.cpp
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#include "Mirador.h"

Mirador::Mirador( string nombreTexturaBorde, string nombreTexturaPiso, string nombreTexturaBaranda,
		float radio, EstrategiaTransformacion* transformacion, ComponenteBarco* aDecorar )
	: ObjetoDibujable(), DecoradorBarco(transformacion, aDecorar)
{
	this->CANT_PALITOS = 16;
	this->RADIO = radio;

	this->piso = new PisoDeMirador(nombreTexturaBorde, nombreTexturaPiso, RADIO);
	this->baranda = new LadoCilindroConTextura(nombreTexturaBaranda, RADIO/20, RADIO/2);
	this->pasamano = new ToroideConTextura(nombreTexturaBorde, RADIO, RADIO/10);

	this->compilarDisplayList();
}

Mirador::~Mirador()
{
	delete this->piso;
	delete this->baranda;
	delete this->pasamano;
}

void Mirador::dibujarBaranda() const
{
	float fi, pasoFi;

	pasoFi = (float) GIRO_COMPLETO / CANT_PALITOS;

	for ( fi = 0; fi < GIRO_COMPLETO; fi += pasoFi )
	{
		glPushMatrix();
			glRotatef( fi, 0.0, 0.0, 1.0 ); // esto es para q la textura quede mejor
			glTranslatef( RADIO * Matematica::cosHex( fi ),
					RADIO * Matematica::sinHex( fi ), 0.0);
			this->baranda->dibujar();
		glPopMatrix();
	}
}

void Mirador::displayList() const
{
	this->piso->dibujar();
	this->dibujarBaranda();
	glPushMatrix();
		glTranslatef(0.0, 0.0, RADIO/2);
		this->pasamano->dibujar();
	glPopMatrix();
}

void Mirador::dibujar()
{
	ObjetoDibujable::dibujar();
}
