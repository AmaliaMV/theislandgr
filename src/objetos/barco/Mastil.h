/*
 * Mastil.h
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#ifndef MASTIL_H_
#define MASTIL_H_

#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/Matematica.h"

class Mastil: public ObjetoDibujable {
public:
	Mastil( string nombreTextura );
	virtual ~Mastil();

private:
	void generarPtos ( float *ptos );
	void setIndice ( float indiceMax, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila );
	void displayList();

};

#endif /* MASTIL_H_ */
