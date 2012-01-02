/*
 * TVelaPrincipal.h
 *
 *  Created on: 25/12/2011
 *      Author: amalia
 */

#ifndef TVELAPRINCIPAL_H_
#define TVELAPRINCIPAL_H_

#include "../EstrategiaTransformacion.h"
#include "../ConstantesBarco.h"

class TVelaPrincipal: public EstrategiaTransformacion{
public:
	TVelaPrincipal( float centroVela, float altura );
	void ejecutar();
	virtual ~TVelaPrincipal();

private:

	float CENTRO;
	float ALTURA;
};

#endif /* TVELAPRINCIPAL_H_ */
