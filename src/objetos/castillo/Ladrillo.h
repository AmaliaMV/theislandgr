/*
 * Ladrillo.h
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#ifndef LADRILLO_H_
#define LADRILLO_H_

#include "ConstantesCastillo.h"

#include "../geometricos/PrismaConTextura.h"

#include "../../fisica/Fisica.h"

class Ladrillo: public PrismaConTextura
{
public:
	Ladrillo( string nombreTextura, btBoxShape* shape, float posX, float posY, float posZ );
	void agregarseAlMundo( btDiscreteDynamicsWorld* dynamicsWorld );
	void dibujar() const;
	virtual ~Ladrillo();

private:

	btRigidBody* ladrillo;
};

#endif /* LADRILLO_H_ */
