/*
 * PisoDeMirador.cpp
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#include "PisoDeMirador.h"

PisoDeMirador::PisoDeMirador( string nombreTexturaBorde, string nombreTexturaPiso, float radio )
	: ObjetoDibujable()
{
	this->RADIO = radio;
	this->ESPESOR = 0.2;

	this->piso = new CirculoConTextura ( nombreTexturaPiso, this->RADIO );
	this->borde = new BordePisoMirador ( nombreTexturaBorde, this->RADIO, this->ESPESOR );

	this->displayList();
}

PisoDeMirador::~PisoDeMirador()
{
	delete this->piso;
	delete this->borde;
}

void PisoDeMirador::displayList()
{
	glNewList(this->getIdDisplayList(), GL_COMPILE);

		glColor3f (1.0, 1.0, 1.0);

		this->piso->dibujar();
		this->borde->dibujar();
		glPushMatrix();
			glTranslatef(0.0, 0.0, ESPESOR);
			this->piso->dibujar();
		glPopMatrix();

	glEndList();
}
