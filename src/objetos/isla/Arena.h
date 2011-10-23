/*
 * Arena.h
 *
 *  Created on: 19/08/2011
 *      Author: amalia
 */

#ifndef ARENA_H_
#define ARENA_H_

#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/curva/CalculadoraBSpline.h"

#include "SuperficeBSlpineChata.h"

class Arena: public ObjetoDibujable {
public:
	Arena( PuntosControl *ptos, string nombreTextura, const int paso );
	virtual ~Arena();

private:
	SuperficeBSlpineChata* superficie;
	void displayList( const int paso ) const;
};

#endif /* ARENA_H_ */
