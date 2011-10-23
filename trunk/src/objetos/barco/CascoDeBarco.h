/*
 * CascoDeBarco.h
 *
 *  Created on: 21/10/2011
 *      Author: amalia
 */

#ifndef CASCODEBARCO_H_
#define CASCODEBARCO_H_

#include "ConstantesBarco.h"
#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/Matematica.h"

class CascoDeBarco: public ObjetoDibujable
{
public:

	CascoDeBarco( string nombreTextura );
	virtual ~CascoDeBarco();

private:

	void generarPtos ( float *ptos );
	void setIndice ( float indiceMax, unsigned int ptosPorFila, unsigned int *vertIndice );
	void generarFigura ( float *ptos, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila, unsigned int cantColum );
	void displayList();

	static const int cantPasosFi;
	static const int cantPasosTita;
};

#endif /* CASCODEBARCO_H_ */
