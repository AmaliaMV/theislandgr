/*
 * CajaCanon.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#ifndef CAJACANON_H_
#define CAJACANON_H_

#include "../DecoradorBarco.h"

#include "../../geometricos/LadoPrismaConTextura.h"
#include "../../geometricos/LadoCilindroConTextura.h"

class CajaCanon: public ObjetoDibujable, public DecoradorBarco {
public:
	CajaCanon( string nombreTextura, float alto, float ancho, float largo,
			EstrategiaTransformacion *transformacion, ComponenteBarco *aDecorar);
	virtual ~CajaCanon();

protected:
	void dibujar();

private:
	void displayList() const;

	LadoPrismaConTextura *caja;
	LadoCilindroConTextura *eje;
};

#endif /* CAJACANON_H_ */
