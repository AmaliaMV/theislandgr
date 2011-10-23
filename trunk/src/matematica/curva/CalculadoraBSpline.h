/*
 * CalculadoraBSpline.h
 *
 *  Created on: 09/08/2011
 *      Author: amalia
 */

#ifndef CALCULADORABSPLINE_H_
#define CALCULADORABSPLINE_H_

#include "BSplineCerrada.h"
#include "../Matematica.h"

/* la curva originalmente va de 0 a 1, pero al calcularla se hizo un desplazamiento
 * de las coordenadas x e y a 0.5 */
#define CENTRO 0.5
class CalculadoraBSpline {
public:
	static void f_bspline( float *ctrlPtos, float u, float &x, float &y);
	static void f_bsplineCentrada05( float *ctrlPtos, float u, float &x, float &y);
	static void f1_bspline( float *ctrlPtos, float u, float *x, float *y); //retorna la derivada en el pto u
	static int cantCurvas( PuntosControl *ptos);
	static void calcularCentro (PuntosControl *ctrlPtos, float &xc, float &yc, float &zc, int paso);
	static void calcularExtremos (PuntosControl *ctrlPtos, float &xmin, float &xmax, float &ymin, float &ymax, const int paso);
	static void calcularExtremosCentrada05 (PuntosControl *ctrlPtos, float &xmin, float &xmax, float &ymin, float &ymax, const int paso);

	virtual ~CalculadoraBSpline();

private:
	CalculadoraBSpline();

};

#endif /* CALCULADORABSPLINE_H_ */
