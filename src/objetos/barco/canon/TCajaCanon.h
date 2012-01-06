/*
 * TCajaCanon.h
 *
 *  Created on: 06/01/2012
 *      Author: amalia
 */

#ifndef TCAJACANON_H_
#define TCAJACANON_H_

#include "../EstrategiaTransformacion.h"
#include "../ConstantesBarco.h"

class TCajaCanon: public EstrategiaTransformacion {
public:
	TCajaCanon(float alturaCaja, float largoCaja);
	void ejecutar();
	virtual ~TCajaCanon();

private:
	float ALTO;
	float LARGO;
};

#endif /* TCAJACANON_H_ */
