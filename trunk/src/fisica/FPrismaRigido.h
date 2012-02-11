/*
 * PrismaFisico.h
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#ifndef FPRISMARIGIDO_H_
#define FPRISMARIGIDO_H_

#include "../grafica/FuncOpenGL.h"

#include "CuerpoFisico.h"

class FPrismaRigido: public CuerpoFisico {
public:
	FPrismaRigido(	btBoxShape* shape, float posX, float posY, float posZ, float masa );
	virtual ~FPrismaRigido();

protected:
	void aplicarTransformada() const;
};

#endif /* PRISMAFISICO_H_ */
