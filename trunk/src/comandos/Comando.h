/*
 * Comando.h
 *
 *  Created on: 11/02/2012
 *      Author: amalia
 */

#ifndef COMANDO_H_
#define COMANDO_H_

#include <iostream>
using namespace std;

class Comando {
public:
	Comando();
	virtual void ejecutar() = 0;
	virtual const string getDescripcion() const = 0;
	virtual ~Comando();
};

#endif /* COMANDO_H_ */
