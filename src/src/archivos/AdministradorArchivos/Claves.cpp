/*
 * Claves.cpp
 *
 *  Created on: 23/09/2011
 *      Author: amalia
 */

#include "Claves.h"

Claves::Claves()
{
	claves = new list<string>;
	cargarClaves();
}

bool Claves::existeLaClave(const string clave) const
{
	list<string>::iterator iterador = claves->begin();

	while ( iterador != claves->end() )
	{
		if ( clave.compare( (*iterador) ) == 0)
			return true;
		iterador++;
	}
	return false;
}

Claves::~Claves()
{
	delete claves;
}

void Claves::agregarClave(const string clave)
{
	claves->push_front( clave );
}
void Claves::cargarClaves ()
{
	for ( unsigned int numClave = 0 ; numClave < CANT_CLAVES ; numClave++ )
		agregarClave( CLAVE_VALIDAS [numClave] );
}


