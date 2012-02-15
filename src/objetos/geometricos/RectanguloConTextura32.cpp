/*
 * RectanguloConTextura32.cpp
 *
 *  Created on: 14/02/2012
 *      Author: amalia
 */

#include "RectanguloConTextura32.h"

RectanguloConTextura32::RectanguloConTextura32(string nombreTextura, float base, float altura, Coord_text *coord_text)
	: ODTextura( new Textura32(nombreTextura) )
{
	this->BASE = base;
	this->ALTURA = altura;
	this->coord_text = coord_text;

	ODTextura::init(4, 4, GL_TRIANGLE_STRIP);
}

RectanguloConTextura32::~RectanguloConTextura32()
{
	delete this->coord_text;
}

void RectanguloConTextura32::generarCoordPtos()
{
	unsigned int pos = 0;

	for ( float y = -BASE/2; y < BASE; y+=BASE  )
		for ( float x = ALTURA/2; x > -ALTURA; x-=ALTURA  )
		{
			ptos[pos++] = x;
			ptos[pos++] = y;
			ptos[pos++] = 0.0;
		}
}

void RectanguloConTextura32::generarIndice()
{
	for ( unsigned int pos = 0; pos < 4; pos++)
		indice[pos] = pos;
}

void RectanguloConTextura32::generarCoodText()
{
	text[0] = this->coord_text->ymin;
	text[1] = 1.0 - this->coord_text->xmin;

	text[2] = this->coord_text->ymax;
	text[3] = 1.0 - this->coord_text->xmin;

	text[4] = this->coord_text->ymin;
	text[5] = 1.0 - this->coord_text->xmax;

	text[6] = this->coord_text->ymax;
	text[7] = 1.0 - this->coord_text->xmax;

}

void RectanguloConTextura32::displayList() const
{
	glEnable( GL_BLEND );
	glDepthMask( GL_FALSE );
		glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA/*, GL_SRC_ALPHA*/);
		glColor4f ( 1.0, 1.0, 1.0, 1.0);
		Textura::habilitar();
			this->getTextura()->usar();
			glDrawElements (this->getModo(), this->getCantTamIndice(), GL_UNSIGNED_INT, indice);
		Textura::deshabilitar();
	glDepthMask( GL_TRUE );
	glDisable( GL_BLEND );
}
