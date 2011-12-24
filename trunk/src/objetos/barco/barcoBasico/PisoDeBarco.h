/*
 * PisoDeBarco.h
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#ifndef PISODEBARCO_H_
#define PISODEBARCO_H_

#include "../ConstantesBarco.h"

#include "../../ODTextura.h"

#include "../../../grafica/textura/Textura24.h"
#include "../../../matematica/Matematica.h"

class PisoDeBarco: public ODTextura {
public:

	PisoDeBarco( string nombreTextura );
	virtual ~PisoDeBarco();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

private:
	static const unsigned int cantPasosTita;
};

#endif /* PISODEBARCO_H_ */
