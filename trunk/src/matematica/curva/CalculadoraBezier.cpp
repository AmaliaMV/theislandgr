/*
 * CalculadoraBeizer.cpp
 *
 *  Created on: 02/01/2012
 *      Author: amalia
 */

#include "CalculadoraBezier.h"

const float CalculadoraBezier::CENTRO = 0.5;

CalculadoraBezier::CalculadoraBezier(unsigned int grado)
{
	GRADO = grado;
}
CalculadoraBezier::~CalculadoraBezier() {}

void CalculadoraBezier::f_bezier(float *ctrlPtos, float u, float &x, float &y)
{
	float valorX =0, valorY=0;
	float base;

	for (unsigned int i = 0; i < GRADO+1; i++) // una bezier tiene un pto de control mas q el grado de la bezier
	{
		base = b_bezier(u, i);
		valorX += base * ctrlPtos[i*3];
		valorY += base * ctrlPtos[i*3+1];
	}

	x = valorX;
	y = valorY;
}

void CalculadoraBezier::f_bezierCentrada05(float *ctrlPtos, float u, float &x, float &y)
{
	f_bezier(ctrlPtos, u, x, y);

	x -= CENTRO;
	y -= CENTRO;
}

void CalculadoraBezier::f1_bezier( float *ctrlPtos, float u, float &x, float &y)
{
	float valorX =0, valorY=0;
	float base;

	if ( u == 0 or u == 1 )
	{
		x = 0;
		y = 0;
	}

	for (unsigned int i = 0; i < GRADO+1; i++)
	{
		base = b1_bezier(u, i);
		valorX += base * ctrlPtos[i*3];
		valorY += base * ctrlPtos[i*3+1];
	}

	x = valorX;
	y = valorY;
}

float CalculadoraBezier::b_bezier(float u, unsigned int i)
{
	float base, comb;

	comb = Matematica::factorial(GRADO) / Matematica::factorial(GRADO-i) / Matematica::factorial(i);
	base = (float) (comb * pow(u, i) * pow(1 - u, GRADO-i));

	return base;
}

float CalculadoraBezier::b1_bezier(float u, float i)
{
	float base, comb;

	comb = Matematica::factorial(GRADO) / Matematica::factorial(GRADO-i) / Matematica::factorial(i);
	base = (float) (comb * (i * pow(u, i-1) * pow(1 - u, GRADO-i) - pow(u, i) * (GRADO-i) * pow(1 - u, GRADO-i-1)));

	return base;
}

unsigned int CalculadoraBezier::cantCurvas (PuntosControl *ctrlPtos)
{
	if (ctrlPtos->getCantPtos() <= GRADO+1)
		return ctrlPtos->getCantPtos()/(GRADO+1);
	else
		return (ctrlPtos->getCantPtos()-1)/GRADO;
}
