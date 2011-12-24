/*
 * Baranda.cpp
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#include "Baranda.h"

const unsigned int Baranda::cantPalitos = 10;

Baranda::Baranda():ObjetoDibujable( new Textura24("texturas/maderaBaranda.bmp"))
{
	palito = new PaloDeBaranda ("texturas/maderaBaranda.bmp");
//	this->displayList();

}

void Baranda::displayList()
{
	float x, y, tita, pasoTita;

	pasoTita = ( CteBarco::titaMax - CteBarco::titaMin )/ cantPalitos;

//	glNewList( this->getIdDisplayList(), GL_COMPILE);
	for ( tita = CteBarco::titaMin; tita <= CteBarco::titaMax; tita += pasoTita )
	{
		x = ( CteBarco::radioX - palito->getLado()/2 )* Matematica::cosHex( tita );
		y = ( CteBarco::radioY - palito->getLado()/2 )* Matematica::sinHex( tita );

		glPushMatrix();
			glTranslatef( x, y, 0.0 );
			palito->dibujar();
		glPopMatrix();
	}


//	glEndList();

}

void Baranda::dibujar()
{
	this->displayList();
}

Baranda::~Baranda()
{
	delete palito;
}
