/*
 * Prisma.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "PrismaConTextura.h"

PrismaConTextura::PrismaConTextura( string nombreTextura, float altura, float ancho, float largo )
	:ObjetoDibujable()
{
	this->lado = new LadoPrismaConTextura( nombreTextura, altura, ancho, largo );
	this->cara = new RectanguloConTextura ( nombreTextura, ancho, largo );

	this->compilarDisplayList();
}

PrismaConTextura::~PrismaConTextura()
{
	delete lado;
	delete cara;
}

void PrismaConTextura::displayList() const
{
	this->lado->dibujar();
	glPushMatrix();
		glTranslatef( 0.0, 0.0, this->lado->getAltura()/2);
		this->cara->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, 0.0, -this->lado->getAltura()/2);
		this->cara->dibujar();
	glPopMatrix();

}
