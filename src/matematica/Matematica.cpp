/*
 * Matematica.cpp
 *
 *  Created on: 21/04/2011
 *      Author: Amalia
 */

#include "Matematica.h"

const double Matematica::PI = 3.14159;

Matematica::Matematica() { }

Matematica::~Matematica() { }

double Matematica::cosHex(double anguloHex)
{
	return cos (anguloHex * PI / 180);
}
double Matematica::sinHex(double anguloHex)
{
	return sin (anguloHex * PI / 180);
}

double Matematica::cosRad(double anguloRad)
{
	return cos (anguloRad);
}
double Matematica::sinRad(double anguloRad)
{
	return sin (anguloRad);
}

unsigned int Matematica::factorial(unsigned int n)
{
	int fact = 1;

	for (unsigned int i = 1; i <= n; i++)
		fact = fact * i;

	return fact;
}

double Matematica::modulo( double numero )
{
	if ( numero < 0 )
		return -numero;

	return numero;
}
