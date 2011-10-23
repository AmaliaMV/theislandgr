/*
 * BSplineCerradaDibujable.h
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#ifndef BSPLINECERRADADIBUJABLE_H_
#define BSPLINECERRADADIBUJABLE_H_

#include "BSplineCerrada.h"
#include <GL/glu.h>

class BSplineCerradaDibujable: public BSplineCerrada {
public:
	BSplineCerradaDibujable( PuntosControl *ptos );
	void dibujarCurvaBSplinePanel() const;
	virtual ~BSplineCerradaDibujable();

private:

	void dibujarPtosCtrl() const;
	void dibujarCurva() const;
	/*
	 * genera los nudos de la BSpline teniendo en cuenta que es una
	 * Bspline uniforme
	 */
	void generarNudos( GLfloat* &nudos ) const;
	void testNoErrorAlCrearCurva( GLUnurbsObj *curva ) const;
};

#endif /* BSPLINECERRADADIBUJABLE_H_ */
