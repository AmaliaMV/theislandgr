/*
 * ParteArriba.h
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#ifndef PARTEARRIBA_H_
#define PARTEARRIBA_H_

#include "../../ODTextura.h"
#include "../../../grafica/textura/Textura24.h"

#include "../ConstantesBarco.h"

class ParteArriba: public ODTextura {
public:
	ParteArriba(  string nombreTextura, float altura, float longitud, float titaMin, float titaMax );
	virtual ~ParteArriba();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void generarNormales();

private:

	float ALTURA;
	float LONGITUD;

	float TITA_MIN;
	float TITA_MAX;

	static const unsigned int CANT_PTOS_LONG = 30;
};

#endif /* PARTEARRIBA_H_ */
