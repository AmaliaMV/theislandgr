/*
 * PrismaFisico.h
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#ifndef CUERPOFISICORIGIDO_H_
#define CUERPOFISICORIGIDO_H_

#include "../grafica/FuncOpenGL.h"

#include "Fisica.h"

class CuerpoFisicoRigido {
public:
	CuerpoFisicoRigido(	btBoxShape* shape, float posX, float posY, float posZ, float masa );
	virtual ~CuerpoFisicoRigido();
	void agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld );
	virtual void dibujar() const = 0;

protected:
	void aplicarTransformada() const;

private:
	btRigidBody* cuerpo;
};

#endif /* PRISMAFISICO_H_ */
