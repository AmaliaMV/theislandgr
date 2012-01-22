/*
 * Prisma.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "PrismaConTexturaCuad.h"

PrismaConTexturaCuad::PrismaConTexturaCuad( Textura* textura, float altura, float ancho, float largo, Coord_text *coord_text )
	:ObjetoDibujable()
{
	cout<<" xmin "<<coord_text->xmin<<" xmax "<<coord_text->xmax<<" ymin "<<coord_text->ymin<<" ymax "<<coord_text->ymax<<endl;
	this->caraZ = new RectanguloConTextura ( textura, ancho, largo, new Coord_text(coord_text) );
	this->caraX = new RectanguloConTextura ( textura, ancho, altura, new Coord_text(coord_text) );
	this->caraY = new RectanguloConTextura ( textura, altura, largo, new Coord_text(coord_text) );

	delete coord_text;
	this->compilarDisplayList();
}

PrismaConTexturaCuad::~PrismaConTexturaCuad()
{
	delete caraX;
	delete caraY;
	delete caraZ;
}

void PrismaConTexturaCuad::displayList() const
{
	glPushMatrix();
		glTranslatef( 0.0, 0.0, this->caraX->getAltura()/2);
		this->caraZ->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, 0.0, -this->caraX->getAltura()/2);
		this->caraZ->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( this->caraZ->getAltura()/2, 0.0, 0.0);
		glRotatef( 90.0, 0.0, 1.0, 0.0 );
		this->caraX->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( -this->caraZ->getAltura()/2, 0.0, 0.0);
		glRotatef( 90.0, 0.0, 1.0, 0.0 );
		this->caraX->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, this->caraZ->getBase()/2, 0.0);
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		this->caraY->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, -this->caraZ->getBase()/2, 0.0);
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		this->caraY->dibujar();
	glPopMatrix();
}
