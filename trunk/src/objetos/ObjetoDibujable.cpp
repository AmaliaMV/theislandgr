/*
 * ObjetoDibujable.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "ObjetoDibujable.h"

ObjetoDibujable::ObjetoDibujable()
{
	this->idDisplayList = FuncOpenGL::pedirIdDisplayList();
}

ObjetoDibujable::~ObjetoDibujable()
{
	FuncOpenGL::liberarIdDisplayList( idDisplayList );
}

void ObjetoDibujable::dibujar() const
{
	glCallList( idDisplayList );
}

void ObjetoDibujable::compilarDisplayList() const
{
	glNewList(idDisplayList, GL_COMPILE);
		this->displayList();
	glEndList();
}
