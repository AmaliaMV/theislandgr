/*
 * Puerta.h
 *
 *  Created on: 21/01/2012
 *      Author: amalia
 */

#ifndef PUERTA_H_
#define PUERTA_H_

#include "../../fisica/CuerpoFisicoRigido.h"

#include "../ObjetoDibujable.h"
#include "../geometricos/RectanguloConTextura.h"
#include "../geometricos/LadoPrismaConTextura.h"

class Puerta: public ObjetoDibujable, public CuerpoFisicoRigido {
public:
	Puerta( string nomTextPuerta, string nomTextMarco, btBoxShape* shape, float posX, float posY, float posZ );
	void dibujar() const;
	virtual ~Puerta();

private:
	void displayList() const;

	RectanguloConTextura *cara;
	LadoPrismaConTextura *lado;

	static const float MASA_PUERTA;
};

#endif /* PUERTA_H_ */
