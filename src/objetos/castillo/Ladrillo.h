/*
 * Ladrillo.h
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#ifndef LADRILLO_H_
#define LADRILLO_H_

#include "ConstantesCastillo.h"

#include "../geometricos/PrismaConTexturaCuad.h"

#include "../../fisica/CuerpoFisicoRigido.h"

class Ladrillo: public PrismaConTexturaCuad, public CuerpoFisicoRigido
{
public:
	Ladrillo( Textura* textura, btBoxShape* shape, float posX, float posY, float posZ,
			Coord_text* coord_textXPos, Coord_text* coord_textXNeg, Coord_text* coord_textYPos,
			Coord_text* coord_textYNeg );
	void dibujar() const;
	virtual ~Ladrillo();

private:
	static const float MASA_PUERTA;
};

#endif /* LADRILLO_H_ */
