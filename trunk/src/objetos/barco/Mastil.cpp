/*
 * Mastil.cpp
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#include "Mastil.h"

Mastil::Mastil(string nombreTextura):ObjetoDibujable( new Textura24( nombreTextura ) )
{
	this->displayList();
}

void Mastil::displayList()
{

}

void Mastil::generarPtos ( float *ptos )
{

}
void Mastil::setIndice ( float indiceMax, unsigned int *vertIndice )
{

}
void Mastil::generarCoordText ( float *coordText, unsigned int cantFila )
{

}


Mastil::~Mastil()
{

}
