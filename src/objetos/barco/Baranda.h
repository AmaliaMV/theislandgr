/*
 * Baranda.h
 *
 *  Created on: 22/10/2011
 *      Author: amalia
 */

#ifndef BARANDA_H_
#define BARANDA_H_

#include "ConstantesBarco.h"
#include "barcoBasico/PaloDeBaranda.h"
#include "../ObjetoDibujable.h"
#include "../../grafica/textura/Textura24.h"
#include "../../matematica/Matematica.h"

class Baranda {
public:
	Baranda();
	void dibujar();
	virtual ~Baranda();

private:

	void displayList();


	PaloDeBaranda *palito;

	static const unsigned int cantPalitos;

};

#endif /* BARANDA_H_ */
