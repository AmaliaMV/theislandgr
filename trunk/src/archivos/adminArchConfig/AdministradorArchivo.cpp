/*
 * AdministradorArchivo.cpp
 *
 *  Created on: 02/08/2011
 *      Author: amalia
 */

#include "AdministradorArchivo.h"

AdministradorArchivo::AdministradorArchivo( const string nomArchAdmin )
{
	this->abrirArchivo( nomArchAdmin );
	this->cargarLosArchivos();
	this->cerrarArchivo();
}

string AdministradorArchivo::getNombreArchivo ( const string clave ) const
{
	map<string, string>::iterator iterador = mapaDeArchivos->find( clave );

	if ( iterador != mapaDeArchivos->end() )
		return iterador->second;

	string mensaje = "correspondiente a la clave: '" + clave + "' en el archivo de configuracion.";

	throw new EArchivoInexistente ( mensaje );
}

AdministradorArchivo::~AdministradorArchivo()
{
	delete mapaDeArchivos;
}

void AdministradorArchivo::cargarLosArchivos()
{
	mapaDeArchivos = new map<string, string>;
	Claves claves;
	string clave, igualdad, valor;

	while ( !llegoAlfinalDelArchivo() )
	{
		archivo >> clave;
		archivo >> igualdad;
		archivo >> valor;
		if ( (igualdad.compare("=") == 0) && claves.existeLaClave( clave ) )
			mapaDeArchivos->insert( componente (clave, valor) );
	}
}

void AdministradorArchivo::abrirArchivo( string nomArchAdmin)
{
	archivo.open( nomArchAdmin.c_str() );
	this->testExisteArchivo( nomArchAdmin );
}

void AdministradorArchivo::testExisteArchivo ( string nombreArchivo )
{
	if ( !archivo.good() )
		throw new EArchivoInexistente( nombreArchivo );
}

void AdministradorArchivo::cerrarArchivo ()
{
	archivo.close();
}

bool AdministradorArchivo::llegoAlfinalDelArchivo()
{
	return archivo.eof();
}
