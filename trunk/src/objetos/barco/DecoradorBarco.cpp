/*
 * DecoradorBarco.cpp
 *
 *  Created on: 24/12/2011
 *      Author: amalia
 */

#include "DecoradorBarco.h"

DecoradorBarco::DecoradorBarco( EstrategiaTransformacion *transformacion, ComponenteBarco *aDecorar )
	:ComponenteBarco( transformacion )
{
	this->componente = aDecorar;
}

void DecoradorBarco::dibujarComponente()
{
	this->componente->dibujarComponente();
	ComponenteBarco::dibujarComponente();
}

DecoradorBarco::~DecoradorBarco()
{
	delete this->componente;
}
