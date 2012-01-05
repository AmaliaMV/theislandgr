/*
 * BSpline.cpp
 *
 *  Created on: 25/05/2011
 *      Author: Amalia
 */

#include "BSplineCerrada.h"

BSplineCerrada::BSplineCerrada(PuntosControl *ctrlPtos)
{
	this->ctrlPtos = new PuntosControl( *ctrlPtos );
	this->cerrarCurva();
}

BSplineCerrada::~BSplineCerrada()
{
	delete this->ctrlPtos;
}

void BSplineCerrada::cerrarCurva()
{
	float *v;
	unsigned int ptoNumero;

	for ( ptoNumero = 0; ptoNumero < ORDEN_BSPLINE-1; ptoNumero++ )
	{
		v = ctrlPtos->getPto( ptoNumero );
		ctrlPtos->agregarPto( v );
		delete []v;
	}
}

PuntosControl* BSplineCerrada::getPuntosControl() const
{
	return this->ctrlPtos;
}

void BSplineCerrada::cargarPtosCrtl ( float v [][3], const int numCurva ) const
{
	/* cargo 4 ptos de control de tres coordenadas en un array
	 * para pasarselo a la calculadoraBSpline*/

	unsigned int j, k;

	for (j = 0; j < ORDEN_BSPLINE; j++)
		for (k = 0; k < CteObjeto::CANT_COORD_PTO ; k++)
			v[j][k] = this->ctrlPtos->getPtos()[j*CteObjeto::CANT_COORD_PTO
			                                    +numCurva*CteObjeto::CANT_COORD_PTO + k];
}

unsigned int BSplineCerrada::getCantCurvas () const
{
	return this->getPuntosControl()->getCantPtos() - ORDEN_BSPLINE + 1;
}
