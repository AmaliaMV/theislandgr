/*
 * Palmera.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef PALMERA_H_
#define PALMERA_H_

#include "ObjetoDibujable.h"
#include "../grafica/textura/Textura32.h"

class Palmera: public ObjetoDibujable {
public:
	Palmera( string nombreTextura );
	void dibujar();
	virtual ~Palmera();

private:
	void displayList();
};

#endif /* PALMERA_H_ */
