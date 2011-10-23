/*
 * Barco.h
 *
 *  Created on: 25/09/2011
 *      Author: amalia
 */

#ifndef BARCO_H_
#define BARCO_H_

#include "ObjetoDibujable.h"
#include "../grafica/textura/Textura24.h"
#include "../matematica/Matematica.h"
#include "barco/CascoDeBarco.h"
#include "barco/PisoDeBarco.h"
#include "barco/Baranda.h"

class Barco: public ObjetoDibujable {
public:
	Barco();
	void dibujar();
	virtual ~Barco();

private:

	void generarPtos ( float *ptos );
	void setIndice ( float indiceMax, unsigned int ptosPorFila, unsigned int *vertIndice );
	void generarFigura ( float *ptos, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila, unsigned int cantColum );
	void displayList();

	CascoDeBarco *casco;
	PisoDeBarco *piso;
	Baranda *baranda;




};

#endif /* BARCO_H_ */
