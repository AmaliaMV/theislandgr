/*
 * Mirador.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef MIRADOR_H_
#define MIRADOR_H_

#include "PisoDeMirador.h"

#include "../../CilindroConTextura.h"
#include "../../ToroideConTextura.h"

class Mirador: public ObjetoDibujable {
public:
	Mirador(string nombreTexturaBorde, string nombreTexturaPiso, string nombreTexturaBaranda,
			float radio);
	virtual ~Mirador();

private:
	void displayList() const;
	void dibujarBaranda() const;

	PisoDeMirador *piso;
	CilindroConTextura *baranda;
	ToroideConTextura *pasamano;

	unsigned int CANT_PALITOS;
	float RADIO;
};

#endif /* MIRADOR_H_ */
