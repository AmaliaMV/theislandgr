/*
 * Palmera.cpp
 *
 *  Created on: 10/X09/2011
 *      Author: amalia
 */

#include "Palmera.h"

const float Palmera::ALTURA_PALMERA = 10.0;

Palmera::Palmera( string nombreTextura )
	: ObjetoDibujable()
{
	this->imagenPalmera = new RectanguloConTextura32(nombreTextura, ALTURA_PALMERA , ALTURA_PALMERA, new Coord_text(0.0, 1.0, 0.0, 1.0));
	this->compilarDisplayList();
}

Palmera::~Palmera()
{
	delete this->imagenPalmera;
}

void Palmera::displayList() const
{
	glDisable(GL_LIGHTING);
	glPushMatrix();
		glTranslatef(0.0, 0.0, ALTURA_PALMERA / 2.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		this->imagenPalmera->dibujar();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.0, ALTURA_PALMERA / 2.0);
		glRotatef(90.0, 0.0, 0.0, 1.0);
		glRotatef(90.0, 0.0, 1.0, 0.0);
		this->imagenPalmera->dibujar();
	glPopMatrix();
	glEnable(GL_LIGHTING);
}

//void Palmera::dibujar()
//{
//	glPushMatrix();
////		glRotatef(10, 0.0, 0.0, 1.0);
////		ObjetoDibujable::dibujar();
//		glRotatef(45, 0.0, 0.0, 1.0);
//		ObjetoDibujable::dibujar();
////		glRotatef(45, 0.0, 0.0, 1.0);
//		ObjetoDibujable::dibujar();
////		glRotatef(45, 0.0, 0.0, 1.0);
////		ObjetoDibujable::dibujar();
//	glPopMatrix();
//}
