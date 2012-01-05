/*
 * Palmera.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef PALMERA_H_
#define PALMERA_H_

#include "ODTextura.h"

#include "../grafica/textura/Textura32.h"

class Palmera: public ODTextura {
public:
	Palmera( string nombreTextura );
	virtual ~Palmera();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();

	void displayList();

private:

	unsigned int TAM_INDICE;
	unsigned int TAM_PTOS;
};

#endif /* PALMERA_H_ */
