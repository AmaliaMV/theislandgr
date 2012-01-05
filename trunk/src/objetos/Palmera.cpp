/*
 * Palmera.cpp
 *
 *  Created on: 10/X09/2011
 *      Author: amalia
 */

#include "Palmera.h"

Palmera::Palmera( string nombreTextura )
	: ODTextura ( new Textura32( nombreTextura ) )
{
	this->TAM_INDICE = 4;
	this->TAM_PTOS = 4;

	this->init( TAM_PTOS, TAM_INDICE, GL_QUADS );
}

void Palmera::generarCoordPtos()
{
	const float tamY = 10.0;
	const float tamX = tamY * 480.0 /1024.0;
	unsigned int pos = 0 ;

	for ( float j = 0; j <= tamY; j+=tamY )
		for ( float i = tamX; i >= tamX; i-=2*tamX )
		{
			ptos [ pos++ ] = 0.0;
			ptos [ pos++ ] = i;
			ptos [ pos++ ] = j;
		}
}

void Palmera::generarIndice()
{
	for ( unsigned int pos = 0; pos < TAM_INDICE; pos++ )
		indice [ pos ] = pos;
}

void Palmera::generarCoodText()
{
	//	float coordText[4][2] = { { 0.0, 340.0 /1024.0 },
	//							  { 1.0, 340.0 /1024.0 },
	//							  { 1.0, 674.0 /1024.0 },
	//							  { 0.0, 674.0 /1024.0 }// hardcode
	text[0] =  340.0 /1024.0;
	text[1] =  0.0;

	text[2] =  674.0 /1024.0;
	text[3] =  0.0;

	text[4] =  674.0 /1024.0;
	text[5] =  1.0;

	text[6] =  340.0 /1024.0;
	text[7] =  1.0;
}

void Palmera::displayList( )
{
	glEnable( GL_BLEND );
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f ( 1.0, 1.0, 1.0, 1.0 );
		Textura::habilitar();
			this->getTextura()->usar();
			glDrawElements (GL_QUADS, this->getCantTamIndice() , GL_UNSIGNED_INT, indice);
		Textura::deshabilitar();
		glDisable( GL_BLEND );

	glEndList();
}

Palmera::~Palmera() {}

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
