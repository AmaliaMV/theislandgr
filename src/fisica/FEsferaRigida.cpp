/*
 * EsferaRigida.cpp
 *
 *  Created on: 28/01/2012
 *      Author: amalia
 */

#include "FEsferaRigida.h"

const float FEsferaRigida::GRAVEDAD = 10.0;
const float FEsferaRigida::DELTA_TIEMPO = 0.005;
const float FEsferaRigida::MODULO_VEL0 = 70.0;

FEsferaRigida::FEsferaRigida( btSphereShape* shape, const float posX, const float posY,
		const float posZ, const float masa, const float angHCanon, const float angVCanon,
		const float angBarco, const float radio )
	: CuerpoFisico (shape, posX, posY, posZ, masa)
{
	this->initPosicion( posX, posY, posZ );
	this->initVelocidad( angHCanon, angVCanon, angBarco, radio );
	tiempo = 0.0;

	// lo define  como Kinetic Rigid Body
	this->getCuerpo()->setCollisionFlags( this->getCuerpo()->getCollisionFlags() | btCollisionObject::CF_KINEMATIC_OBJECT);
	this->getCuerpo()->setActivationState(DISABLE_DEACTIVATION);
}

FEsferaRigida::~FEsferaRigida()
{
	delete [] POSICION_INICIAL;
	delete [] VELOCIDAD_INICIAL;
}


void FEsferaRigida::actualizar()
{
	float posX, posY, posZ;

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
	delete this->getCuerpo()->getMotionState();
	this->getCuerpo()->setMotionState(esferaMotionState);
}

void FEsferaRigida::aplicarTransformada() const
{
	btTransform trans;
	this->getCuerpo()->getMotionState()->getWorldTransform(trans);

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
	x = MODULO_VEL0 * Matematica::cosHex( angVCanon ) * Matematica::cosHex( angHCanon );
	y = MODULO_VEL0 * Matematica::cosHex( angVCanon ) * Matematica::sinHex( angHCanon );

	VELOCIDAD_INICIAL[0] = radio * Matematica::cosHex( angBarco ) + x * Matematica::cosHex( angBarco ) - y * Matematica::sinHex( angBarco );
	VELOCIDAD_INICIAL[1] = radio * Matematica::sinHex( angBarco ) + y * Matematica::cosHex( angBarco ) + x * Matematica::sinHex( angBarco );

 	VELOCIDAD_INICIAL[2] = MODULO_VEL0 * Matematica::sinHex( angVCanon );
}
