/*
 * Mundo.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Mundo.h"

const float Mundo::RADIO_AGUA = CteMundo::RADIO_MUNDO+4;

Mundo::Mundo(string nombreArchivoNivel)
{
	fisica = new Fisica();

	AdministradorArchivo *admin = new AdministradorArchivo ( nombreArchivoNivel );

	isla = new Isla ( admin );
	agua = new Agua( admin->getNombreArchivo( AGUA ), RADIO_AGUA);
	cielo = new Cielo ( admin->getNombreArchivo( CIELO), CteMundo::RADIO_MUNDO);
	barco = new Barco( admin );
	castillo = new Castillo(fisica);
	delete admin;

	this->posBarco = new TBarco();

	pausa = false;
}

void Mundo::actualizar()
{
	if ( estaPausado() == false )
	{
		agua->incrementarAngulo();
		this->incAnguloBarco();

		fisica->getMundoFisico()->stepSimulation(1/300.f,10);
	}
}

void Mundo::dibujar()
{
	glBegin(GL_LINE_STRIP);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(5);
		glVertex3f(0,0,0);
		glPushMatrix();
		this->posBarco->ejecutar();
		barco->getTCanon()->ejecutar();
		glVertex3f(5.0,5.0,5.0);
		glPopMatrix();
		glVertex3f(10,10,10);
		glLineWidth(1);
	glEnd();

	cielo->dibujar();
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.5); //para q no se vea la junta con el cielo
		agua->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0, 0.0, 1.5);
		glScalef(2.0, 2.0, 1.5);
		isla->dibujar();
	glPopMatrix();

	glPushMatrix();
		this->posBarco->ejecutar();
		barco->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, 0.0, isla->getAltura()+1.2);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		castillo->dibujar();

	glPopMatrix();
}
void Mundo::reiniciarFisica()
{
	delete castillo;
	fisica->reiniciar();

	try	{
		castillo = new Castillo( fisica );
	}catch ( EArchivoInexistente *e ){
		cout<< e->what() <<endl;
		exit(1);
	}
}

Mundo::~Mundo()
{
	delete agua;
	delete cielo;
	delete barco;
	delete isla;
	delete posBarco;
	delete castillo;
	delete fisica;
}

void Mundo::incAnguloBarco()
{ this->posBarco->incAngulo(); }

TBarco* Mundo::getTBarco() const
{ return this->posBarco; }

Barco* Mundo::getBarco() const
{ return this->barco; }

void Mundo::pausar()
{ this->pausa = !this->pausa; }

bool Mundo::estaPausado() const
{ return this->pausa; }
