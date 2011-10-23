/*
 * BSpline.h
 *
 *  Created on: 25/05/2011
 *      Author: Amalia
 */

#ifndef BSPLINE_H_
#define BSPLINE_H_

#define ORDEN_BSPLINE 4 //(grado)+1

#include "PuntosControl.h"
#include <stdlib.h>

class BSplineCerrada {
public:

	/*
	 * a partir de los ptos de control pasados, se obtienen los
	 * ptos de control de una BSplineCerrada
	 */
	BSplineCerrada(PuntosControl *ctrlPtos);

	/* carga ORDEN_BSPLINE ptos de control de 3 coordenadas en un vector
	 * v 		es el vector con los ptos de control correspondientes a la curva
	 * 			numCurva
	 * numCurva es el numero de la curva de la cual hay q obtener su ptos de control
	*/
	void cargarPtosCrtl ( float v [][3], const int numCurva ) const;

	/*
	 * retorna la cantidad de curvas BSpline de orden 4 esta conformado la curva
	 */
	unsigned int getCantCurvas () const;
	PuntosControl* getPuntosControl() const;
	virtual ~BSplineCerrada();

private:

	PuntosControl *ctrlPtos;
	/*
	 * Dado los puntos de control, cierra la curva bspline
	 * de orden ORDEN_BSPLINE
	 */
	void cerrarCurva();
};

#endif /* BSPLINE_H_ */
