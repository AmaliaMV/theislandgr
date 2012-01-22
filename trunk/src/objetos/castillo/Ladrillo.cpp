/*
 * Ladrillo.cpp
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#include "Ladrillo.h"

const float Ladrillo::MASA_PUERTA = 1.0;
Ladrillo::Ladrillo( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ,
		Coord_text* coord_text)
	:PrismaConTexturaCuad( textura, shape->getHalfExtentsWithMargin().getZ()*2,
			shape->getHalfExtentsWithMargin().getY()*2,
			shape->getHalfExtentsWithMargin().getX()*2, coord_text ),
	 CuerpoFisicoRigido( shape, posX, posY, posZ, MASA_PUERTA)
{

}

Ladrillo::~Ladrillo()
{

}

void Ladrillo::dibujar() const
{
	glPushMatrix();
		CuerpoFisicoRigido::aplicarTransformada();
		PrismaConTexturaCuad::dibujar();
	glPopMatrix();
}
