/*
 * PrismaFisico.cpp
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#include "FPrismaRigido.h"

FPrismaRigido::FPrismaRigido( btBoxShape* shape, float posX, float posY, float posZ, float masa )
	: CuerpoFisico (shape, posX, posY, posZ, masa)
{
	this->getCuerpo()->setFriction(btScalar(0.1)); // defino factor de friccion
}

FPrismaRigido::~FPrismaRigido() {}

void FPrismaRigido::aplicarTransformada() const
{
	btTransform trans;
	this->getCuerpo()->getMotionState()->getWorldTransform(trans); // obtengo la transformacion de la caja

	btVector3 pos=trans.getOrigin();
	glTranslatef(pos.getX(),pos.getY(),pos.getZ());// unico centro de masa de la caja

	btVector3 axis=trans.getRotation().getAxis(); // aplico orientacion
	glRotatef(trans.getRotation().getAngle()*360/6.2832f,axis.getX(),axis.getY(),axis.getZ());
}
