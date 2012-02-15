/*
 * Palmera.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef PALMERA_H_
#define PALMERA_H_

#include "geometricos/RectanguloConTextura32.h"

class Palmera: public ObjetoDibujable {
public:
	Palmera( string nombreTextura );
	virtual ~Palmera();

protected:
	virtual void displayList() const;

private:
	RectanguloConTextura32* imagenPalmera;
	static const float ALTURA_PALMERA;
};

#endif /* PALMERA_H_ */
