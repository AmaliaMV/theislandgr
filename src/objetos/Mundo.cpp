/*
 * Mundo.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "Mundo.h"
#define ESCALADOZ 1.5
#define TRASLASIONZ 1.5
Mundo::Mundo(string nombreArchivoNivel)
{
	AdministradorArchivo *admin = new AdministradorArchivo ( nombreArchivoNivel );

	agua = new Agua( admin->getNombreArchivo( AGUA ), CteMundo::RADIO_AGUA);
	cielo = new Cielo ( admin->getNombreArchivo( CIELO ), CteMundo::RADIO_MUNDO);
	isla = new Isla ( admin );
	palmera = new Palmera ( admin->getNombreArchivo( PALMERA ) );
	CteMundo::ALTURA_ISLA = isla->getAltura()*ESCALADOZ + TRASLASIONZ;
	barco = new Barco( admin );
	fisica = new Fisica();
	btBoxShape *shapePiso = new btBoxShape(btVector3(btScalar(13.),btScalar(13.),0.001));
	piso = new PisoFisico( shapePiso, btScalar(CteMundo::ALTURA_ISLA));
	fisica->addCollisionShape( shapePiso );
	piso->agregarseAlMundo( fisica->getMundoFisico() );
	castillo = new Castillo(fisica, CteMundo::ALTURA_ISLA);
	delete admin;

	this->posBarco = new TBarco();

	pausa = false;

	adminBombas = new AdminBombas( fisica, (CteBarco::RADIO_X - 5.0 + this->barco->getTCanon()->getLargoCanon()) * 0.25, (CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA + 1.8) * 0.25 );
}

void Mundo::actualizar()
{
	if ( estaPausado() == false )
	{
		agua->incrementarAngulo();
		this->incAnguloBarco();
		this->adminBombas->acutalizarBombas();
//		fisica->getMundoFisico()->stepSimulation(1/300.f,10);
		fisica->getMundoFisico()->stepSimulation(1/20.f,10);
	}
}

void Mundo::dibujar()
{
	cielo->dibujar();

	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.5); //para q no se vea la junta con el cielo
		agua->dibujar();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, TRASLASIONZ);
		glScalef(2.0, 3.0, ESCALADOZ);
		isla->dibujar();
	glPopMatrix();

	glPushMatrix();
		this->posBarco->ejecutar();
		barco->dibujar();
	glPopMatrix();

	castillo->dibujar();
	adminBombas->dibujarBombas();

	glPushMatrix();
		glTranslatef(-10.0,0.0, CteMundo::ALTURA_ISLA);
		palmera->dibujar();
		glTranslatef(0.0,-10.0, 0.0 );
		palmera->dibujar();
		glTranslatef(18.0,0.0, 0.0);
		palmera->dibujar();
		glTranslatef(-25.0, 16.0, 0.0);
		palmera->dibujar();
	glPopMatrix();
}
void Mundo::reiniciarFisica()
{
	delete castillo;
	delete adminBombas;
	delete piso;
	fisica->reiniciar();

	try	{
		btBoxShape *shapePiso = new btBoxShape(btVector3(btScalar(13.),btScalar(13.),0.001));
		piso = new PisoFisico( shapePiso, btScalar(CteMundo::ALTURA_ISLA));
		fisica->addCollisionShape( shapePiso );
		piso->agregarseAlMundo( fisica->getMundoFisico() );
		castillo = new Castillo( fisica, CteMundo::ALTURA_ISLA );
		adminBombas = new AdminBombas( fisica, (CteBarco::RADIO_X - 5.0 + this->barco->getTCanon()->getLargoCanon()) * 0.25, (CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA + 1.8) * 0.25 );

	}catch ( EArchivoInexistente *e ){
		cout<< e->what() <<endl;
		exit(1);
	}
}

void Mundo::lanzarBomba()
{
	this->adminBombas->lanzarBomba( this->barco->getCanon()->getAngV(), this->barco->getCanon()->getAngH(), this->posBarco->getAngulo(), CteMundo::RADIO_NAVEGACION);
}

Mundo::~Mundo()
{
	delete piso;
	delete agua;
	delete cielo;
	delete barco;
	delete isla;
	delete posBarco;
	delete castillo;
	delete fisica;
	delete adminBombas;
	delete palmera;
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

#undef ESCALADOZ
#undef TRASLASIONZ
