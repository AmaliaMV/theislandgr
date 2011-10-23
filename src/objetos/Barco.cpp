/*
 * Barco.cpp
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#include "Barco.h"

Barco::Barco():ObjetoDibujable( new Textura24("texturas/madera4.bmp"))
{
	casco = new CascoDeBarco ("texturas/madera4.bmp");
	piso = new PisoDeBarco ("texturas/pisoBarco.bmp");
	baranda = new Baranda ();

//	this->displayList();
}

void Barco::dibujar()
{
	casco->dibujar();
	piso->dibujar();
	baranda->dibujar();

}


Barco::~Barco()
{
	delete casco;
	delete piso;
	delete baranda;
}
