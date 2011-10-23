/*
 * EArchivoInexistente.cpp
 *
 *  Created on: 09/09/2011
 *      Author: amalia
 */

#include "EArchivoInexistente.h"

EArchivoInexistente::EArchivoInexistente( string nombreArchivo )
{
	this->nombreArchivo = nombreArchivo;
}

EArchivoInexistente::~EArchivoInexistente() throw() { }

const char* EArchivoInexistente::what() const throw()
{
	string mensaje;

	mensaje = "No existe el archivo " + this->nombreArchivo;

	return mensaje.c_str();
}
