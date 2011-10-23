/*
 * ECurvas.cpp
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#include "ECurvas.h"

ECurvas::ECurvas( string mensaje )
{
	this->mensaje = mensaje;
}
const char* ECurvas::what() const throw()
{
	return mensaje.c_str();
}
