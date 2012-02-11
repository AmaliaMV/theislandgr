/*
 * CuerpoFisico.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef CUERPOFISICO_H_
#define CUERPOFISICO_H_

#include "Fisica.h"

class CuerpoFisico {
public:
	CuerpoFisico( btCollisionShape* shape, float posX, float posY, float posZ, float masa );
	void agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld );
	virtual void dibujar() const = 0;
	virtual ~CuerpoFisico();

protected:
	btRigidBody* getCuerpo() const;
	btTransform getTransformada() const;

private:
	btRigidBody* cuerpo;
};

#endif /* CUERPOFISICO_H_ */
