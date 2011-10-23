/*
 * Pasto.h
 *
 *  Created on: 14/08/2011
 *      Author: amalia
 */

#ifndef PASTO_H_
#define PASTO_H_

#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/curva/CalculadoraBSpline.h"

#include "SuperficeBSlpineChata.h"

class Pasto: public ObjetoDibujable {
public:
	Pasto ( PuntosControl *ptos, string nombreArchText, const int paso );
	virtual ~Pasto();

private:

	void displayList( const int paso ) const;
	SuperficeBSlpineChata *superficie;
};

#endif /* PASTO_H_ */
