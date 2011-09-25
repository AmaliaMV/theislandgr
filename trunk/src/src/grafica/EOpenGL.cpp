/*
 * EOpenGL.cpp
 *
 *  Created on: 10/09/2011
 *      Author: amalia
 */

#include "EOpenGL.h"

EOpenGL::EOpenGL( string mensaje)
{
	this->mensaje = mensaje;
}

const char* EOpenGL::what() const throw()
{
	return mensaje.c_str();
}

EOpenGL::~EOpenGL() throw() {
	// TODO Auto-generated destructor stub
}
