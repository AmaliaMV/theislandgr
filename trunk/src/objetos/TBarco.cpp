/*
 * TBarco.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "TBarco.h"

#define ESCALADOXYZ 0.25

TBarco::TBarco()
{
	this->angulo = 0.0;
}

TBarco::~TBarco(){}

void TBarco::ejecutar() const
{
	glTranslatef(CteMundo::RADIO_NAVEGACION * Matematica::cosHex( angulo ),
			CteMundo::RADIO_NAVEGACION * Matematica::sinHex( angulo ), 0.0);
	glScalef(ESCALADOXYZ, ESCALADOXYZ, ESCALADOXYZ);
	glTranslatef(0.0, 0.0, CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA);
	glRotatef( angulo, 0.0, 0.0, 1.0 );
}

void TBarco::incAngulo()
{
	if ( angulo > 360.0 )
		angulo = 0.0;
	angulo+= CteMundo::DELTA_ANGULO_BARCO;
}

void TBarco::getTPto( const float x, const float y, const float z, float &fx, float &fy, float &fz ) const
{
	// matriz rotacion
	fx = Matematica::cosHex(angulo) * x - Matematica::sinHex(angulo) * y;
	fy = Matematica::sinHex(angulo) * x + Matematica::cosHex(angulo) * y;

	// matriz traslacion
	fz = CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA + z;

	// matriz escalado
	fx *= ESCALADOXYZ;
	fy *= ESCALADOXYZ;
	fz *= ESCALADOXYZ;

	// matriz traslacion
	fx += CteMundo::RADIO_NAVEGACION * Matematica::cosHex( angulo );
	fy += CteMundo::RADIO_NAVEGACION * Matematica::sinHex( angulo );

//	// aplico las mismas transformaciones que al barco
//	x = CteMundo::RADIO_NAVEGACION * Matematica::cosHex( angulo );
//	y = CteMundo::RADIO_NAVEGACION * Matematica::sinHex( angulo );
//	z = 0.25 * (CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA) ;
}

float TBarco::getAngulo() const
{
	return this->angulo;
}
float TBarco::getAlturaBarco() const
{
	return (CteBarco::RADIO_Z - 2* CteMundo::NIVEL_AGUA) *  ESCALADOXYZ;
}
