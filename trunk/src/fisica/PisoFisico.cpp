/*
 * PisoFisico.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "PisoFisico.h"

PisoFisico::PisoFisico( btBoxShape* shape, float alturaDelPiso )
	: CuerpoFisico ( shape, -1, 0.6, alturaDelPiso - shape->getHalfExtentsWithMargin().getZ()* 2, 0 )
{
	this->getCuerpo()->setFriction(1.0);
}

PisoFisico::~PisoFisico() {}
