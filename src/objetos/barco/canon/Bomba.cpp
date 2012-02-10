/*
 * Bomba.cpp
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#include "Bomba.h"

const float Bomba::MASA_BOMBA = 10.0;

Bomba::Bomba( Textura* textura, btSphereShape* shape, float posX, float posY, float posZ )
	:EsferaConTextura( textura, shape->getMargin() ),
	 FEsferaRigida( shape, posX, posY, posZ, MASA_BOMBA )
{
}

Bomba::~Bomba()
{
}

void Bomba::dibujar() const
{
	glPushMatrix();
		FEsferaRigida::aplicarTransformada();
		EsferaConTextura::dibujar();
	glPopMatrix();
}
