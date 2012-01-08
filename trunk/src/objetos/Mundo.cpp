/*
 * Mundo.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Mundo.h"

const float Mundo::RADIO_MUNDO =  70.0;
const float Mundo::RADIO_AGUA = RADIO_MUNDO+4;

Mundo::Mundo(string nombreArchivoNivel)
{
	AdministradorArchivo *admin = new AdministradorArchivo ( nombreArchivoNivel );

	isla = new Isla ( admin );
	agua = new Agua( admin->getNombreArchivo( AGUA ), RADIO_AGUA);
	cielo = new Cielo ( admin->getNombreArchivo( CIELO), RADIO_MUNDO);
	barco = new Barco();

	this->posBarco = new TBarco();

	delete admin;
}

void Mundo::actualizar()
{
	agua->incrementarAngulo();
	this->incAnguloBarco();
}

void Mundo::dibujar()
{
	cielo->dibujar();
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.5); //para q no se vea la junta con el cielo
		agua->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, 0.0, 1.5);
		isla->dibujar();
	glPopMatrix();


	glPushMatrix();
		this->posBarco->ejecutar();
		barco->dibujar();
	glPopMatrix();

}

Mundo::~Mundo()
{
	delete agua;
	delete cielo;
	delete barco;
	delete isla;
	delete posBarco;
}

void Mundo::incAnguloBarco()
{
	this->posBarco->incAngulo();
}

TBarco* Mundo::getTBarco() const
{
	return this->posBarco;
}
