/*
 * Pasto.cpp
 *
 *  Created on: 14/08/2011
 *      Author: amalia
 */

#include "Pasto.h"

Pasto::Pasto( PuntosControl *ptos, string nombreTextura, const int paso ): ObjetoDibujable ( new Textura24(nombreTextura) )
{
	superficie 	= new SuperficeBSlpineChata( ptos );

	this->displayList( paso );
}

Pasto::~Pasto()
{
	delete superficie;
}

void Pasto::displayList( const int paso ) const
{
	float *ptos, *coordText;
	GLuint *vertIndice;

	ptos = this->superficie->generarPtos( paso );
	vertIndice = this->superficie->generarIndice();
	coordText = this->superficie->generarCoordText( paso );

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, coordText);

		glNewList( this->getIdDisplayList(), GL_COMPILE);
			Textura::habilitar();
			this->getTextura()->usar();
			glColor3f(1.0, 1.0, 1.0);
			glDrawElements (GL_TRIANGLE_FAN, superficie->getCantPtos(), GL_UNSIGNED_INT, vertIndice);
			Textura::deshabilitar();
		glEndList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete []ptos;
	delete []vertIndice;
	delete []coordText;
}
