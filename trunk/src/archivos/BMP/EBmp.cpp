/*
 * EBmp.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "EBmp.h"

EBmp::EBmp( string mensaje )
{
	this->mensaje = mensaje;
}

EBmp::~EBmp() throw() { }

const char* EBmp::what() const throw()
{
	return mensaje.c_str();
}
