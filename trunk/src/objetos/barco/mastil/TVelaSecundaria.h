/*
 * TVelaSecundaria.h
 *
 *  Created on: 01/01/2012
 *      Author: amalia
 */

#ifndef TVELASECUNDARIA_H_
#define TVELASECUNDARIA_H_

#include "../EstrategiaTransformacion.h"

class TVelaSecundaria: public EstrategiaTransformacion {
public:
	TVelaSecundaria( float centroVela, float altura, float desplazamientoHorizontal );
	void ejecutar();
	virtual ~TVelaSecundaria();
private:
	float DESPLAZAMIENTO;
	float CENTRO;
	float ALTURA;
};

#endif /* TVELASECUNDARIA_H_ */
