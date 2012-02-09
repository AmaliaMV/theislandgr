/*
 * CamaraBarco.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "CamaraBarco.h"

CamaraBarco::CamaraBarco( const TBarco *tbarco ): Camara(180.0, 45.0, 10.0)
{
	this->setAngVMax( CteCamara::ANGULO_MAX_VERTICAL );
	this->setDistMax( CteMundo::RADIO_NAVEGACION - 5.0 );
	this->posBarco = tbarco;
}

CamaraBarco::~CamaraBarco() {}

void CamaraBarco::setEye()
{
	float fx, fy, fz;

	this->posBarco->getTPto( 0.0, 0.0, 0.0, fx, fy, fz);

	fx += this->getDist() * Matematica::cosHex ( this->getAngH()+ posBarco->getAngulo() ) * Matematica::sinHex ( this->getAngV() );
	fy += this->getDist() * Matematica::sinHex ( this->getAngH()+ posBarco->getAngulo() ) * Matematica::sinHex ( this->getAngV() );
	fz += this->getDist() * Matematica::cosHex ( this->getAngV() );

	this->setCoordEye( fx, fy, fz );
}

void CamaraBarco::setAt ()
{
	float fx, fy, fz;

	this->posBarco->getTPto( 0.0, 0.0, 0.0, fx, fy, fz);

	this->setCoordAt( fx, fy, fz );
}
void CamaraBarco::alejarCamara()
{
	this->aumentarDist( 1.0 );
}

void CamaraBarco::acercarCamara()
{
	this->disminuirDist( 1.0 );
}
