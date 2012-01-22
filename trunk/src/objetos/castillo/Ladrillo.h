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

#include "../../fisica/CuerpoFisicoRigido.h"

class Ladrillo: public PrismaConTextura, public CuerpoFisicoRigido
{
public:
	Ladrillo( string nombreTextura, btBoxShape* shape, float posX, float posY, float posZ );
	void dibujar() const;
	virtual ~Ladrillo();

private:
	static const float MASA_PUERTA;
};

#endif /* LADRILLO_H_ */
