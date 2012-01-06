/*
 * Prisma.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#ifndef PRISMACONTEXTURA_H_
#define PRISMACONTEXTURA_H_

#include "LadoPrismaConTextura.h"
#include "RectanguloConTextura.h"

class PrismaConTextura: public ObjetoDibujable {
public:
	PrismaConTextura( string nombreTextura, float altura, float ancho, float largo );
	virtual ~PrismaConTextura();

private:
	void displayList() const;

	RectanguloConTextura *cara;
	LadoPrismaConTextura *lado;

};

#endif /* PRISMA_H_ */
