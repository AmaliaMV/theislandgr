/*
 * ECamara.h
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#ifndef ECOMANDO_H_
#define ECOMANDO_H_

#include <exception>
#include <iostream>

using namespace std;

class EComando: public exception {
public:
	EComando( string expresion );
	virtual const char* what() const throw();
	virtual ~EComando() throw();

private:
	string expresion;
};

#endif /* ECOMANDO_H_ */
