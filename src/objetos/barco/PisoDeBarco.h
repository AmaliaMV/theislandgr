/*
 * PisoDeBarco.h
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#ifndef PISODEBARCO_H_
#define PISODEBARCO_H_

#include "ConstantesBarco.h"
#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/Matematica.h"

class PisoDeBarco: public ObjetoDibujable {
public:

	PisoDeBarco( string nombreTextura );
	virtual ~PisoDeBarco();

private:

	void generarPtos ( float *ptos );
	void setIndice ( float indiceMax, unsigned int *vertIndice );
	void generarFigura ( float *ptos, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila);
	void displayList();

	static const unsigned int cantPasosTita;
};

#endif /* PISODEBARCO_H_ */
