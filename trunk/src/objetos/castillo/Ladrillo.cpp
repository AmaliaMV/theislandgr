/*
 * Ladrillo.cpp
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#include "Ladrillo.h"

Ladrillo::Ladrillo( string nombreTextura, float longZ, float longY, float longX, float posX, float posY, float posZ )
	: PrismaConTextura( nombreTextura, longZ, longY, longX )
{
	btCollisionShape* cajaShape = new  btBoxShape( btVector3( longX / 2.0, longY / 2.0 , longZ / 2.0 ));
	btScalar mass = 1.0;
	btVector3 fallInertia(0,0,0);
	cajaShape->calculateLocalInertia( mass, fallInertia );

	btTransform startTransform;
	startTransform.setIdentity();
	// aplico transformacion inicial
	startTransform.setOrigin(btVector3(btScalar(posX),btScalar(posY),btScalar(posZ)));

	btDefaultMotionState* fallMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass,fallMotionState,cajaShape,fallInertia);

	ladrillo = new btRigidBody(fallRigidBodyCI);// creo el cuerpo rigido
	ladrillo->setFriction(btScalar(0.1)); // defino factor de friccion
}

Ladrillo::~Ladrillo()
{
	delete ladrillo;
}

void Ladrillo::dibujar() const
{
	glPushMatrix();
		btTransform trans;
		ladrillo->getMotionState()->getWorldTransform(trans); // obtengo la transformacion de la caja

		btVector3 pos=trans.getOrigin();
		glTranslatef(pos.getX(),pos.getY(),pos.getZ());// unico centro de masa de la caja

		btVector3 axis=trans.getRotation().getAxis(); // aplico orientacion
		glRotatef(trans.getRotation().getAngle()*360/6.2832f,axis.getX(),axis.getY(),axis.getZ());

		PrismaConTextura::dibujar();
	glPopMatrix();
}

void Ladrillo::agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	dynamicsWorld->addRigidBody(ladrillo); // agrego la caja a la simulacion
}
