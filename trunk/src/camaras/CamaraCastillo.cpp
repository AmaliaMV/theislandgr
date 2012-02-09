/*
 * CamaraCastillo.cpp
 *
 *  Created on: 09/02/2012
 *      Author: amalia
 */

#include "CamaraCastillo.h"

CamaraCastillo::CamaraCastillo(): Camara( 90.0, 70.0, 10.0 )
{
	this->setAngVMax( CteCamara::ANGULO_MAX_VERTICAL );
	this->setAngVMin( 15.0 );
	this->setDistMax( CteMundo::RADIO_MUNDO - 10.0 );
}

CamaraCastillo::~CamaraCastillo(){}

void CamaraCastillo::setEye()
{
//	float x, y, z;
//
//	x = this->getDist() * Matematica::cosHex ( this->getAngH() ) * Matematica::sinHex ( this->getAngV() );
//	y = this->getDist() * Matematica::sinHex ( this->getAngH() ) * Matematica::sinHex ( this->getAngV() );
//	z = this->getDist() * Matematica::cosHex ( this->getAngV() ) + 5;

	this->setCoordEye( CteCamara::POS_X_EYE_CAM_CASTILLO, CteCamara::POS_Y_EYE_CAM_CASTILLO, CteMundo::ALTURA_ISLA + 6.0 );
}

void CamaraCastillo::setAt ()
{
	float x, y, z;

//	x =  0.0;
//	y =  0.0;
//	z = this->getDist()/4;

//	x = this->getDist() * Matematica::cosHex ( this->getAngH() ) * Matematica::sinHex ( this->getAngV() );
//	y = this->getDist() * Matematica::sinHex ( this->getAngH() ) * Matematica::sinHex ( this->getAngV() );
//	z = this->getDist() * Matematica::cosHex ( this->getAngV() ) + 5;

	x = this->getDist() * Matematica::cosHex ( this->getAngH() ) /** Matematica::sinHex ( this->getAngV() )*/;
	y = this->getDist() * Matematica::sinHex ( this->getAngH() ) /** Matematica::sinHex ( this->getAngV() )*/;
	z = this->getDist() * Matematica::cosHex ( this->getAngV() ) + 6.0;


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
