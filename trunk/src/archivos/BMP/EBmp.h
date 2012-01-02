/*
 * EBmp.h
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#ifndef EBMP_H_
#define EBMP_H_

#include <exception>
#include <iostream>

using namespace std;

class EBmp: public exception {
public:
	EBmp( string mensaje );
	virtual const char* what() const throw();
	virtual ~EBmp() throw();

private:
	string mensaje;
};

#endif /* EBMP_H_ */
