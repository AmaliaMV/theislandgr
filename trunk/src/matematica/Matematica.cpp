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

void Matematica::normalizar3(float v[3])
{
	float modulo = sqrt( pow(v[0],2) + pow(v[1],2) + pow(v[2],2) );

	if ( modulo == 0 ) return;

	for (unsigned int i = 0; i < 3; i++ )
		v[i] = v[i] / modulo;
}

void Matematica::productoVectorial(const float v[3], const float w[3], float resultado[3])
{
	resultado[0] = v[1] * w[2] - v[2] * w[1];
	resultado[1] = v[2] * w[0] - v[0] * w[2] ;
	resultado[2] = v[0] * w[1] - v[1] * w[0];
}
