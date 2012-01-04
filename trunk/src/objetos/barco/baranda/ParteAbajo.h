/*
 * ParteAbajo.h
 *
 *  Created on: 04/01/2012
 *      Author: amalia
 */

#ifndef PARTEABAJO_H_
#define PARTEABAJO_H_

#include "../../ODTextura.h"
#include "../../../grafica/textura/Textura24.h"

#include "../ConstantesBarco.h"

class ParteAbajo: public ODTextura {
public:
	ParteAbajo( string nombreTextura, float altura, float longitud, float titaMin, float titaMax );
	virtual ~ParteAbajo();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

private:

	float ALTURA;
	float LONGITUD;

	float TITA_MIN;
	float TITA_MAX;

	static const unsigned int CANT_PTOS_LONG = 30;
};

#endif /* PARTEABAJO_H_ */
