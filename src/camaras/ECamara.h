/*
 * ECamara.h
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#ifndef ECAMARA_H_
#define ECAMARA_H_

#include <exception>
#include <iostream>

using namespace std;

class ECamara: public exception {
public:
	ECamara( string expresion );
	virtual const char* what() const throw();
	virtual ~ECamara() throw();

private:
	string expresion;
};

#endif /* ECAMARA_H_ */
