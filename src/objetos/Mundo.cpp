/*
 * Mundo.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Mundo.h"

const float Mundo::RADIO_MUNDO =  40.0;
const float Mundo::RADIO_AGUA = RADIO_MUNDO+4;
const float Mundo::RADIO_NAVEGACION = 35.0;
const float Mundo::DELTA_ANGULO = 0.05;

Mundo::Mundo(string nombreArchivoNivel)
{
	AdministradorArchivo *admin = new AdministradorArchivo ( nombreArchivoNivel );

	isla = new Isla ( admin );
	agua = new Agua( admin->getNombreArchivo( AGUA ), 44.0 );
	cielo = new Cielo ( admin->getNombreArchivo( CIELO), 40.0);
	barco = new Barco();

	this->anguloBarco = 0.0;

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
		glTranslatef(RADIO_NAVEGACION * Matematica::cosHex( anguloBarco ),
				RADIO_NAVEGACION * Matematica::sinHex( anguloBarco ), 0.0);
		glScalef(0.25, 0.25, 0.25);
		glTranslatef(0.0, 0.0, CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA);
		glRotatef( anguloBarco, 0.0, 0.0, 1.0 );
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

void Mundo::incAnguloBarco()
{
	if ( anguloBarco > 360.0 )
		anguloBarco = 0.0;
	anguloBarco+= DELTA_ANGULO;
}
