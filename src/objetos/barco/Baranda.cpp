/*
 * Baranda.cpp
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#include "Baranda.h"

const unsigned int Baranda::cantPalitos = 10;

Baranda::Baranda()
{
	palito = new PaloDeBaranda ("texturas/maderaBaranda.bmp");
//	this->displayList();

}

void Baranda::displayList()
{
	float x, y, tita, pasoTita;

	pasoTita = ( CteBarco::TITA_MAX - CteBarco::TITA_MIN )/ cantPalitos;

//	glNewList( this->getIdDisplayList(), GL_COMPILE);
	for ( tita = CteBarco::TITA_MIN; tita <= CteBarco::TITA_MAX; tita += pasoTita )
	{
		x = ( CteBarco::RADIO_X - palito->getLado()/2 )* Matematica::cosHex( tita );
		y = ( CteBarco::RADIO_Y - palito->getLado()/2 )* Matematica::sinHex( tita );

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
