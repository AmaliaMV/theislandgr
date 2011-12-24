/*
 * BarcoBasico.cpp
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#include "BarcoBasico.h"

BarcoBasico::BarcoBasico( EstrategiaTransformacion *transformacion, string texturaCasco,
		string texturaPiso )
	:ComponenteBarco( transformacion ),	ObjetoDibujable()
{
	casco = new CascoDeBarco ( texturaCasco );
	piso = new PisoDeBarco ( texturaPiso );

	this->compilarDisplayList();
}

BarcoBasico::~BarcoBasico()
{
	delete casco;
	delete piso;
}

void BarcoBasico::displayList() const
{
	casco->dibujar();
	piso->dibujar();
}

void BarcoBasico::dibujar()
{
	ObjetoDibujable::dibujar();
}

