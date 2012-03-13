/*
 * Matematica.h
 *
 *  Created on: 21/04/2011
 *      Author: Amalia
 */

#ifndef MATEMATICA_H_
#define MATEMATICA_H_

#include <math.h>

class Matematica {

public:

	static const double PI;

	static double cosHex(double anguloHex);
	static double sinHex(double anguloHex);

	static double cosRad(double anguloRad);
	static double sinRad(double anguloRad);

	static unsigned int factorial( unsigned int n );

	static double modulo( double numero );
	static void normalizar3(float v[3]);

	static void productoVectorial(const float v[3], const float w[3], float resultado[3]);

	virtual ~Matematica();

private:
	Matematica();
};

#endif /* MATEMATICA_H_ */
