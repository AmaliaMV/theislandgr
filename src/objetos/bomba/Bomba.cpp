/*
 * Bomba.cpp
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#include "Bomba.h"

const float Bomba::MASA_BOMBA = 10.0;

Bomba::Bomba( Textura* textura, btSphereShape* shape, const float posX, const float posY,
		const float posZ , const float angHCanon, const float angVCanon, const float angBarco,
		const float radioDistancia )
	:EsferaConTextura( textura, shape->getMargin() ),
	 FEsferaRigida( shape, posX, posY, posZ, MASA_BOMBA, angHCanon, angVCanon, angBarco, radioDistancia )
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
