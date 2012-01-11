/*
 * CamaraCanon.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "CamaraCanon.h"

CamaraCanon::CamaraCanon(const TBarco *tbarco, const TCanon *tcanon): Camara ( 0.0, 45.0, 2.0)
{
	posBarco = tbarco;
	posCanon = tcanon;
	this->setDistMin(-10);
}

CamaraCanon::~CamaraCanon() {}

void CamaraCanon::setEye()
{
	float x, y, z, fx, fy, fz;

	x = - 2 * CteBarco::RADIO_X / 3;
	y = 0.0;
	z = 7.0;

	posBarco->getTPto( x, y, z, fx, fy, fz);

/*
	x += this->getDist() * Matematica::cosHex ( posBarco->getAngulo() ) * Matematica::sinHex ( this->getAngV() );
	y += this->getDist() * Matematica::sinHex ( posBarco->getAngulo() ) * Matematica::sinHex ( this->getAngV() );
*/
	//fz += 1.0 /*this->getDist() * Matematica::cosHex ( this->getAngV() )*/ ;

	this->setCoordEye( fx, fy, fz);
//	cout<<"eye: x: "<< fx << " y: "<< fy<<" z: "<<fz<<endl;
}

void CamaraCanon::setAt()
{
	float x, y, z, fx, fy, fz;

	x = y = z = 0.0;

	posCanon->getTPto( x, y, z, fx, fy, fz);
//	cout<<"at antes del cos x: "<< fx << " y: "<<fy<<" z: "<<fz<<endl;

	fx += CteMundo::RADIO_NAVEGACION */*this->getDist() **/ Matematica::cosHex ( posCanon->getCanon()->getAngH() ) * Matematica::sinHex ( posCanon->getCanon()->getAngV() );
	fy += CteMundo::RADIO_NAVEGACION */*this->getDist() * */Matematica::sinHex ( posCanon->getCanon()->getAngH() ) * Matematica::sinHex ( posCanon->getCanon()->getAngV() );
	fz += posBarco->getAlturaBarco() * /*CteMundo::RADIO_NAVEGACION *this->getDist() **/ Matematica::cosHex ( posCanon->getCanon()->getAngV() );

	this->setCoordAt( -fx, -fy, fz);
	cout<<"at: -x: "<< -fx << " -y: "<<-fy<<" z: "<<fz<<endl;
}

void  CamaraCanon::alejarCamara()
{
	this->aumentarDist(1.0);
}
void  CamaraCanon::acercarCamara()
{
	this->disminuirDist(1.0);
}
