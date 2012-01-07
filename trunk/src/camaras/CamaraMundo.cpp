/*
 * CamaraMundo.cpp
 *
 *  Created on: 21/07/2011
 *      Author: Amalia
 */

#include "CamaraMundo.h"

CamaraMundo::CamaraMundo():Camara( 0.0, 45.0 )
{
	this->distancia = 20;
	this->setAngVMax( ANGULO_MAX_TITA );
}

CamaraMundo::~CamaraMundo() { }

void CamaraMundo::setEye()
{
	float x, y, z;

	x = distancia * Matematica::cosHex ( this->getAngH() ) * Matematica::sinHex ( this->getTita() );
	y = distancia * Matematica::sinHex ( this->getAngH() ) * Matematica::sinHex ( this->getTita() );
	z = distancia * Matematica::cosHex ( this->getTita() ) + 5;

	this->setCoordEye( x, y, z );
}

void CamaraMundo::setAt ()
{
	float x, y, z;

	x =  0.0;
	y =  0.0;
	z = distancia/3;


	this->setCoordAt( x, y, z );
}

void  CamaraMundo::alejar()
{
	this->distancia++;
}
void  CamaraMundo::acercar()
{
	this->distancia--;
}
