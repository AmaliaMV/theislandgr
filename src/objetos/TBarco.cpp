/*
 * TBarco.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "TBarco.h"

TBarco::TBarco()
{
	this->angulo = 0.0;
}

TBarco::~TBarco(){}

void TBarco::ejecutar() const
{
	glTranslatef(CteMundo::RADIO_NAVEGACION * Matematica::cosHex( angulo ),
			CteMundo::RADIO_NAVEGACION * Matematica::sinHex( angulo ), 0.0);
	glScalef(0.25, 0.25, 0.25);
	glTranslatef(0.0, 0.0, CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA);
	glRotatef( angulo, 0.0, 0.0, 1.0 );
}

void TBarco::incAngulo()
{
	if ( angulo > 360.0 )
		angulo = 0.0;
	angulo+= CteMundo::DELTA_ANGULO;
}

void TBarco::getPosicionBarco( float &x, float &y, float &z ) const
{
	// aplico las mismas transformaciones que al barco
	x = CteMundo::RADIO_NAVEGACION * Matematica::cosHex( angulo );
	y = CteMundo::RADIO_NAVEGACION * Matematica::sinHex( angulo );
	z = 0.25 * (CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA) ;
}
