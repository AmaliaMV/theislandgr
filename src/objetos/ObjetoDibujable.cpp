/*
 * ObjetoDibujable.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "ObjetoDibujable.h"

ObjetoDibujable::ObjetoDibujable( Textura *textura )
{
	this->idDisplayList = FuncOpenGL::pedirIdDisplayList();
	this->textura = textura;
}

ObjetoDibujable::~ObjetoDibujable()
{
	delete textura;
	FuncOpenGL::liberarIdDisplayList( idDisplayList );
}

GLuint ObjetoDibujable::getIdDisplayList() const
{
	return this->idDisplayList;
}

const Textura* ObjetoDibujable::getTextura() const
{
	return textura;
}

void ObjetoDibujable::dibujar()
{
	glCallList(this->getIdDisplayList());
}
