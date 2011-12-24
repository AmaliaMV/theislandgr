/*
 * PisoDeMirador.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef PISODEMIRADOR_H_
#define PISODEMIRADOR_H_

#include "BordePisoMirador.h"

#include "../../CirculoConTextura.h"

class PisoDeMirador: public ObjetoDibujable {
public:
	PisoDeMirador(string nombreTexturaBorde, string nombreTexturaPiso, float radio);
	virtual ~PisoDeMirador();

private:
	void displayList() const;

	float RADIO;
	float ESPESOR;

	CirculoConTextura *piso;
	BordePisoMirador *borde;

	static const unsigned int PASO = 30;
};

#endif /* PISODEMIRADOR_H_ */
