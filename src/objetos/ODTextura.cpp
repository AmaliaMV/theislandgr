/*
 * ObjetoDibujable.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "ODTextura.h"

ODTextura::ODTextura( Textura *textura, bool compartida ): ObjetoDibujable()
{
	this->textura = textura;
	this->compartida = compartida;
}

ODTextura::~ODTextura()
{
	if ( compartida == false )
		delete this->textura;
}

const Textura* ODTextura::getTextura() const
{
	return this->textura;
}

void ODTextura::init( unsigned int cantPtos, unsigned int tamIndice, GLenum mode )
{
	this->cantPtos = cantPtos;
	this->tamIndice = tamIndice;
	this->mode = mode;

	this->indice = new unsigned int [ this->tamIndice ];
	this->ptos = new float [ this->cantPtos * CteObjeto::CANT_COORD_PTO];
	this->text = new float [ this->cantPtos * CteObjeto::CANT_COORD_TEXTURA];

	this->generarCoordPtos();
	this->generarCoodText();
	this->generarIndice();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glVertexPointer(CteObjeto::CANT_COORD_PTO, GL_FLOAT, 0, this->ptos);
		glTexCoordPointer(CteObjeto::CANT_COORD_TEXTURA, GL_FLOAT, 0, this->text);

			this->compilarDisplayList();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

	delete [] this->indice;
	delete [] this->ptos;
	delete [] this->text;

}
void ODTextura::displayList() const
{
	glColor3f (1.0, 1.0, 1.0);
	Textura::habilitar();
	this->getTextura()->usar();
	glDrawElements (this->mode, this->tamIndice, GL_UNSIGNED_INT, this->indice);
	Textura::deshabilitar();
}

unsigned int ODTextura::getCantPtos() const
{
	return this->cantPtos;
}
unsigned int ODTextura::getCantTamIndice() const
{
	return this->tamIndice;
}
