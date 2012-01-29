/*
 * Prisma.cpp
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#include "PrismaConTexturaCuad.h"

PrismaConTexturaCuad::PrismaConTexturaCuad( Textura* textura, float altura, float ancho, float largo,
		Coord_text *coord_textXPos, Coord_text *coord_textXNeg,
		Coord_text *coord_textYPos, Coord_text *coord_textYNeg )
	:ObjetoDibujable()
{
	this->caraZ = new RectanguloConTextura ( textura, ancho, largo, new Coord_text(coord_textXPos) ); // le pongo las mimas coorde de text q x :p
	this->caraXPos = new RectanguloConTextura ( textura, ancho, altura, new Coord_text(coord_textXPos) ); // cambio el orden para q qde bien la textura
	this->caraXNeg = new RectanguloConTextura ( textura, ancho, altura, new Coord_text(coord_textXNeg) );
	this->caraYPos = new RectanguloConTextura ( textura, largo, altura, new Coord_text(coord_textYPos) );
	this->caraYNeg = new RectanguloConTextura ( textura, largo, altura, new Coord_text(coord_textYNeg) );

	this->compilarDisplayList();
}

PrismaConTexturaCuad::~PrismaConTexturaCuad()
{
	delete caraXPos;
	delete caraXNeg;
	delete caraYPos;
	delete caraYNeg;
	delete caraZ;
}

void PrismaConTexturaCuad::displayList() const
{
	glPushMatrix();
		glTranslatef( 0.0, 0.0, this->caraYPos->getAltura()/2);
		this->caraZ->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, 0.0, -this->caraYPos->getAltura()/2);
		this->caraZ->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( this->caraZ->getAltura()/2, 0.0, 0.0);
		glRotatef( 90.0, 0.0, 1.0, 0.0 );
		this->caraXPos->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( -this->caraZ->getAltura()/2, 0.0, 0.0);
		glScalef( 1.0, -1.0, 1.0 );
		glRotatef( 90.0, 0.0, 1.0, 0.0 );
		this->caraXNeg->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, this->caraZ->getBase()/2, 0.0);
		glScalef( -1.0, 1.0, 1.0 );
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		glRotatef( -90.0, 0.0, 0.0, 1.0 );
		this->caraYPos->dibujar();
	glPopMatrix();
	glPushMatrix();
		glTranslatef( 0.0, -this->caraZ->getBase()/2, 0.0);
		glRotatef( 90.0, 1.0, 0.0, 0.0 );
		glRotatef( -90.0, 0.0, 0.0, 1.0 );
		this->caraYNeg->dibujar();
	glPopMatrix();
}
