/*
 * Vela.h
 *
 *  Created on: 22/12/2011
 *      Author: amalia
 */

#ifndef TELAVELA_H_
#define TELAVELA_H_

#include "../../ODTextura.h"

#include "../../../grafica/textura/Textura24.h"
#include "../../../matematica/Matematica.h"

class TelaVela: public ODTextura {
public:
	TelaVela( string nombreTextura, float largo, float alto, float factCurvatura );
	virtual ~TelaVela();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

private:
	float LARGO;
	float ALTO;
	float FACTOR_CURVATURA;
	static const unsigned int CANT_PTOS_LARGO;
	static const unsigned int CANT_PTOS_ALTO;

};

#endif /* VELA_H_ */
