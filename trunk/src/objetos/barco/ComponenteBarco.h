/*
 * ComponenteBarco.h
 *
 *  Created on: 23/12/2011
 *      Author: amalia
 */

#ifndef COMPONENTEBARCO_H_
#define COMPONENTEBARCO_H_

#include "EstrategiaTransformacion.h"
#include "../../grafica/FuncOpenGL.h"

class ComponenteBarco {
public:
	ComponenteBarco( EstrategiaTransformacion *transformacion );
	virtual void dibujarComponente();
	virtual ~ComponenteBarco();

protected:
	virtual void dibujar() = 0;

private:
	EstrategiaTransformacion *transformacion;
};

#endif /* COMPONENTEBARCO_H_ */
