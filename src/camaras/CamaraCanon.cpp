/*
 * CamaraCanon.cpp
 *
 *  Created on: 08/01/2012
 *      Author: amalia
 */

#include "CamaraCanon.h"

CamaraCanon::CamaraCanon(const TBarco *tbarco, const TCanon *tcanon): Camara ( 0.0, 45.0, 4.0)
{
	posBarco = tbarco;
	posCanon = tcanon;
}

CamaraCanon::~CamaraCanon() {}

void CamaraCanon::setEye()
{
	float x, y, z, fx, fy, fz/*, radio*/;

	posCanon->getTPto( x, y, z, fx, fy, fz);
	posBarco->getTPto(fx, fy, fz, x, y, z);

	//	radio = sqrt(x^2 + y^2);


	this->setCoordEye(x, y, z+5);
}

void CamaraCanon::setAt()
{
	float x, y, z;

x = y = z = 0.0;
	this->setCoordAt( x, y, z);
}
