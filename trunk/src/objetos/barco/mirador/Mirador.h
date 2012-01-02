/*
 * Mirador.h
 *
 *  Created on: 29/11/2011
 *      Author: amalia
 */

#ifndef MIRADOR_H_
#define MIRADOR_H_

#include "PisoDeMirador.h"

#include "../DecoradorBarco.h"

#include "../../geometricos/LadoCilindroConTextura.h"
#include "../../geometricos/ToroideConTextura.h"

class Mirador: public ObjetoDibujable, public DecoradorBarco {
public:
	Mirador( string nombreTexturaBorde, string nombreTexturaPiso, string nombreTexturaBaranda, float radio,
			EstrategiaTransformacion* transformacion, ComponenteBarco* aDecorar );
	virtual ~Mirador();

protected:
	void dibujar();

private:
	void displayList() const;
	void dibujarBaranda() const;

	PisoDeMirador *piso;
	LadoCilindroConTextura *baranda;
	ToroideConTextura *pasamano;

	unsigned int CANT_PALITOS;
	float RADIO;
};

#endif /* MIRADOR_H_ */
