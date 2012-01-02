/*
 * TMirador.h
 *
 *  Created on: 24/12/2011
 *      Author: amalia
 */

#ifndef TMIRADOR_H_
#define TMIRADOR_H_

#include "../EstrategiaTransformacion.h"
#include "../ConstantesBarco.h"

class TMirador: public EstrategiaTransformacion{
public:
	TMirador( float altura );
	virtual void ejecutar();
	virtual ~TMirador();
private:
	float ALTURA;
};

#endif /* TMIRADOR_H_ */
