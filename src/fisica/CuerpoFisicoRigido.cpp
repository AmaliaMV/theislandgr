/*
 * PrismaFisico.cpp
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#include "CuerpoFisicoRigido.h"

CuerpoFisicoRigido::CuerpoFisicoRigido( btBoxShape* shape, float posX, float posY, float posZ, float masa )
{
	btVector3 fallInertia(0,0,0);
	shape->calculateLocalInertia( masa, fallInertia );

	btTransform startTransform;
	startTransform.setIdentity();
	// aplico transformacion inicial
	startTransform.setOrigin(btVector3(btScalar(posX),btScalar(posY),btScalar(posZ)));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(masa, fallMotionState, shape, fallInertia);

	cuerpo = new btRigidBody(fallRigidBodyCI);// creo el cuerpo rigido
	cuerpo->setFriction(btScalar(0.1)); // defino factor de friccion
}

CuerpoFisicoRigido::~CuerpoFisicoRigido()
{
	delete cuerpo->getMotionState();
	delete cuerpo;
}

void CuerpoFisicoRigido::agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	dynamicsWorld->addRigidBody(cuerpo); // agrego la caja a la simulacion
}

void CuerpoFisicoRigido::aplicarTransformada() const
{
	btTransform trans;
	cuerpo->getMotionState()->getWorldTransform(trans); // obtengo la transformacion de la caja

	btVector3 pos=trans.getOrigin();
	glTranslatef(pos.getX(),pos.getY(),pos.getZ());// unico centro de masa de la caja

	btVector3 axis=trans.getRotation().getAxis(); // aplico orientacion
	glRotatef(trans.getRotation().getAngle()*360/6.2832f,axis.getX(),axis.getY(),axis.getZ());
}
