/*
 * ECurvas.h
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#ifndef ECURVAS_H_
#define ECURVAS_H_

#include <exception>
#include <string>
using namespace std;

class ECurvas: public exception {
public:
	ECurvas( string mensaje );
	const char* what() const throw();
	virtual ~ECurvas() throw() {};

private:
	string mensaje;
};

#endif /* ECURVAS_H_ */
