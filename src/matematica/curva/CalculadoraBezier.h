/*
 * CalculadoraBeizer.h
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#ifndef CALCULADORABEZIER_H_
#define CALCULADORABEZIER_H_

#include "PuntosControl.h"

class CalculadoraBezier {

public:
	CalculadoraBezier(unsigned int grado);
	void f_bezier(float *ctrlPtos, float u, float &x, float &y);
	void f_bezierCentrada05(float *ctrlPtos, float u, float &x, float &y);
	void f1_bezier( float *ctrlPtos, float u, float &x, float &y);
	unsigned int cantCurvas (PuntosControl *ctrlPtos);
	~CalculadoraBezier();

private:
	float b_bezier( float u, unsigned int i );
	float b1_bezier( float u, float i );

	unsigned int GRADO;
	static const float CENTRO;
};

#endif /* CALCULADORABEZIER_H_ */
