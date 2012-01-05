/*
 * Cielo.h
 *
 *  Created on: 17/09/2011
 *      Author: amalia
 */

#ifndef CIELO_H_
#define CIELO_H_

#include "ODTextura.h"

#include "../grafica/textura/Textura24.h"
#include "../matematica/Matematica.h"

class Cielo: public ODTextura {
public:
	Cielo( string nombreTextura, float radio );
	virtual ~Cielo();

protected:
	virtual void generarCoordPtos();
	virtual void generarIndice();
	virtual void generarCoodText();

private:
	void displayList();

	void generarPtos ( float *ptos, float titaAvance, float fiAvance );
	void setIndice ( float indiceMax, unsigned int ptosPorFila, unsigned int *vertIndice );
	void generarFigura ( float *ptos, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila, unsigned int cantColum );

	unsigned int cantPtosX;
	unsigned int cantPtosY;

	float RADIO;

	static const float FI_MAX;
	static const float TITA_MAX;
	static const float DELTA_FI;
	static const float DELTA_TITA;
};

#endif /* CIELO_H_ */
