/*
 * TMastilSecundario.h
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#ifndef TMASTILSECUNDARIO_H_
#define TMASTILSECUNDARIO_H_

#include "EstrategiaTransformacion.h"

class TMastilSecundario: public EstrategiaTransformacion {
public:
	TMastilSecundario( float desplazamiento );
	void ejecutar();
	virtual ~TMastilSecundario();

private:
	float DESPLAZAMIENTO;
};

#endif /* TMASTILSECUNDARIO_H_ */
