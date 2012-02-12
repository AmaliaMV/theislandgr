/*
 * ECamara.cpp
 *
 *  Created on: 11/01/2012
 *      Author: amalia
 */

#include "EComando.h"

EComando::EComando( string expresion ): exception()
{
	this->expresion = expresion;
}

EComando::~EComando() throw() {}

const char* EComando::what() const throw()
{
	return this->expresion.c_str();
}
