/*
 * CamaraMundo.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "CamaraMundo.h"

CamaraMundo::CamaraMundo():Camara( 0.0, 45.0, 20.0 )
{
	this->setAngVMax( ANGULO_MAX_TITA );
	this->setDistMax( CteMundo::RADIO_MUNDO - 5.0 );
}

CamaraMundo::~CamaraMundo() { }

void CamaraMundo::setEye()
{
	float x, y, z;

	x = this->getDist() * Matematica::cosHex ( this->getAngH() ) * Matematica::sinHex ( this->getAngV() );
	y = this->getDist() * Matematica::sinHex ( this->getAngH() ) * Matematica::sinHex ( this->getAngV() );
	z = this->getDist() * Matematica::cosHex ( this->getAngV() ) + 5;

	this->setCoordEye( x, y, z );
}

void CamaraMundo::setAt ()
{
	float x, y, z;

	x =  0.0;
	y =  0.0;
	z = this->getDist()/3;


	this->setCoordAt( x, y, z );
}

void  CamaraMundo::alejarCamara()
{
	this->aumentarDist(1.0);
}
void  CamaraMundo::acercarCamara()
{
	this->disminuirDist(1.0);
}
