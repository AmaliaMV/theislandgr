/*
 * CamaraCanon.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "CamaraCanon.h"

const float CamaraCanon::ALTURA_EYE = 2.0 ;

CamaraCanon::CamaraCanon(const TBarco *tbarco, const TCanon *tcanon): Camara ( 0.0, 45.0, 10.0)
{
	posBarco = tbarco;
	posCanon = tcanon;
	this->setDistMin(-10);
}

CamaraCanon::~CamaraCanon() {}

void CamaraCanon::setEye()
{
	float x, y, z;

	x = (CteMundo::RADIO_NAVEGACION - (CteBarco::RADIO_X / this->getDist())) * Matematica::cosHex ( posBarco->getAngulo() );
	y = (CteMundo::RADIO_NAVEGACION - (CteBarco::RADIO_X / this->getDist())) * Matematica::sinHex ( posBarco->getAngulo() );
	z = posBarco->getAlturaBarco() + ALTURA_EYE;

	this->setCoordEye( x, y, z);
}

void CamaraCanon::setAt()
{
	float x, y, z, fx, fy;

	x = - CteMundo::RADIO_NAVEGACION * Matematica::cosHex ( posCanon->getCanon()->getAngH() ) * Matematica::cosHex ( posCanon->getCanon()->getAngV() );
	y = - CteMundo::RADIO_NAVEGACION * Matematica::sinHex ( posCanon->getCanon()->getAngH() ) * Matematica::cosHex ( posCanon->getCanon()->getAngV() );

	fx = CteMundo::RADIO_NAVEGACION * Matematica::cosHex( posBarco->getAngulo() ) + x * Matematica::cosHex( posBarco->getAngulo() ) - y * Matematica::sinHex( posBarco->getAngulo() );
	fy = CteMundo::RADIO_NAVEGACION * Matematica::sinHex( posBarco->getAngulo() ) + y * Matematica::cosHex( posBarco->getAngulo() ) + x * Matematica::sinHex( posBarco->getAngulo() );

	z = posBarco->getAlturaBarco() + posCanon->getAltura() + CteMundo::RADIO_NAVEGACION * Matematica::sinHex ( posCanon->getCanon()->getAngV() );

	this->setCoordAt( fx, fy, z);
}

void CamaraCanon::alejarCamara()
{
	this->aumentarDist(1.0);
}

void CamaraCanon::acercarCamara()
{
	this->disminuirDist(1.0);
}

