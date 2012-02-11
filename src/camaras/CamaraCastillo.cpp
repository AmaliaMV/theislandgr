/*
 * CamaraCastillo.cpp
 *
 *  Created on: 09/02/2012
 *      Author: amalia
 */

#include "CamaraCastillo.h"

CamaraCastillo::CamaraCastillo(): Camara( 180.0, 89.0, 10.0 )
{
	this->setAngVMax( 95.0 );
	this->setAngVMin( 20.0 );

	this->setDistMax( CteMundo::RADIO_MUNDO - 10.0 );
}

CamaraCastillo::~CamaraCastillo(){}

void CamaraCastillo::setEye()
{
	this->setCoordEye( CteCamara::POS_X_EYE_CAM_CASTILLO, CteCamara::POS_Y_EYE_CAM_CASTILLO, CteMundo::ALTURA_ISLA + 6.0 );
}

void CamaraCastillo::setAt ()
{
	float x, y, z;

	x = CteCamara::POS_X_EYE_CAM_CASTILLO + this->getDist() * Matematica::cosHex ( this->getAngH() );
	y = CteCamara::POS_Y_EYE_CAM_CASTILLO +  this->getDist() * Matematica::sinHex ( this->getAngH() );
	z = CteMundo::ALTURA_ISLA + this->getDist() * Matematica::cosHex ( this->getAngV() ) + 6.0;

	this->setCoordAt( x, y, z );
}

void CamaraCastillo::alejarCamara()
{
	this->aumentarDist(1.0);
}

void CamaraCastillo::acercarCamara()
{
	this->disminuirDist(1.0);
}
