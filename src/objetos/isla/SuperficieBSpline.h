/*
 * Arena.h
 *
 *  Created on: 19/08/2011
 *      Author: amalia
 */

#ifndef SUPERFICEBSPLINE_H_
#define SUPERFICEBSPLINE_H_

#include "ConstantesIsla.h"

#include "../ODTextura.h"

#include "../../grafica/textura/Textura24.h"
#include "../../matematica/curva/CalculadoraBSpline.h"

class SuperficieBSpline: public ODTextura {
public:
	SuperficieBSpline( PuntosControl *ptos, string nombreTextura, const int paso );
	virtual ~SuperficieBSpline();

protected:
	void generarCoordPtos();
	void generarIndice();
	void generarCoodText();
	void displayList() const;

private:

	unsigned int getCantPtos() const;

	unsigned int PASO;
	BSplineCerrada *curva;

};

#endif /* ARENA_H_ */
