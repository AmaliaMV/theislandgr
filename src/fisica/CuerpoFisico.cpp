/*
 * CuerpoFisico.cpp
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#include "CuerpoFisico.h"

CuerpoFisico::CuerpoFisico( btCollisionShape* shape, float posX, float posY, float posZ, float masa )
{
	btVector3 fallInertia(0,0,0);
	if ( masa != 0 )
		shape->calculateLocalInertia( masa, fallInertia );

	btTransform startTransform;
	startTransform.setIdentity();
	// aplico transformacion inicial
	startTransform.setOrigin(btVector3(btScalar(posX),btScalar(posY),btScalar(posZ)));

	btDefaultMotionState* motionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(masa, motionState, shape, fallInertia);

	cuerpo = new btRigidBody(fallRigidBodyCI);
}

CuerpoFisico::~CuerpoFisico()
{
	delete cuerpo->getMotionState();
	delete cuerpo;
}

void CuerpoFisico::agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	dynamicsWorld->addRigidBody(cuerpo);
}

btTransform CuerpoFisico::getTransformada() const
{
	btTransform trans;
	cuerpo->getMotionState()->getWorldTransform(trans); // obtengo la transformacion de la caja

	return trans;
}

btRigidBody* CuerpoFisico::getCuerpo() const
{
	return cuerpo;
}
