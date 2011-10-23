/*
 * Cielo.h
 *
 *  Created on: 17/09/2011
 *      Author: amalia
 */

#ifndef CIELO_H_
#define CIELO_H_

#include "ObjetoDibujable.h"
#include "../grafica/textura/Textura24.h"
#include "../matematica/Matematica.h"

class Cielo: public ObjetoDibujable {
public:
	Cielo( string nombreTextura, float radio );
	virtual ~Cielo();

private:
	void displayList();

	void generarPtos ( float *ptos, float titaAvance, float fiAvance );
	void setIndice ( float indiceMax, unsigned int ptosPorFila, unsigned int *vertIndice );
	void generarFigura ( float *ptos, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila, unsigned int cantColum );

	float radio;
	float fiMax;
	float titaMax;
	float deltaFi;
	float deltaTita;
};

#endif /* CIELO_H_ */
