/*
 * BordeBSpline.h
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#ifndef BORDEBSPLINE_H_
#define BORDEBSPLINE_H_

#include "../../matematica/curva/CalculadoraBSpline.h"
#include "../../ConstantesObjeto.h"
#include "ConstantesIsla.h"

class BordeBSpline {
public:
	BordeBSpline( PuntosControl *ptos, const unsigned int cantNivelesHorizontal, const float escaladoXY,
			const float escaladoZ, const float pendiente, const float alturaEntreNiveles );
	float* generarPtos() const;
	unsigned int* generarIndice () const;
	float* generarCoorText () const;
	unsigned int getCantPtos() const;
	unsigned int getCantReferencias() const;
	float getAltura() const;
	virtual ~BordeBSpline();

private:

	BSplineCerrada *curva;
	unsigned int ptosHorizontales;
	unsigned int ptosVerticales;
	float ESCALADOxy;
	float ESCALADOz;
	float PENDIENTE;
	float ALTURA_ENTRE_NIVELES;

};

#endif /* BORDEBSPLINE_H_ */
