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

	this->inicializarLuz();
	this->compilarDisplayList();
}

BarcoBasico::~BarcoBasico()
{
	delete casco;
	delete piso;
	this->eliminarLuz();
}

void BarcoBasico::displayList() const
{
	casco->dibujar();
	piso->dibujar();
}

void BarcoBasico::dibujar()
{
	this->luz->setPropiedadesMaterial();
	ObjetoDibujable::dibujar();
}

void BarcoBasico::inicializarLuz()
{
	this->luz = new IluminacionMaterial(1.0, 1.0, 1.0);
}

void BarcoBasico::eliminarLuz()
{
	delete this->luz;
}
