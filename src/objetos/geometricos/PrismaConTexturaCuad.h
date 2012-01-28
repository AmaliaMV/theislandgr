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
	PrismaConTexturaCuad( Textura* textura, float altura, float ancho, float largo, Coord_text *coord_textXPos, Coord_text *coord_textXNeg, Coord_text *coord_textYPos, Coord_text *coord_textYNeg );
	virtual ~PrismaConTexturaCuad();

private:
	void displayList() const;

	RectanguloConTextura *caraZ;
	RectanguloConTextura *caraYPos;
	RectanguloConTextura *caraYNeg;
	RectanguloConTextura *caraXPos;
	RectanguloConTextura *caraXNeg;
};

#endif /* PRISMA_H_ */
