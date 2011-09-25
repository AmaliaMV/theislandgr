/*
 * EOpenGL.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef EOPENGL_H_
#define EOPENGL_H_

#include <exception>
#include <iostream>
using namespace std;

class EOpenGL: public exception {
public:
	EOpenGL( string mensaje );
	virtual const char* what() const throw();
	virtual ~EOpenGL() throw();

private:
	string mensaje;
};

#endif /* EOPENGL_H_ */
