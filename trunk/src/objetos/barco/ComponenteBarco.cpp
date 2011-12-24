/*
 * ComponenteBarco.cpp
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#include "ComponenteBarco.h"

ComponenteBarco::ComponenteBarco( EstrategiaTransformacion *transformacion )
{
	this->transformacion = transformacion;
}

ComponenteBarco::~ComponenteBarco()
{
	delete this->transformacion;
}

void ComponenteBarco::dibujarComponente()
{
	glPushMatrix();
	this->transformacion->ejecutar();
	this->dibujar();
	glPopMatrix();
}
