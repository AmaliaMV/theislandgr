/*
 * TMirador.h
 *
 *  Created on: 24/12/2011
 *      Author: amalia
 */

#ifndef TMIRADOR_H_
#define TMIRADOR_H_

#include "../EstrategiaTransformacion.h"

class TMirador: public EstrategiaTransformacion{
public:
	TMirador();
	virtual void ejecutar();
	virtual ~TMirador();
};

#endif /* TMIRADOR_H_ */
