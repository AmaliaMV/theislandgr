/*
 * CamaraBarco.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "CamaraBarco.h"

CamaraBarco::CamaraBarco( const TBarco *tbarco ): Camara(0.0, 45.0, 10.0)
{
	this->setAngVMax( CteCamara::ANGULO_MAX_VERTICAL );
	this->setDistMax( CteMundo::RADIO_NAVEGACION - 5.0 );
	this->posBarco = tbarco;
}

CamaraBarco::~CamaraBarco() {}

void CamaraBarco::setEye()
{
	float x, y, z;

	this->posBarco->getPosicionBarco( x, y, z);

	x += this->getDist() * Matematica::cosHex ( this->getAngH()+ posBarco->getAngulo() ) * Matematica::sinHex ( this->getAngV() );
	y += this->getDist() * Matematica::sinHex ( this->getAngH()+ posBarco->getAngulo() ) * Matematica::sinHex ( this->getAngV() );
	z += this->getDist() * Matematica::cosHex ( this->getAngV() );

	this->setCoordEye( x, y, z );
}

void CamaraBarco::setAt ()
{
	float x, y, z;

	this->posBarco->getPosicionBarco( x, y, z);

	this->setCoordAt( x, y, z );
}
void CamaraBarco::alejarCamara()
{
	this->aumentarDist( 1.0 );
}

void CamaraBarco::acercarCamara()
{
	this->disminuirDist( 1.0 );
}
