/*
 * Fisica.cpp
 *
 *  Created on: 17/01/2012
 *      Author: amalia
 */

#include "Fisica.h"

Fisica::Fisica()
{
	this->inicializar();
}

Fisica::~Fisica()
{
	this->finalizar();
}

void Fisica::inicializar()
{
	// Inicializacion del motor de fisica
	broadphase = new btDbvtBroadphase();
	collisionConfiguration = new btDefaultCollisionConfiguration();
	dispatcher = new btCollisionDispatcher(collisionConfiguration);
	solver = new btSequentialImpulseConstraintSolver;

	dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher,broadphase,solver,collisionConfiguration);
	dynamicsWorld->setGravity(btVector3(0,0,-10.0));

	// Definimos plano del suelo - Cuerpo rigido estatico (masa=0)
	btCollisionShape* groundShape = new btStaticPlaneShape(btVector3(0,0,1),1);// parametros: normal {x,y,z} , espesor o altura
	collisionShapes.push_back(groundShape);
 	///create a few basic rigid bodies
// 	btBoxShape* box = new btBoxShape(btVector3(btScalar(110.),btScalar(1.),btScalar(110.)));
// 	btCollisionShape* groundShape = box;

	btDefaultMotionState* groundMotionState = new btDefaultMotionState(btTransform(btQuaternion(0,0,0,1),btVector3(0,0,-1)));
	//los 2 vectores representan la orientacion (x,y,z,w) y traslacion (x,y,z) del objeto suelo,
	// traslacion es (0,-1,0) para compensar el espesor que es 1, asi el lado superior del piso queda en Y=0

	btRigidBody::btRigidBodyConstructionInfo groundRigidBodyCI(0,groundMotionState,groundShape,btVector3(0,0,0));
	groundRigidBody = new btRigidBody(groundRigidBodyCI);
	groundRigidBody->setFriction(1.0);
	dynamicsWorld->addRigidBody(groundRigidBody);

	/*si objeto es estatico, la masa es 0, sino es distinto de cero y hay q calcularle la inercia*/


}

void Fisica::addCollisionShape(btCollisionShape *collisionShape)
{
	collisionShapes.push_back(collisionShape);
}

void Fisica::finalizar()
{
	//remove the rigidbodies from the dynamics world and delete them
	delete groundRigidBody->getMotionState();
	delete groundRigidBody;

	//delete collision shapes
	for (int j=0;j<collisionShapes.size();j++)
	{
		btCollisionShape* shape = collisionShapes[j];
		delete shape;
	}
	collisionShapes.clear();

	delete dynamicsWorld;
	delete solver;
	delete broadphase;
	delete dispatcher;
	delete collisionConfiguration;
}

void Fisica::reiniciar()
{
	this->finalizar();
	this->inicializar();
}

btDiscreteDynamicsWorld* Fisica::getMundoFisico()
{
	return this->dynamicsWorld;
}
