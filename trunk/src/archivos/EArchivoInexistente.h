/*
 * EArchivoInexistente.h
 *
 *  Created on: 09/09/2011
 *      Author: amalia
 */

#ifndef EARCHIVOINEXISTENTE_H_
#define EARCHIVOINEXISTENTE_H_

#include <exception>
#include <iostream>

using namespace std;

class EArchivoInexistente: public exception{
public:
	EArchivoInexistente( string nombreArchivo );
	virtual const char* what() const throw();
	virtual ~EArchivoInexistente() throw();

private:
	string nombreArchivo;
};

#endif /* EARCHIVOINEXISTENTE_H_ */
