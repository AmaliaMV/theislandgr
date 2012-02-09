/*
 * PrismaFisico.h
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#ifndef FPRISMARIGIDO_H_
#define FPRISMARIGIDO_H_

#include "../grafica/FuncOpenGL.h"

#include "Fisica.h"

class FPrismaRigido {
public:
	FPrismaRigido(	btBoxShape* shape, float posX, float posY, float posZ, float masa );
	virtual ~FPrismaRigido();
	void agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld );
	virtual void dibujar() const = 0;

protected:
	void aplicarTransformada() const;

private:
	btRigidBody* cuerpo;
};

#endif /* PRISMAFISICO_H_ */
