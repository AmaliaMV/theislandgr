/*
 * EsferaRigida.cpp
 *
 *  Created on: 28/01/2012
 *      Author: amalia
 */

#include "FEsferaRigida.h"

const float FEsferaRigida::GRAVEDAD = 10.0;
const float FEsferaRigida::DELTA_TIEMPO = 0.005;
const float FEsferaRigida::MODULO_VEL0 = 50.0;

FEsferaRigida::FEsferaRigida( btSphereShape* shape, const float posX, const float posY,
		const float posZ, const float masa, const float angHCanon, const float angVCanon,
		const float angBarco, const float radio )
{
	this->initPosicion( posX, posY, posZ );
	this->initVelocidad( angHCanon, angVCanon, angBarco, radio );
	tiempo = 0.0;

	btVector3 fallInertia(0,0,0);
	shape->calculateLocalInertia( masa, fallInertia );

	btTransform startTransform;
	startTransform.setIdentity();
	// aplico transformacion inicial
	startTransform.setOrigin(btVector3(btScalar(POSICION_INICIAL[0]),btScalar(POSICION_INICIAL[1]),btScalar(POSICION_INICIAL[2])));

	btDefaultMotionState* esferaMotionState = new btDefaultMotionState(startTransform);
	btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(masa, esferaMotionState, shape, fallInertia);

	cuerpo = new btRigidBody(fallRigidBodyCI);

	// lo define  como Kinetic Rigid Body
	cuerpo->setCollisionFlags(cuerpo->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	cuerpo->setActivationState(DISABLE_DEACTIVATION);

}

FEsferaRigida::~FEsferaRigida()
{
	delete cuerpo->getMotionState();
	delete cuerpo;
	delete [] POSICION_INICIAL;
	delete [] VELOCIDAD_INICIAL;
}

void FEsferaRigida::agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld )
{
	dynamicsWorld->addRigidBody(cuerpo);
}

void FEsferaRigida::actualizar()
{
	float posX, posY, posZ;

	//Y = yInicial + tg titaI (x - xInicial) - g/2 * (x- xInicial)^2 / (2*vinicial^2 * (cos titaIncial)^2)
//	if (!detenerEsfera){
//		POSICION_INICIAL[0]+=VELOCIDAD_INICIAL[0];
//		POSICION_INICIAL[1]+=VELOCIDAD_INICIAL[1];
////	}

	posX = POSICION_INICIAL[0] + VELOCIDAD_INICIAL[0] * tiempo;
	posY = POSICION_INICIAL[1] + VELOCIDAD_INICIAL[1] * tiempo;
	posZ = POSICION_INICIAL[2] + VELOCIDAD_INICIAL[2] * tiempo - GRAVEDAD * tiempo * tiempo / 2.0;

	tiempo += DELTA_TIEMPO;

//	cout<<"posX: "<<posX<<" posY: "<<posY<<" posZ: "<<posZ<<endl;

	// actualizo la tranformacion de la esfera en la simulacion
	btTransform trans;
	trans.setIdentity();
	trans.setOrigin(btVector3(btScalar(posX),btScalar(posY),btScalar(posZ)));

	btDefaultMotionState* esferaMotionState = new btDefaultMotionState(trans);
	delete cuerpo->getMotionState();
	cuerpo->setMotionState(esferaMotionState);
}

void FEsferaRigida::aplicarTransformada() const
{
	btTransform trans;
	cuerpo->getMotionState()->getWorldTransform(trans);

	btVector3 pos=trans.getOrigin();
	glTranslatef(pos.getX(),pos.getY(),pos.getZ());
}

void FEsferaRigida::initPosicion( const float posX, const float posY, const float posZ )
{
	POSICION_INICIAL = new float [3];
	POSICION_INICIAL[0] = posX;
	POSICION_INICIAL[1] = posY;
	POSICION_INICIAL[2] = posZ;
}

void FEsferaRigida:: initVelocidad( const float angHCanon, const float angVCanon, const float angBarco, const float radio )
{
	VELOCIDAD_INICIAL = new float [3];
	float x, y;
	x = - MODULO_VEL0 * Matematica::cosHex( angVCanon ) * Matematica::cosHex( angHCanon );
	y = - MODULO_VEL0 * Matematica::cosHex( angVCanon ) * Matematica::sinHex( angHCanon );

	VELOCIDAD_INICIAL[0] = radio * Matematica::cosHex( angBarco ) + x * Matematica::cosHex( angBarco ) - y * Matematica::sinHex( angBarco );
	VELOCIDAD_INICIAL[1] = radio * Matematica::sinHex( angBarco ) + y * Matematica::cosHex( angBarco ) + x * Matematica::sinHex( angBarco );

 	VELOCIDAD_INICIAL[2] = MODULO_VEL0 * Matematica::sinHex( angVCanon );

	cout<<"velx: "<<VELOCIDAD_INICIAL[0]<<" vely: "<<VELOCIDAD_INICIAL[1]<<" velz: "<<VELOCIDAD_INICIAL[2]<<" angV: "<<angVCanon<<" angH: "<<angHCanon<<endl;
}
