/*
 * Superfice.h
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#ifndef SUPERFICEBSPLINECHATA_H_
#define SUPERFICEBSPLINECHATA_H_

#include "../../matematica/curva/CalculadoraBSpline.h"
#include "../../ConstantesObjeto.h"
#include "ConstantesIsla.h"

class SuperficeBSlpineChata {

public:
	SuperficeBSlpineChata(  PuntosControl *ptos );
	float* generarPtos ( const unsigned int paso );
	unsigned int* generarIndice ();
	float* generarCoordText ( const unsigned int paso );
	unsigned int getCantPtos();

	virtual ~SuperficeBSlpineChata();

private:

	BSplineCerrada *curva;

};

#endif /* SUPERFICE_H_ */
