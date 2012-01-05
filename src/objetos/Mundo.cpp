/*
 * Mundo.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Mundo.h"

const float Mundo::RADIO_MUNDO =  40.0;
const float Mundo::RADIO_AGUA = 44.0;

Mundo::Mundo(string nombreArchivoNivel)
{
	AdministradorArchivo *admin = new AdministradorArchivo ( nombreArchivoNivel );

	isla = new Isla ( admin );
	agua = new Agua( admin->getNombreArchivo( AGUA ), 44.0 );
	cielo = new Cielo ( admin->getNombreArchivo( CIELO), 40.0);
	barco = new Barco();

	delete admin;
}
void Mundo::actualizar()
{
	agua->incrementarAngulo();
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
		glTranslatef(10.0, 10.0, 2.5);
		glScalef(0.25, 0.25, 0.25);
		barco->dibujar();
	glPopMatrix();

}

Mundo::~Mundo()
{
	delete agua;
	delete cielo;
	delete barco;
	delete isla;
}
