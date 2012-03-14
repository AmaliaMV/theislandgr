/*
 * Puerta.cpp
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#include "Puerta.h"

const float Puerta::MASA_PUERTA = 4.0;

Puerta::Puerta( string nomTextPuerta, string nomTextMarco, btBoxShape* shape, float posX, float posY, float posZ )
	: ObjetoDibujable(),
	  FPrismaRigido( shape, posX, posY, posZ, MASA_PUERTA)
{
	this->lado = new LadoPrismaConTextura ( nomTextMarco,
			shape->getHalfExtentsWithMargin().getX()*2,
			shape->getHalfExtentsWithMargin().getY()*2,
			shape->getHalfExtentsWithMargin().getZ()*2);
	this->cara = new RectanguloConTextura ( nomTextPuerta, shape->getHalfExtentsWithMargin().getY()*2,
			shape->getHalfExtentsWithMargin().getZ()*2);

	this->compilarDisplayList();
}

Puerta::~Puerta()
{
	delete lado;
	delete cara;
}

void Puerta::displayList() const
{
	glPushMatrix();
		glRotatef ( 90, 0.0, 1.0, 0.0 );
		this->lado->dibujar();
		glPushMatrix();
			glTranslatef( 0.0, 0.0, this->lado->getAltura()/2);
			glNormal3f(0.0, 0.0, 1.0);
			this->cara->dibujar();
		glPopMatrix();
		glPushMatrix();
			glTranslatef( 0.0, 0.0, -this->lado->getAltura()/2);
			glNormal3f(0.0, 0.0, -1.0);
			this->cara->dibujar();
		glPopMatrix();
	glPopMatrix();
}

void Puerta::dibujar() const
{
	glPushMatrix();
		FPrismaRigido::aplicarTransformada();
		ObjetoDibujable::dibujar();
	glPopMatrix();
}
