/*
 * TBaupres.h
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#ifndef TBAUPRES_H_
#define TBAUPRES_H_

#include "../EstrategiaTransformacion.h"
#include "../ConstantesBarco.h"
class TBaupres: public EstrategiaTransformacion {
public:
	TBaupres();
	void ejecutar();
	virtual ~TBaupres();
};

#endif /* TBAUPRES_H_ */
