/*
 * Isla.cpp
 *
 *  Created on: 09/08/2011
 *      Author: amalia
 */

#include "Isla.h"

Isla::Isla( AdministradorArchivo *administrador )
	: ObjetoDibujable()
{
	this->inicializarLuces();
	this->levantarCurva( administrador->getNombreArchivo( MAPA ) );

	/* creamos el borde de la isla*/
	pasto = new SuperficieBSpline ( ptos, administrador->getNombreArchivo( PASTO ), paso);
	supBorde = new BordeIsla( ptos, administrador->getNombreArchivo( SUELO ), cantNivelesHorizontalesIsla );
	playaBorde = new BordeIsla ( ptos, administrador->getNombreArchivo( ARENA ), cantNivelesHorizontalesPlaya); // es el costado de la isla
	arena = new SuperficieBSpline ( ptos, administrador->getNombreArchivo( ARENA ), paso);

	this->calcularCentroIsla();

	this->compilarDisplayList();
}

void Isla::inicializarLuces()
{
	this->luzPasto = new IluminacionMaterial(0.0, 0.5, 0.0);
	this->luzArena = new IluminacionMaterial(0.8, 0.5, 0.0);
}

void Isla::eliminarLuces()
{
	delete this->luzArena;
	delete this->luzPasto;
}

void Isla::displayList() const
{
	float largoPlaya = 3.0 / 2.0;

	glColor3f(1.0, 1.0, 1.0);

	glPushMatrix();

	glTranslatef(-xc,-yc, 0.0); // centro de la isla en el centro de coordenadas

	this->luzArena->setPropiedadesMaterial();
	supBorde->dibujar();

	luzPasto->setPropiedadesMaterial();
	glPushMatrix();
		glTranslatef(0.0,0.0, supBorde->getAlturaMax());
		glScalef(supBorde->getEscalado(),supBorde->getEscalado() ,1.0);
		pasto->dibujar();
	glPopMatrix();

	luzArena->setPropiedadesMaterial();
	glPushMatrix();
		glScalef(largoPlaya*supBorde->getEscalado(),largoPlaya*supBorde->getEscalado() ,1.0);
		arena->dibujar();
	glPopMatrix();

	glPushMatrix();
		glScalef(largoPlaya,largoPlaya,1.0);
		glTranslatef(0.0,0.0, - playaBorde->getAlturaMax());
		playaBorde->dibujar();
	glPopMatrix();

	glPopMatrix();
}

Isla::~Isla()
{
	delete ptos;
	delete supBorde;
	delete arena;
	delete pasto;
	delete playaBorde;
	this->eliminarLuces();
}

void Isla::levantarCurva( string nombreArchPtoCtrl )
{
	ptos = new PuntosControl;
	ArchivoPtosControl::cagarPtosControl( ptos, nombreArchPtoCtrl );
}

void Isla::calcularCentroIsla()
{
	float zc; //guarda la coordenada z del centro de la isla, pero no me importa porq es 0

	CalculadoraBSpline::calcularCentro( ptos, xc, yc, zc, paso); //guarda q esta mal porq la curva no esta cerra, y siii, es obvio cuando vuelva a leer estre comentario no voy a saber de q estoy hablando
	xc *= supBorde->getEscalado();
	yc *= supBorde->getEscalado();
}

float Isla::getAltura()
{
	return supBorde->getAlturaMax();
}
