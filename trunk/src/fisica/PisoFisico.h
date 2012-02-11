/*
 * PisoFisico.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef PISOFISICO_H_
#define PISOFISICO_H_

#include "CuerpoFisico.h"

class PisoFisico: public CuerpoFisico{
public:
	PisoFisico( btBoxShape* shape, float alturaDelPiso );
	void dibujar() const{}
	virtual ~PisoFisico();
};

#endif /* PISOFISICO_H_ */
