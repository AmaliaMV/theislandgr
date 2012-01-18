/*
 * Fisica.h
 *
 *  Created on: 17/01/2012
 *      Author: amalia
 */

#include <btBulletDynamicsCommon.h>

#ifndef FISICA_H_
#define FISICA_H_

class Fisica {
public:
	Fisica();
	void reiniciar();
	void addCollisionShape(btCollisionShape *collisionShape);
	virtual ~Fisica();
	btDiscreteDynamicsWorld* getMundoFisico();

private:
	void inicializar();
	void finalizar();

    btBroadphaseInterface* broadphase;
    btDefaultCollisionConfiguration* collisionConfiguration;
    btCollisionDispatcher* dispatcher;
    btSequentialImpulseConstraintSolver* solver;
    btAlignedObjectArray<btCollisionShape*> collisionShapes;
    btDiscreteDynamicsWorld* dynamicsWorld;
    btRigidBody* groundRigidBody;
};

#endif /* FISICA_H_ */
