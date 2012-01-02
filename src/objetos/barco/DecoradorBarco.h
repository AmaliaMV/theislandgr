/*
 * DecoradorBarco.h
 *
 *  Created on: 24/12/2011
 *      Author: amalia
 */

#ifndef DECORADORBARCO_H_
#define DECORADORBARCO_H_

/* No borra el objeto a Decorar!!!*/

#include "ComponenteBarco.h"

class DecoradorBarco: public ComponenteBarco {
public:
	DecoradorBarco( EstrategiaTransformacion *transformacion, ComponenteBarco *aDecorar );
	void dibujarComponente();
	virtual ~DecoradorBarco() =0;

private:
	ComponenteBarco * componente;
};

#endif /* DECORADORBARCO_H_ */
