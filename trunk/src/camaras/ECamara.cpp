/*
 * ECamara.cpp
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#include "ECamara.h"

ECamara::ECamara( string expresion ): exception()
{
	this->expresion = expresion;
}

ECamara::~ECamara() throw() {}

const char* ECamara::what() const throw()
{
	return this->expresion.c_str();
}
