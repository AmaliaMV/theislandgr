/*
 * PaloDeBaranda.h
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#ifndef PALODEBARANDA_H_
#define PALODEBARANDA_H_

#include "ConstantesBarco.h"
#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/Matematica.h"

class PaloDeBaranda: public ObjetoDibujable {
public:
	PaloDeBaranda( string nombreTextura);
	float getLado();
	virtual ~PaloDeBaranda();

private:

	void generarPtos ( float *ptos );
	void setIndice ( float indiceMax, unsigned int *vertIndice );
	void generarCoordText ( float *coordText, unsigned int cantFila );
	void displayList();

	static const float alto;
	static const float lado;
};

#endif /* PALODEBARANDA_H_ */
