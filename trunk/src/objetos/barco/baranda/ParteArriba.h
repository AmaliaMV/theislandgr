/*
 * ParteArriba.h
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#ifndef PARTEARRIBA_H_
#define PARTEARRIBA_H_

#include "../../ODTextura.h"

#include "../ConstantesBarco.h"

class ParteArriba: public ODTextura {
public:
	ParteArriba(  Textura* tetura, float altura, float longitud, float titaMin, float titaMax, float distancia=0.0, int afuera=1);
	virtual ~ParteArriba();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void generarNormales();

private:

	float ALTURA;
	float LONGITUD;
	float DISTANCIA;
	int AFUERA;

	float TITA_MIN;
	float TITA_MAX;

	static const unsigned int CANT_PTOS_LONG = 30;
};

#endif /* PARTEARRIBA_H_ */
