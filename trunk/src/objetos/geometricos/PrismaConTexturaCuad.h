/*
 * Prisma.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#ifndef PRISMACONTEXTURACUAD_H_
#define PRISMACONTEXTURACUAD_H_

#include "RectanguloConTextura.h"

class PrismaConTexturaCuad: public ObjetoDibujable {
public:
	PrismaConTexturaCuad( Textura* textura, float altura, float ancho, float largo, Coord_text *coord_text= new Coord_text() );
	virtual ~PrismaConTexturaCuad();

private:
	void displayList() const;

	RectanguloConTextura *caraZ;
	RectanguloConTextura *caraY;
	RectanguloConTextura *caraX;
};

#endif /* PRISMA_H_ */
