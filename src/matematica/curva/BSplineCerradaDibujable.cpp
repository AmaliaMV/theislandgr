/*
 * BSplineCerradaDibujable.cpp
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#include "BSplineCerradaDibujable.h"

BSplineCerradaDibujable::BSplineCerradaDibujable( PuntosControl *ptos ): BSplineCerrada(ptos)
{
}

BSplineCerradaDibujable::~BSplineCerradaDibujable()
{
}

void BSplineCerradaDibujable::dibujarCurvaBSplinePanel() const
{
	glDisable(GL_LIGHTING);

	this->dibujarPtosCtrl();
	this->dibujarCurva();

	glEnable(GL_LIGHTING);
}

void BSplineCerradaDibujable::dibujarCurva() const
{
	GLfloat *nudos;
	GLUnurbsObj *curva;

	glColor3f (0.14, 0.47, 0.03);
	glLineWidth (3.0);

	this->generarNudos( nudos );

	curva = gluNewNurbsRenderer ();
	testNoErrorAlCrearCurva( curva );

	gluBeginCurve(curva);
		gluNurbsCurve (curva, this->getPuntosControl()->getCantPtos() + ORDEN_BSPLINE, nudos,
				CteObjeto::CANT_COORD_PTO, this->getPuntosControl()->getPtos(), ORDEN_BSPLINE,
				GL_MAP1_VERTEX_3);
	gluEndCurve(curva);

	gluDeleteNurbsRenderer(curva);

	glLineWidth (1.0);
}

void BSplineCerradaDibujable::dibujarPtosCtrl() const
{
	float *v;
	unsigned int i;

	glPointSize(5.0);
	glColor3f (1.0, 0.0, 0.0);

	glBegin(GL_POINTS);

		for (i = 0; i < this->getPuntosControl()->getCantPtos(); i++)
		{
			v = this->getPuntosControl()->getPto(i);
			glVertex3fv( v );
			delete v;
		}

	glEnd();

	glPointSize(1.0);
}

void BSplineCerradaDibujable::generarNudos( GLfloat* &nudos ) const
{
	const unsigned int cantPtoCtrl = this->getPuntosControl()->getCantPtos();
	unsigned int i;

	nudos = new GLfloat[cantPtoCtrl + ORDEN_BSPLINE];

	for ( i = 0; i < cantPtoCtrl + ORDEN_BSPLINE; i++)
		nudos[i] = (float)i;
}

void BSplineCerradaDibujable::testNoErrorAlCrearCurva( GLUnurbsObj *curva ) const
{
	if (curva == 0)
		throw new ECurvas ("No se pudo generar la curva BSpline");
}
